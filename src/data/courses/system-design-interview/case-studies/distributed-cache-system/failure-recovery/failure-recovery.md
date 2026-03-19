## Why Failure Handling is Critical

At scale, failures are not exceptions—they're the norm:

- **Hardware failures**: Servers crash, disks fail, memory corrupts
- **Network issues**: Partitions, packet loss, high latency
- **Software bugs**: Memory leaks, deadlocks, infinite loops
- **Operational errors**: Misconfigurations, accidental deletions
- **Capacity issues**: Traffic spikes, memory exhaustion

A robust distributed cache must handle all these scenarios gracefully.

## Common Failure Scenarios

### 1. Single Node Failure

**Scenario**: Primary node crashes due to hardware failure

**Impact**:
- All keys on that shard become unavailable for writes
- Reads can still be served from replicas
- ~1/N of total cache capacity lost

**Detection**:
```python
class NodeHealthChecker:
    def __init__(self, nodes, check_interval=1.0, failure_threshold=5.0):
        self.nodes = nodes
        self.check_interval = check_interval
        self.failure_threshold = failure_threshold
        self.node_status = {}
        self.last_successful_ping = {}
    
    def start_health_checks(self):
        def health_check_worker():
            while True:
                self.check_all_nodes()
                time.sleep(self.check_interval)
        
        thread = threading.Thread(target=health_check_worker, daemon=True)
        thread.start()
    
    def check_all_nodes(self):
        for node in self.nodes:
            try:
                # Send ping with timeout
                response = node.ping(timeout=0.5)
                self.handle_successful_ping(node, response)
            except (TimeoutError, ConnectionError) as e:
                self.handle_failed_ping(node, e)
    
    def handle_successful_ping(self, node, response):
        self.last_successful_ping[node.id] = time.time()
        if self.node_status.get(node.id) == 'FAILED':
            self.handle_node_recovery(node)
        self.node_status[node.id] = 'HEALTHY'
    
    def handle_failed_ping(self, node, error):
        last_success = self.last_successful_ping.get(node.id, 0)
        time_since_success = time.time() - last_success
        
        if time_since_success > self.failure_threshold:
            if self.node_status.get(node.id) != 'FAILED':
                self.handle_node_failure(node)
            self.node_status[node.id] = 'FAILED'
```

**Recovery**:
```python
class FailoverManager:
    def handle_node_failure(self, failed_node):
        if failed_node.role == 'PRIMARY':
            self.handle_primary_failure(failed_node)
        else:
            self.handle_replica_failure(failed_node)
    
    def handle_primary_failure(self, failed_primary):
        # 1. Find best replica to promote
        best_replica = self.select_best_replica(failed_primary)
        
        # 2. Promote replica to primary
        self.promote_replica_to_primary(best_replica)
        
        # 3. Update cluster topology
        self.update_cluster_topology(failed_primary, best_replica)
        
        # 4. Redirect traffic
        self.redirect_traffic(failed_primary.shard_id, best_replica)
        
        # 5. Start replacement replica
        self.start_replacement_replica(best_replica)
    
    def select_best_replica(self, failed_primary):
        replicas = self.get_replicas(failed_primary)
        
        # Choose replica with:
        # 1. Highest replication offset (least data loss)
        # 2. Lowest network latency to clients
        # 3. Sufficient resources
        
        best_replica = max(replicas, key=lambda r: (
            r.replication_offset,
            -r.average_latency,
            r.available_memory
        ))
        
        return best_replica
    
    def promote_replica_to_primary(self, replica):
        # Stop replication
        replica.stop_replication()
        
        # Enable write operations
        replica.enable_writes()
        
        # Start accepting replication connections
        replica.start_replication_server()
        
        # Update role
        replica.role = 'PRIMARY'
```

### 2. Network Partition

**Scenario**: Network split isolates some nodes from the cluster

**Impact**:
- Cluster splits into multiple partitions
- Risk of split-brain (multiple primaries)
- Some clients can't reach their assigned shards

