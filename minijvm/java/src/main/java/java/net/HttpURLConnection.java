package java.net;

import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;

public class HttpURLConnection {
    public void setRequestProperty(String s, String s2) {
    }
    public void setRequestMethod(String s) {
    }

    public void connect() throws IOException {
        System.err.println("connect()");
        throw new IOException();
    }

    public void disconnect() {
    }

    public InputStream getInputStream() throws IOException {
        System.err.println("getInputStream()");
        throw new IOException();
    }

    public OutputStream getOutputStream() throws IOException {
        System.err.println("getOutputStream()");
        throw new IOException();
    }

    public void setDoOutput(boolean b) {
    }

    public void setDoInput(boolean b) {
    }

    public void setUseCaches(boolean b) {
    }

    public void setReadTimeout(int i) {
    }

    public void setConnectTimeout(int i) {
    }

    public boolean getUseCaches() {
        return false;
    }

    public int getDefaultPort() {
        return 0;
    }

    public int getPort() {
        return 0;
    }

    public void setPort(int i) {
    }
}
