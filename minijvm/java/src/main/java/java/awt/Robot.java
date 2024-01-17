package java.awt;

public class Robot {
    public void mouseMove(int x, int y) {
      org.lwjgl.input.Mouse.setCursorPosition(x, y);
    }
}
