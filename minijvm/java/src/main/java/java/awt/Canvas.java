package java.awt;

import org.lwjgl.opengl.Display;

public abstract class Canvas extends Component {
    private Dimension preferredSize;

    public synchronized void addNotify() {}
    public synchronized void removeNotify() {}

    public Canvas() {
        preferredSize = new Dimension(800, 600);
    }
    Graphics getGraphics() {
        return new Graphics();
    }
    int getHeight() {
        return Display.getHeight();
    }
    int getWidth() {
        return Display.getWidth();
    }
    void setPreferredSize(Dimension newSize) {
        preferredSize = newSize;
    }
    public void setFocusable(boolean focusable) {}
}