**Detection and Handling**:
```python
class PartitionHandler:
    def __init__(self, cluster_size):
        self.cluster_size = cluster_size
        self.quorum_size = cluster_size // 2 + 1
    
    def handle_partition_detection(self, reachable_nodes):
        if len(reachable_nodes) >= self.quorum_size:
            # This partition has quorum - can continue operating
            self.maintain_service(reachable_nodes)
        else:
            # This partition lacks quorum - enter read-only mode
            self.enter_readonly_mode()
    
    def maintain_service(self, nodes):
        # Continue accepting reads and writes
        # Mark unreachable nodes as failed
        for node in nodes:
            if node.role == 'PRIMARY':
                node.can_accept_writes = True
    
    def enter_readonly_mode(self):
        # Stop accepting writes to prevent split-brain
        # Continue serving reads from available replicas
        for node in self.local_nodes:
            if node.role == 'PRIMARY':
                node.can_accept_writes = False
                node.reject_writes_reason = "PARTITION_NO_QUORUM"
```

### 3. Cascading Failures

**Scenario**: One node failure triggers failures in other nodes

**Example Flow**:
1. Primary node fails
2. Traffic redirects to replicas
3. Replicas become overloaded
4. Replicas start failing
5. Remaining nodes get even more traffic
6. Entire cluster fails

**Prevention**:
```python
class CascadePreventionManager:
    def __init__(self):
        self.circuit_breakers = {}
        self.load_shedding_enabled = False
        self.emergency_cache_enabled = False
    
    def handle_node_overload(self, node):
        # 1. Enable circuit breaker
        self.enable_circuit_breaker(node)
        
        # 2. Start load shedding
        self.enable_load_shedding(node)
        
        # 3. Scale out if possible
        self.attempt_emergency_scaling()
        
        # 4. Enable emergency local caching
        self.enable_emergency_caching()
    
    def enable_circuit_breaker(self, node):
        circuit_breaker = CircuitBreaker(
            failure_threshold=50,  # 50% error rate
            recovery_timeout=30,   # 30 seconds
            expected_exception=TimeoutError
        )
        self.circuit_breakers[node.id] = circuit_breaker
    
    def enable_load_shedding(self, node):
        # Drop lowest priority requests
        node.enable_load_shedding(
            drop_percentage=20,  # Drop 20% of requests
            priority_threshold='LOW'
        )
    
    def enable_emergency_caching(self):
        # Enable aggressive client-side caching
        for client in self.connected_clients:
            client.enable_emergency_cache(
                ttl=300,  # 5 minute TTL
                max_size=10000  # 10K entries per client
            )

class CircuitBreaker:
    def __init__(self, failure_threshold, recovery_timeout, expected_exception):
        self.failure_threshold = failure_threshold
        self.recovery_timeout = recovery_timeout
        self.expected_exception = expected_exception
        
        self.failure_count = 0
        self.success_count = 0
        self.last_failure_time = None
        self.state = 'CLOSED'  # CLOSED, OPEN, HALF_OPEN
    
    def call(self, func, *args, **kwargs):
        if self.state == 'OPEN':
            if self.should_attempt_reset():
                self.state = 'HALF_OPEN'
            else:
                raise CircuitBreakerOpenException("Circuit breaker is open")
        
        try:
            result = func(*args, **kwargs)
            self.on_success()
            return result
        except self.expected_exception as e:
            self.on_failure()
            raise e
    
    def on_success(self):
        self.success_count += 1
        if self.state == 'HALF_OPEN' and self.success_count >= 3:
            self.state = 'CLOSED'
            self.failure_count = 0
    
    def on_failure(self):
        self.failure_count += 1
        self.last_failure_time = time.time()
        
        failure_rate = self.failure_count / (self.failure_count + self.success_count)
        if failure_rate >= self.failure_threshold:
            self.state = 'OPEN'
    
    def should_attempt_reset(self):
        return (time.time() - self.last_failure_time) > self.recovery_timeout
```

### 4. Memory Exhaustion

**Scenario**: Node runs out of memory and gets killed by OS

