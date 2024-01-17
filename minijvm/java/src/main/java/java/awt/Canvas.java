package java.awt;

public abstract class Canvas extends Component {
    private Dimension preferredSize;

    public synchronized void addNotify() {}
    public synchronized void removeNotify() {}

    public Canvas() {
        preferredSize = new Dimension(1024, 768);
    }
    Graphics getGraphics() {
        return new Graphics();
    }
    int getHeight() {
        return (int)preferredSize.getHeight();
    }
    int getWidth() {
        return (int)preferredSize.getWidth();
    }
    void setPreferredSize(Dimension newSize) {
        preferredSize = newSize;
    }
    public void setFocusable(boolean focusable) {}
}
