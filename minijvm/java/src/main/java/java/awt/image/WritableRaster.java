package java.awt.image;

public class WritableRaster {

    private DataBufferInt db = new DataBufferInt();

    public DataBuffer getDataBuffer() {
        return db;
    }
}