**Detection**:
```python
class MemoryExhaustionDetector:
    def __init__(self, warning_threshold=0.8, critical_threshold=0.95):
        self.warning_threshold = warning_threshold
        self.critical_threshold = critical_threshold
        self.monitoring_interval = 5.0  # 5 seconds
    
    def start_monitoring(self):
        def memory_monitor():
            while True:
                memory_usage = self.get_memory_usage_ratio()
                
                if memory_usage > self.critical_threshold:
                    self.handle_critical_memory_pressure()
                elif memory_usage > self.warning_threshold:
                    self.handle_memory_warning()
                
                time.sleep(self.monitoring_interval)
        
        thread = threading.Thread(target=memory_monitor, daemon=True)
        thread.start()
    
    def handle_critical_memory_pressure(self):
        # Emergency actions to prevent OOM kill
        
        # 1. Aggressive eviction
        self.trigger_aggressive_eviction()
        
        # 2. Stop accepting new writes
        self.stop_accepting_writes()
        
        # 3. Request immediate failover
        self.request_emergency_failover()
        
        # 4. Dump memory statistics for debugging
        self.dump_memory_stats()
    
    def trigger_aggressive_eviction(self):
        # Evict 20% of cache immediately
        target_eviction = self.get_total_keys() * 0.2
        self.eviction_manager.evict_keys(target_eviction)
    
    def stop_accepting_writes(self):
        # Reject new SET operations to prevent further memory growth
        self.write_operations_enabled = False
    
    def request_emergency_failover(self):
        # Signal cluster manager to failover this node
        self.cluster_manager.request_emergency_failover(self.node_id)
```

### 5. Data Corruption

**Scenario**: Memory corruption or disk errors corrupt cached data

**Detection**:
```python
class DataIntegrityChecker:
    def __init__(self):
        self.checksum_enabled = True
        self.periodic_check_interval = 3600  # 1 hour
    
    def store_with_checksum(self, key, value):
        # Calculate checksum
        checksum = self.calculate_checksum(value)
        
        # Store value with checksum
        stored_data = {
            'value': value,
            'checksum': checksum,
            'timestamp': time.time()
        }
        
        return self.storage.set(key, stored_data)
    
    def retrieve_with_verification(self, key):
        stored_data = self.storage.get(key)
        if not stored_data:
            return None
        
        # Verify checksum
        expected_checksum = self.calculate_checksum(stored_data['value'])
        if stored_data['checksum'] != expected_checksum:
            # Data corruption detected
            self.handle_corruption(key, stored_data)
            return None
        
        return stored_data['value']
    
    def handle_corruption(self, key, corrupted_data):
        # Log corruption incident
        self.log_corruption_incident(key, corrupted_data)
        
        # Remove corrupted data
        self.storage.delete(key)
        
        # Try to recover from replica
        self.attempt_recovery_from_replica(key)
        
        # Alert monitoring system
        self.alert_data_corruption(key)
    
    def calculate_checksum(self, data):
        import hashlib
        return hashlib.md5(str(data).encode()).hexdigest()
```

## Disaster Recovery

### Backup and Restore

```python
class BackupManager:
    def __init__(self, backup_interval=3600):  # 1 hour
        self.backup_interval = backup_interval
        self.backup_storage = S3BackupStorage()
        self.compression_enabled = True
    
    def start_periodic_backup(self):
        def backup_worker():
            while True:
                try:
                    self.create_backup()
                except Exception as e:
                    self.log_backup_error(e)
                
                time.sleep(self.backup_interval)
        
        thread = threading.Thread(target=backup_worker, daemon=True)
        thread.start()
    
    def create_backup(self):
        backup_id = f"backup_{int(time.time())}"
        
        # 1. Create consistent snapshot
        snapshot = self.create_consistent_snapshot()
        
        # 2. Compress if enabled
        if self.compression_enabled:
            snapshot = self.compress_snapshot(snapshot)
        
        # 3. Upload to backup storage
        self.backup_storage.upload(backup_id, snapshot)
        
        # 4. Update backup metadata
        self.update_backup_metadata(backup_id, snapshot)
        
        # 5. Clean up old backups
        self.cleanup_old_backups()
    
    def create_consistent_snapshot(self):
        # Pause writes temporarily
        self.pause_writes()
        
        try:
            # Create point-in-time snapshot
            snapshot = {
                'timestamp': time.time(),
                'data': self.storage.dump_all_data(),
                'metadata': self.get_cluster_metadata()
            }
            return snapshot
        finally:
            # Resume writes
            self.resume_writes()
    
    def restore_from_backup(self, backup_id):
        # 1. Download backup
        backup_data = self.backup_storage.download(backup_id)
        
        # 2. Decompress if needed
        if self.compression_enabled:
            backup_data = self.decompress_snapshot(backup_data)
        
        # 3. Validate backup integrity
        if not self.validate_backup(backup_data):
            raise BackupCorruptionError(f"Backup {backup_id} is corrupted")
        
        # 4. Clear current data
        self.storage.clear_all_data()
        
        # 5. Restore data
        self.storage.restore_data(backup_data['data'])
        
        # 6. Restore metadata
        self.restore_cluster_metadata(backup_data['metadata'])
```

