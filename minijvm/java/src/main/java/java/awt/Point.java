package java.awt;

import java.util.Objects;

public class Point {
    private int x;
    private int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
     }

    public int getX() {
        return x;
    }
    public int getY() {
        return y;
    }
    public void setX(int x) {
        this.x = x;
    }
    public void setY(int y) {
        this.y = y;
    }
    public void translate(int dx, int dy) {
        this.x += dx;
        this.y += dy;
     }
    public String toString() {
        return "(" + x + "," + y + ")";
     }
    public boolean equals(Point p) {
        return this.x == p.x && this.y == p.y;
     }
    public boolean equals(int x, int y) {
        return this.x == x && this.y == y;
    }
    public int hashCode() {
        return Objects.hash(x, y);
    }
}
