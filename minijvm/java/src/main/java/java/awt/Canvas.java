package java.awt;

import org.lwjgl.opengl.Display;
import org.lwjgl.opengl.DisplayMode;

public abstract class Canvas extends Component {
    public synchronized void addNotify() {}
    public synchronized void removeNotify() {}

    public Canvas() {
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
        Display.setDisplayMode(new DisplayMode((int)newSize.getWidth(), (int)newSize.getHeight()));
    }
    public void setFocusable(boolean focusable) {}
}
