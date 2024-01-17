package java.awt;

import org.lwjgl.input.Mouse;

public class PointerInfo {
    public static final PointerInfo INSTANCE = new PointerInfo();

    private PointerInfo() {}

    Point getLocation() {
        return new Point(Mouse.getX(), Mouse.getY());
    }
}
