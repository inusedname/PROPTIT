package Model;

import java.io.Serializable;
import java.time.LocalDate;

public class HoaDon implements Serializable {

    private final int idKhach;
    private final int idPhong;
    private final LocalDate ngayThue;

    public HoaDon(int idKhach, int idPhong, LocalDate ngayThue) {
        this.idKhach = idKhach;
        this.idPhong = idPhong;
        this.ngayThue = ngayThue;
    }

    public int getIdKhach() {
        return idKhach;
    }

    public int getIdPhong() {
        return idPhong;
    }

    public LocalDate getNgayThue() {
        return ngayThue;
    }

}
