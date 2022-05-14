package Model;

import java.io.Serializable;

public class Phong implements Serializable {

    public boolean available;
    public static int idPhongCount = 10000;

    private int id;
    private String name;
    private String loaiPhong;

    public Phong(String name, String loaiPhong, int id) {
        if (id < 0) {
            available = true;
            this.id = idPhongCount;
            idPhongCount++;
        } else {
            this.id = id;
        }
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
