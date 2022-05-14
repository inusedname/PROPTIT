package Controller.Util;

import Model.Phong;
import java.time.LocalDate;
import java.util.Comparator;

public class Sorts {

    public static Comparator<String> sortByName() {
        return new Comparator<>() {
            @Override
            public int compare(String o1, String o2) {
                return o1.compareTo(o2);
            }
        };
    }

    public static Comparator<LocalDate> sortByElapsedTime() {
        return new Comparator<>() {
            @Override
            public int compare(LocalDate o1, LocalDate o2) {
                return o1.compareTo(o2);
            }
        };
    }
    
    public static Comparator<Phong> sortBySomething() { // m muốn sắp xếp mảng theo ý thích của mình
        return new Comparator<>() {
            @Override
            public int compare(Phong o1, Phong o2) {
                return Integer.valueOf(o1.getId()).compareTo(Integer.valueOf(o2.getId()));
                // return Double.valueOf(o1.tinhTienLuong()).compareTo(Double.valueOf(o2.tinhTienLuong());
            } 
        };
    }
}