import java.util.*;

class CustomKey {
    int x, y;
    public int hashCode() {
        return Objects.hash(x, y);
    }
    public boolean equals(Object o) {
        if (!(o instanceof CustomKey)) return false;
        CustomKey k = (CustomKey) o;
        return x == k.x && y == k.y;
    }
}

class Main {
    public static void main(String[] args) {
        HashMap<CustomKey, Integer> map = new HashMap<>();
    }
}