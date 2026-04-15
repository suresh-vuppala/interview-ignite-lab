// Abstract Factory — Database Access Layer
interface Connection { void connect(); void disconnect(); }
interface Command { void execute(String query); }
interface ResultSet { boolean next(); String getString(int col); }

// MySQL family
class MySQLConnection implements Connection {
    public void connect() { System.out.println("MySQL connected"); }
    public void disconnect() { System.out.println("MySQL disconnected"); }
}
class MySQLCommand implements Command {
    public void execute(String query) { System.out.println("MySQL: " + query); }
}

// PostgreSQL family
class PostgresConnection implements Connection {
    public void connect() { System.out.println("Postgres connected"); }
    public void disconnect() { System.out.println("Postgres disconnected"); }
}
class PostgresCommand implements Command {
    public void execute(String query) { System.out.println("Postgres: " + query); }
}

// Abstract Factory
interface DatabaseFactory {
    Connection createConnection();
    Command createCommand();
}

class MySQLFactory implements DatabaseFactory {
    public Connection createConnection() { return new MySQLConnection(); }
    public Command createCommand() { return new MySQLCommand(); }
}

class PostgresFactory implements DatabaseFactory {
    public Connection createConnection() { return new PostgresConnection(); }
    public Command createCommand() { return new PostgresCommand(); }
}

// Client — database-agnostic
class Repository {
    private final Connection conn;
    private final Command cmd;
    
    public Repository(DatabaseFactory factory) {
        this.conn = factory.createConnection();
        this.cmd = factory.createCommand();
    }
    
    public void save(String data) {
        conn.connect();
        cmd.execute("INSERT INTO table VALUES ('" + data + "')");
        conn.disconnect();
    }
}
