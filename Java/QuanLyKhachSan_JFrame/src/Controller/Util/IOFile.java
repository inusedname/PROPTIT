package Controller.Util;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.List;

public class IOFile {

    public static <T> void saveToFile(String dir, List<T> ls) {
        File file = new File(dir);
        try {
            file.createNewFile();
            FileOutputStream fos = new FileOutputStream(file, false);
            // Append mode is now false
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            oos.writeObject(ls);
            oos.close();
            fos.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static <T> List<T> loadFromFile(String dir) {
        File file = new File(dir);
        List<T> tmp = new ArrayList<>();
        if (file.length() > 0) {
            try {
                file.createNewFile();
                FileInputStream fis = new FileInputStream(file);
                ObjectInputStream ois = new ObjectInputStream(fis);
                tmp = (List<T>) ois.readObject();
                ois.close();
                fis.close();

            } catch (IOException | ClassNotFoundException e) {
                e.printStackTrace();
            }
        }
        return tmp;
    }
}
