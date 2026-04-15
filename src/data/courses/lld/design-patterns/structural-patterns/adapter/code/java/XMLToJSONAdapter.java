// Adapter — XML to JSON converter
interface JSONDataSource {
    String readJSON();
    void writeJSON(String json);
}

// Legacy XML system
class XMLDataSource {
    public String readXML() { return "<data><name>John</name></data>"; }
    public void writeXML(String xml) { System.out.println("Writing XML: " + xml); }
}

// Adapter: makes XML source look like JSON source
class XMLToJSONAdapter implements JSONDataSource {
    private XMLDataSource xmlSource;
    
    public XMLToJSONAdapter(XMLDataSource xmlSource) {
        this.xmlSource = xmlSource;
    }
    
    @Override
    public String readJSON() {
        String xml = xmlSource.readXML();
        return convertXMLtoJSON(xml); // Transform format
    }
    
    @Override
    public void writeJSON(String json) {
        String xml = convertJSONtoXML(json); // Transform format
        xmlSource.writeXML(xml);
    }
    
    private String convertXMLtoJSON(String xml) {
        // Conversion logic
        return "{"name": "John"}";
    }
    
    private String convertJSONtoXML(String json) {
        return "<data><name>John</name></data>";
    }
}
