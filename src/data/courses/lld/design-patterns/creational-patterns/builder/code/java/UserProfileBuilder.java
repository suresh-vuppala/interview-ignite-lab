// Builder — User Profile with many optional fields
public class UserProfile {
    private final String username;     // Required
    private final String email;        // Required
    private final String firstName;    // Optional
    private final String lastName;     // Optional
    private final int age;             // Optional
    private final String bio;          // Optional
    private final String avatarUrl;    // Optional
    private final boolean isPublic;    // Optional
    private final List<String> interests; // Optional
    
    private UserProfile(Builder builder) {
        this.username = builder.username;
        this.email = builder.email;
        this.firstName = builder.firstName;
        this.lastName = builder.lastName;
        this.age = builder.age;
        this.bio = builder.bio;
        this.avatarUrl = builder.avatarUrl;
        this.isPublic = builder.isPublic;
        this.interests = Collections.unmodifiableList(builder.interests);
    }
    
    // Getters only — immutable!
    public String getUsername() { return username; }
    public String getEmail() { return email; }
    
    public static class Builder {
        private final String username;
        private final String email;
        private String firstName = "";
        private String lastName = "";
        private int age = 0;
        private String bio = "";
        private String avatarUrl = "";
        private boolean isPublic = true;
        private List<String> interests = new ArrayList<>();
        
        public Builder(String username, String email) {
            this.username = username;
            this.email = email;
        }
        
        public Builder firstName(String fn) { this.firstName = fn; return this; }
        public Builder lastName(String ln) { this.lastName = ln; return this; }
        public Builder age(int age) { this.age = age; return this; }
        public Builder bio(String bio) { this.bio = bio; return this; }
        public Builder avatar(String url) { this.avatarUrl = url; return this; }
        public Builder isPublic(boolean p) { this.isPublic = p; return this; }
        public Builder interest(String i) { this.interests.add(i); return this; }
        
        public UserProfile build() {
            if (username == null || username.isEmpty())
                throw new IllegalStateException("Username required");
            if (email == null || !email.contains("@"))
                throw new IllegalStateException("Valid email required");
            return new UserProfile(this);
        }
    }
}

// Usage
// UserProfile profile = new UserProfile.Builder("john_doe", "john@example.com")
//     .firstName("John").lastName("Doe").age(28)
//     .bio("Software engineer").interest("Coding").interest("Gaming")
//     .build();
