package Model;

import java.io.Serializable;

public class Phong  implements Serializable {

    public boolean available;
    public static int idPhongCount = 0;
    
    private int id;
    private String name;
    private String loaiPhong;

    public Phong(String name, String loaiPhong) {
        available = true;
        this.id = idPhongCount;
        idPhongCount++;
        this.name = name;
        this.loaiPhong = loaiPhong;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getLoaiphong() {
        return loaiPhong;
    }

    @Override
    public String toString() {
        return this.id + " - " + this.name + " - " + this.loaiPhong;
    }
}
