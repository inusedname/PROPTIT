package Controller.Util;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.List;


public class IOFile {
    public static <T> void saveToFile(String dir, List<T> ls) throws FileNotFoundException, IOException {
        FileOutputStream fos = new FileOutputStream(dir, false);
        // Append mode is now false
        ObjectOutputStream oos = new ObjectOutputStream(fos);
        oos.writeObject(ls);
        oos.close();
        fos.close();
    }

    public static <T> List<T> loadFromFile(String dir) throws FileNotFoundException, IOException, ClassNotFoundException {
        FileInputStream fis = new FileInputStream(dir);
        ObjectInputStream ois = new ObjectInputStream(fis);
        List<T> tmp = (List<T>) ois.readObject();
        ois.close();
        fis.close();
        return tmp;
    }
}
