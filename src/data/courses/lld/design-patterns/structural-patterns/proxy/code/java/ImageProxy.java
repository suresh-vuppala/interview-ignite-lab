// Proxy — Virtual Proxy for Lazy Image Loading
interface Image {
    void display();
    int getWidth();
    int getHeight();
}

// Heavy object — expensive to create
class HighResImage implements Image {
    private String filename;
    private byte[] data;
    
    public HighResImage(String filename) {
        this.filename = filename;
        loadFromDisk(); // EXPENSIVE — loads entire image into memory
    }
    
    private void loadFromDisk() {
        System.out.println("Loading " + filename + " from disk... (slow!)");
        this.data = new byte[10_000_000]; // 10MB image
    }
    
    public void display() { System.out.println("Displaying " + filename); }
    public int getWidth() { return 1920; }
    public int getHeight() { return 1080; }
}

// Virtual Proxy — delays loading until actually needed
class ImageProxy implements Image {
    private String filename;
    private HighResImage realImage; // null until needed
    
    public ImageProxy(String filename) {
        this.filename = filename;
        // NO loading here — just store the filename
    }
    
    public void display() {
        if (realImage == null) {
            realImage = new HighResImage(filename); // Load on first use
        }
        realImage.display();
    }
    
    public int getWidth() { return 1920; }  // Known without loading
    public int getHeight() { return 1080; } // Known without loading
}

// Client uses proxy — doesn't know about lazy loading
// List<Image> gallery = List.of(
//     new ImageProxy("photo1.jpg"),  // NOT loaded yet
//     new ImageProxy("photo2.jpg"),  // NOT loaded yet
//     new ImageProxy("photo3.jpg")   // NOT loaded yet
// );
// gallery.get(0).display(); // NOW photo1.jpg loads