### Cross-Region Disaster Recovery

```python
class DisasterRecoveryManager:
    def __init__(self):
        self.primary_region = 'us-east-1'
        self.dr_region = 'us-west-2'
        self.rpo_target = 300  # 5 minutes Recovery Point Objective
        self.rto_target = 1800  # 30 minutes Recovery Time Objective
    
    def setup_cross_region_replication(self):
        # Setup async replication to DR region
        dr_cluster = self.provision_dr_cluster()
        
        for primary_node in self.primary_cluster.nodes:
            dr_node = dr_cluster.get_corresponding_node(primary_node)
            self.setup_replication_stream(primary_node, dr_node)
    
    def handle_region_failure(self):
        # Primary region is down - failover to DR region
        
        # 1. Assess DR cluster readiness
        dr_readiness = self.assess_dr_readiness()
        if not dr_readiness.is_ready:
            raise DRNotReadyException(dr_readiness.issues)
        
        # 2. Promote DR cluster to primary
        self.promote_dr_cluster()
        
        # 3. Update DNS to point to DR region
        self.update_dns_to_dr_region()
        
        # 4. Notify applications of region change
        self.notify_region_failover()
        
        # 5. Monitor recovery progress
        self.monitor_failover_progress()
    
    def assess_dr_readiness(self):
        readiness = DRReadinessReport()
        
        # Check replication lag
        max_lag = max(node.replication_lag for node in self.dr_cluster.nodes)
        if max_lag > self.rpo_target:
            readiness.add_issue(f"Replication lag {max_lag}s exceeds RPO {self.rpo_target}s")
        
        # Check node health
        unhealthy_nodes = [n for n in self.dr_cluster.nodes if not n.is_healthy()]
        if unhealthy_nodes:
            readiness.add_issue(f"{len(unhealthy_nodes)} nodes are unhealthy")
        
        # Check capacity
        if self.dr_cluster.capacity < self.primary_cluster.capacity * 0.8:
            readiness.add_issue("DR cluster capacity is insufficient")
        
        return readiness
```

## Monitoring and Alerting

### Comprehensive Health Monitoring

```python
class HealthMonitoringSystem:
    def __init__(self):
        self.metrics_collector = MetricsCollector()
        self.alert_manager = AlertManager()
        self.health_checks = [
            NodeHealthCheck(),
            ReplicationHealthCheck(),
            MemoryHealthCheck(),
            NetworkHealthCheck(),
            DataIntegrityCheck()
        ]
    
    def start_monitoring(self):
        for health_check in self.health_checks:
            health_check.start()
    
    def collect_system_metrics(self):
        return {
            'node_status': self.get_node_status_metrics(),
            'performance': self.get_performance_metrics(),
            'capacity': self.get_capacity_metrics(),
            'errors': self.get_error_metrics(),
            'replication': self.get_replication_metrics()
        }
    
    def get_node_status_metrics(self):
        return {
            'total_nodes': len(self.cluster.nodes),
            'healthy_nodes': len([n for n in self.cluster.nodes if n.is_healthy()]),
            'failed_nodes': len([n for n in self.cluster.nodes if n.is_failed()]),
            'nodes_in_maintenance': len([n for n in self.cluster.nodes if n.in_maintenance])
        }
    
    def get_performance_metrics(self):
        return {
            'total_qps': sum(node.qps for node in self.cluster.nodes),
            'avg_latency_ms': self.calculate_avg_latency(),
            'p99_latency_ms': self.calculate_p99_latency(),
            'hit_rate': self.calculate_hit_rate(),
            'error_rate': self.calculate_error_rate()
        }
    
    def get_capacity_metrics(self):
        return {
            'total_memory_gb': sum(node.total_memory for node in self.cluster.nodes),
            'used_memory_gb': sum(node.used_memory for node in self.cluster.nodes),
            'memory_utilization': self.calculate_memory_utilization(),
            'total_connections': sum(node.connection_count for node in self.cluster.nodes),
            'eviction_rate': sum(node.eviction_rate for node in self.cluster.nodes)
        }

class AlertManager:
    def __init__(self):
        self.alert_rules = [
            AlertRule('node_down', 'healthy_nodes < total_nodes', 'CRITICAL'),
            AlertRule('high_latency', 'p99_latency_ms > 5', 'WARNING'),
            AlertRule('low_hit_rate', 'hit_rate < 0.9', 'WARNING'),
            AlertRule('memory_pressure', 'memory_utilization > 0.85', 'WARNING'),
            AlertRule('replication_lag', 'max_replication_lag > 10', 'CRITICAL'),
            AlertRule('error_spike', 'error_rate > 0.05', 'CRITICAL')
        ]
    
    def evaluate_alerts(self, metrics):
        active_alerts = []
        
        for rule in self.alert_rules:
            if rule.evaluate(metrics):
                alert = Alert(
                    rule_name=rule.name,
                    severity=rule.severity,
                    message=rule.generate_message(metrics),
                    timestamp=time.time()
                )
                active_alerts.append(alert)
        
        return active_alerts
    
    def send_alerts(self, alerts):
        for alert in alerts:
            if alert.severity == 'CRITICAL':
                self.send_pager_alert(alert)
            else:
                self.send_email_alert(alert)
```

