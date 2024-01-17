package java.awt;

import org.lwjgl.input.Mouse;
import org.lwjgl.opengl.Display;

public class PointerInfo {
    public static final PointerInfo INSTANCE = new PointerInfo();

    private PointerInfo() {}

    Point getLocation() {
        return new Point(Mouse.getX(), Display.getHeight() - Mouse.getY());
    }
}
