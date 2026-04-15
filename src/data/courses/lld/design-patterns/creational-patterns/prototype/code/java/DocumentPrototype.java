// Prototype — Document Template System
abstract class DocumentTemplate implements Cloneable {
    protected String title;
    protected String content;
    protected Map<String, String> metadata;
    protected List<String> sections;
    
    public abstract DocumentTemplate clone();
    
    public void setTitle(String title) { this.title = title; }
    public void addSection(String section) { this.sections.add(section); }
    public void setMetadata(String key, String value) { metadata.put(key, value); }
}

class ReportTemplate extends DocumentTemplate {
    public ReportTemplate() {
        this.title = "Report Template";
        this.content = "";
        this.metadata = new HashMap<>();
        this.sections = new ArrayList<>(List.of("Executive Summary", "Analysis", "Conclusion"));
        this.metadata.put("type", "report");
        this.metadata.put("version", "1.0");
    }
    
    @Override
    public ReportTemplate clone() {
        ReportTemplate copy = new ReportTemplate();
        copy.title = this.title;
        copy.content = this.content;
        copy.metadata = new HashMap<>(this.metadata);     // Deep copy
        copy.sections = new ArrayList<>(this.sections);    // Deep copy
        return copy;
    }
}

class TemplateRegistry {
    private static final Map<String, DocumentTemplate> templates = new HashMap<>();
    
    static {
        templates.put("report", new ReportTemplate());
        // Add more templates...
    }
    
    public static DocumentTemplate create(String type) {
        DocumentTemplate proto = templates.get(type);
        if (proto == null) throw new IllegalArgumentException("Unknown template: " + type);
        return proto.clone();
    }
}
