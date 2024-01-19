package org.lwjgl;

public class Sys {
    public long getTime() {
        return System.currentTimeMillis();
    }

    public long getTimerResolution() {
        return 1000L;
    }

    public String getVersion() {
        return "2.9.3";
     }
}
