package Controller;

import Model.*;
import Controller.Util.*;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class IO {
    public void showHoaDon(List<HoaDon> hd, List<KhachHang> khachHangs, List<Phong> phongs) {
        System.out.println("ID Phong - ID Khach Hang - Ten KH - Dia chi KH - SDT KH");
        for (HoaDon i : hd) {
            System.out.println(i.getIdPhong() + " - " + khachHangs.get(i.getIdKhach()).toString());
        }
    }

    public void showAvaibleRoom(String loaiPhong, List<Phong> phongs) {
        for (Phong x : phongs) {
            if (x.getLoaiphong().equals(loaiPhong)) {
                System.out.println(x.toString());
            }
        }
    }

    public void statisticRoomTypes(List<HoaDon> hd, List<Phong> phongs) {
        int VIPnum = 0, CLCnum = 0, NORMnum = 0;
        for (HoaDon x : hd) {
            int id = x.getIdPhong();
            switch (phongs.get(id).getLoaiphong()) {
                case "VIP" ->
                    VIPnum++;
                case "Chat luong cao" ->
                    CLCnum++;
                case "Thuong" ->
                    NORMnum++;
                default ->
                    throw new AssertionError();
            }
        }
        System.out.println("Khach o phong VIP: " + (int) (VIPnum / hd.size()) + "%");
        System.out.println("Khach o phong CLC: " + (int) (CLCnum / hd.size()) + "%");
        System.out.println("Khach o phong Thuong: " + (int) (NORMnum / hd.size()) + "%");
    }

    public void sortCustomers(List<KhachHang> kh) {
        List<KhachHang> tmp = new ArrayList<>();
        tmp.addAll(kh);
        System.out.println("Sap xep theo: ");
        System.out.println("1. Ten");
        System.out.println("2. Thoi gian thue phong.");
        int opt = Integer.parseInt(Input.cin.nextLine());
        switch (opt) {
            case 1 ->
                Collections.sort(tmp, Comparator.comparing(KhachHang::getName, Sorts.sortByName()));
            case 2 ->
                System.out.println("");
            default ->
                throw new AssertionError();
        }
        for (KhachHang x : tmp) {
            System.out.println(x.toString());
        }
    }
}
