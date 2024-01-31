package test;

import org.lwjgl.opengl.Display;
// import org.lwjgl.opengl.DisplayMode;
import org.lwjgl.opengl.GL11;

public class LWJGL2 {
    
    public void start() {
        try {
            // Display.setDisplayMode(new DisplayMode(800, 600));
            Display.create();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }

        // Initialize OpenGL
        GL11.glMatrixMode(0x1701);
        GL11.glLoadIdentity();
        GL11.glOrtho(0, 800, 0, 600, 1, -1);
        GL11.glMatrixMode(0x1700);

        // Main loop
        while (true) {
            // Clear the screen and depth buffer
            GL11.glClear(0x00004000 | 0x00000100);

            // Draw a colored triangle
            GL11.glBegin(0x0004);
            GL11.glColor3f(1.0f, 0.0f, 0.0f); // Red
            GL11.glVertex2f(400, 100);
            GL11.glColor3f(0.0f, 1.0f, 0.0f); // Green
            GL11.glVertex2f(100, 700);
            GL11.glColor3f(0.0f, 0.0f, 1.0f); // Blue
            GL11.glVertex2f(700, 700);
            GL11.glEnd();

            Display.update();
        }

        // Display.destroy();
    }

    public static void main(String[] args) {
        LWJGL2 example = new LWJGL2();
        example.start();
    }
}
