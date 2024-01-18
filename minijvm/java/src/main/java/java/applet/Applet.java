package java.applet;

import org.mini.reflect.vm.RefNative;
import java.awt.Component;
import java.awt.Panel;
import java.net.URL;
import java.net.MalformedURLException;
import java.util.Properties;

public abstract class Applet extends Panel {
  public abstract void init();
  public abstract void start();
  public abstract void stop();
  public abstract void destroy();

  private static Properties params = new Properties();

  private static synchronized boolean waitForAllThreads() {
    try {
      for (Thread t : RefNative.getThreads()) {
        if (t != Thread.currentThread()) {
          t.join();
          return false;
        }
      }
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
    return true;
  }

  public static void main(String[] args) throws Exception {
    try {
      params.put("username", "BlahajMastr");
      params.put("haspaid", "false");
      params.put("server", "localhost");
      params.put("port", "0");
      System.out.println("Applet launcher: main");
      String className = args[0];
      ClassLoader classLoader = ClassLoader.getSystemClassLoader();
      Class<?> clazz = classLoader.loadClass(className);
      Applet applet = (Applet) clazz.newInstance();

      System.out.println("Applet launcher: applet init");
      applet.init();

      System.out.println("Applet launcher: applet start");
      applet.start();

      System.out.println("Applet launcher: applet join");
      while (!waitForAllThreads()) {
      }

      System.out.println("Applet launcher: applet stop");
      applet.stop();

      System.out.println("Applet launcher: applet destroy");
      applet.destroy();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  public void add(Component c, Object o) {
    System.out.println("Add component");
    try {
      c.getClass().getMethod("addNotify").invoke(c);
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  public int getWidth() {
    return 800;
  }
  public int getHeight() {
    return 600;
  }
  public URL getCodeBase() {
    try {
      return new URL("http://www.minecraft.net/game/");
    } catch (MalformedURLException e) {
      e.printStackTrace();
      return null;
    }
  }
  public URL getDocumentBase() {
    try {
      return new URL("http://www.minecraft.net/game/");
    } catch (MalformedURLException e) {
      e.printStackTrace();
      return null;
    }
  }
  public String getParameter(String name) {
    System.err.println("getParameter: " + name);
    return params.getProperty(name, "");
   }
}
