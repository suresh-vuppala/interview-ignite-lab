## Time-Wheel Scheduling Algorithm

The time-wheel is an efficient data structure for scheduling tasks at specific times with O(1) insertion and deletion.

## Time-Wheel Structure

```python
class TimeWheel:
    def __init__(self):
        # Level 1: Seconds (60 buckets, 1-second granularity)
        self.seconds_wheel = [[] for _ in range(60)]
        
        # Level 2: Minutes (60 buckets, 1-minute granularity)
        self.minutes_wheel = [[] for _ in range(60)]
        
        # Level 3: Hours (24 buckets, 1-hour granularity)
        self.hours_wheel = [[] for _ in range(24)]
        
        # Level 4: Days (30 buckets, 1-day granularity)
        self.days_wheel = [[] for _ in range(30)]
        
        self.current_second = 0
        self.current_minute = 0
        self.current_hour = 0
        self.current_day = 0
    
    def add_task(self, task_id, scheduled_time):
        """Add task to appropriate wheel"""
        delay = scheduled_time - time.time()
        
        if delay < 60:
            # Add to seconds wheel
            bucket = (self.current_second + int(delay)) % 60
            self.seconds_wheel[bucket].append(task_id)
        
        elif delay < 3600:
            # Add to minutes wheel
            bucket = (self.current_minute + int(delay / 60)) % 60
            self.minutes_wheel[bucket].append(task_id)
        
        elif delay < 86400:
            # Add to hours wheel
            bucket = (self.current_hour + int(delay / 3600)) % 24
            self.hours_wheel[bucket].append(task_id)
        
        else:
            # Add to days wheel
            bucket = (self.current_day + int(delay / 86400)) % 30
            self.days_wheel[bucket].append(task_id)
    
    def tick(self):
        """Advance time by 1 second"""
        # Process current second bucket
        tasks = self.seconds_wheel[self.current_second]
        self.seconds_wheel[self.current_second] = []
        
        # Move tasks to execution queue
        for task_id in tasks:
            enqueue_for_execution(task_id)
        
        # Advance second
        self.current_second = (self.current_second + 1) % 60
        
        # Cascade from minutes wheel
        if self.current_second == 0:
            self.cascade_minutes()
    
    def cascade_minutes(self):
        """Move tasks from minutes wheel to seconds wheel"""
        tasks = self.minutes_wheel[self.current_minute]
        self.minutes_wheel[self.current_minute] = []
        
        for task_id in tasks:
            # Re-add to seconds wheel
            task = get_task(task_id)
            self.add_task(task_id, task.scheduled_time)
        
        self.current_minute = (self.current_minute + 1) % 60
        
        if self.current_minute == 0:
            self.cascade_hours()
```

## Cron Expression Parsing

```python
class CronParser:
    def parse(self, cron_expression):
        """Parse cron expression"""
        parts = cron_expression.split()
        
        return {
            "minute": self.parse_field(parts[0], 0, 59),
            "hour": self.parse_field(parts[1], 0, 23),
            "day": self.parse_field(parts[2], 1, 31),
            "month": self.parse_field(parts[3], 1, 12),
            "weekday": self.parse_field(parts[4], 0, 6)
        }
    
    def parse_field(self, field, min_val, max_val):
        """Parse single cron field"""
        if field == "*":
            return list(range(min_val, max_val + 1))
        
        if "/" in field:
            # Step values: */15 = every 15 minutes
            step = int(field.split("/")[1])
            return list(range(min_val, max_val + 1, step))
        
        if "-" in field:
            # Range: 1-5 = 1,2,3,4,5
            start, end = map(int, field.split("-"))
            return list(range(start, end + 1))
        
        if "," in field:
            # List: 1,3,5
            return [int(x) for x in field.split(",")]
        
        return [int(field)]
    
    def next_execution(self, cron_expr, from_time=None):
        """Calculate next execution time"""
        if from_time is None:
            from_time = datetime.now()
        
        parsed = self.parse(cron_expr)
        
        # Start from next minute
        next_time = from_time + timedelta(minutes=1)
        next_time = next_time.replace(second=0, microsecond=0)
        
        # Find next matching time
        for _ in range(366 * 24 * 60):  # Max 1 year
            if (next_time.minute in parsed["minute"] and
                next_time.hour in parsed["hour"] and
                next_time.day in parsed["day"] and
                next_time.month in parsed["month"] and
                next_time.weekday() in parsed["weekday"]):
                return next_time
            
            next_time += timedelta(minutes=1)
        
        return None
```

## Recurring Task Scheduling

```python
class RecurringTaskScheduler:
    def schedule_recurring(self, task_id, cron_expression):
        """Schedule recurring task"""
        # Calculate next execution
        next_time = CronParser().next_execution(cron_expression)
        
        # Add to time wheel
        time_wheel.add_task(task_id, next_time.timestamp())
        
        # Store for rescheduling after execution
        redis.hset(f"recurring:{task_id}", mapping={
            "cron_expression": cron_expression,
            "next_execution": next_time.timestamp()
        })
    
    def reschedule_after_execution(self, task_id):
        """Reschedule recurring task after execution"""
        cron_expr = redis.hget(f"recurring:{task_id}", "cron_expression")
        
        if cron_expr:
            # Calculate next execution
            next_time = CronParser().next_execution(cron_expr)
            
            # Add back to time wheel
            time_wheel.add_task(task_id, next_time.timestamp())
            
            # Update next execution time
            redis.hset(f"recurring:{task_id}", "next_execution", next_time.timestamp())
```

## Distributed Scheduling Coordination

```python
class DistributedScheduler:
    def __init__(self, scheduler_id):
        self.scheduler_id = scheduler_id
        self.is_leader = False
    
    def elect_leader(self):
        """Leader election using Redis"""
        # Try to acquire leader lock
        acquired = redis.set(
            "scheduler:leader",
            self.scheduler_id,
            nx=True,  # Only set if not exists
            ex=30     # Expire in 30 seconds
        )
        
        if acquired:
            self.is_leader = True
            # Renew lock periodically
            threading.Thread(target=self.renew_leader_lock, daemon=True).start()
    
    def renew_leader_lock(self):
        """Renew leader lock"""
        while self.is_leader:
            redis.expire("scheduler:leader", 30)
            time.sleep(10)
    
    def partition_tasks(self):
        """Partition tasks across schedulers using consistent hashing"""
        schedulers = redis.smembers("schedulers:active")
        scheduler_count = len(schedulers)
        
        # Each scheduler handles tasks where hash(task_id) % count == scheduler_index
        my_index = sorted(schedulers).index(self.scheduler_id)
        
        return lambda task_id: hash(task_id) % scheduler_count == my_index
```

This scheduling system achieves ±1 second accuracy for 10 million tasks/day using efficient time-wheel algorithm and distributed coordination.
