package Controller.Util;

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
}