## Chaos Engineering

### Fault Injection Testing

```python
class ChaosEngineer:
    def __init__(self, cluster):
        self.cluster = cluster
        self.chaos_experiments = [
            NodeFailureExperiment(),
            NetworkPartitionExperiment(),
            MemoryPressureExperiment(),
            LatencyInjectionExperiment(),
            DataCorruptionExperiment()
        ]
    
    def run_chaos_experiment(self, experiment_name):
        experiment = self.get_experiment(experiment_name)
        
        # 1. Record baseline metrics
        baseline = self.collect_baseline_metrics()
        
        # 2. Run experiment
        experiment.execute(self.cluster)
        
        # 3. Monitor system behavior
        behavior = self.monitor_system_behavior(experiment.duration)
        
        # 4. Clean up
        experiment.cleanup(self.cluster)
        
        # 5. Analyze results
        results = self.analyze_experiment_results(baseline, behavior)
        
        return results

class NodeFailureExperiment:
    def __init__(self):
        self.name = "node_failure"
        self.duration = 300  # 5 minutes
    
    def execute(self, cluster):
        # Randomly select a node to fail
        target_node = random.choice(cluster.nodes)
        
        # Simulate node failure
        self.failed_node = target_node
        target_node.simulate_failure()
        
        print(f"Simulating failure of node {target_node.id}")
    
    def cleanup(self, cluster):
        # Restore failed node
        if hasattr(self, 'failed_node'):
            self.failed_node.restore_from_failure()
            print(f"Restored node {self.failed_node.id}")

class NetworkPartitionExperiment:
    def __init__(self):
        self.name = "network_partition"
        self.duration = 180  # 3 minutes
    
    def execute(self, cluster):
        # Split cluster into two partitions
        nodes = list(cluster.nodes)
        partition_size = len(nodes) // 2
        
        self.partition_a = nodes[:partition_size]
        self.partition_b = nodes[partition_size:]
        
        # Block network communication between partitions
        for node_a in self.partition_a:
            for node_b in self.partition_b:
                node_a.block_communication_with(node_b)
                node_b.block_communication_with(node_a)
        
        print(f"Created network partition: {len(self.partition_a)} vs {len(self.partition_b)} nodes")
    
    def cleanup(self, cluster):
        # Restore network communication
        for node_a in self.partition_a:
            for node_b in self.partition_b:
                node_a.restore_communication_with(node_b)
                node_b.restore_communication_with(node_a)
        
        print("Restored network communication")
```

## Summary

Our failure handling strategy provides:

1. **Comprehensive Detection**: Health checks, circuit breakers, and monitoring
2. **Automatic Recovery**: Failover, load shedding, and self-healing mechanisms
3. **Cascade Prevention**: Circuit breakers and emergency protocols
4. **Data Protection**: Checksums, backups, and disaster recovery
5. **Chaos Engineering**: Proactive testing of failure scenarios

The system is designed to handle various failure modes gracefully, maintaining availability and data integrity even during complex failure scenarios. The combination of proactive monitoring, automatic recovery, and comprehensive testing ensures robust operation at scale.

This completes our distributed cache system design, covering all aspects from requirements analysis through failure handling. The system provides high performance, scalability, and reliability suitable for production use at internet scale.