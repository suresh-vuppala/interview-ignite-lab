// Composite — Organization Hierarchy
interface OrganizationComponent {
    String getName();
    double getTotalSalary();
    void display(String indent);
}

class Employee implements OrganizationComponent {
    private String name;
    private String role;
    private double salary;
    
    public Employee(String name, String role, double salary) {
        this.name = name; this.role = role; this.salary = salary;
    }
    
    public String getName() { return name; }
    public double getTotalSalary() { return salary; }
    public void display(String indent) {
        System.out.println(indent + "👤 " + name + " (" + role + ") - $" + salary);
    }
}

class Department implements OrganizationComponent {
    private String name;
    private List<OrganizationComponent> members = new ArrayList<>();
    
    public Department(String name) { this.name = name; }
    public void add(OrganizationComponent member) { members.add(member); }
    
    public String getName() { return name; }
    public double getTotalSalary() {
        return members.stream().mapToDouble(OrganizationComponent::getTotalSalary).sum();
    }
    public void display(String indent) {
        System.out.println(indent + "🏢 " + name + " (Total: $" + getTotalSalary() + ")");
        members.forEach(m -> m.display(indent + "  "));
    }
}

// Department can contain Employees OR sub-Departments
// Engineering
//   ├── Backend Team
//   │   ├── Alice (Lead) - $120k
//   │   └── Bob (Dev) - $100k
//   └── Frontend Team
//       └── Carol (Dev) - $95k
