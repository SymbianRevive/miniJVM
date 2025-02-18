package org.lwjgl.input;

public class Mouse {
    public static native void create();
    public static native void destroy();
    public static native int getDX();
    public static native int getDY();
    public static native int getX();
    public static native int getY();
    public static native int getEventX();
    public static native int getEventY();
    public static native int getEventDWheel();
    public static native int getEventButton();
    public static native boolean isButtonDown(int button);
    public static native boolean getEventButtonState();
    public static native boolean next();
    public static native void setGrabbed(boolean a1);
    public static Cursor setNativeCursor(Cursor a1) { return null; }
    public static native void setCursorPosition(int x, int y);
}
