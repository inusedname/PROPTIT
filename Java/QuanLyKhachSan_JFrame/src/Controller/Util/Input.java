package Controller.Util;

import java.util.Scanner;
import Controller.Exceptions.*;
import Model.KhachHang;
import Model.Phong;
import java.util.List;

public class Input {

    static public Scanner cin;

    static {
        cin = new Scanner(System.in);
    }

    static public String readAndValidateLine(String inputWhat, String regex) {
        System.out.println(inputWhat);
        String str = cin.nextLine();
        while (true) {
            try {
                if (!str.matches(regex)) {
                    throw new InvalidInput();
                }
                return str;
            } catch (InvalidInput e) {
                System.out.println("Nhap sai." + inputWhat);
                str = cin.nextLine();
            }
        }
    }

    static public Integer searchCustomerReturnID(List<KhachHang> aList) {
        System.out.println("Nhap ten Khach Hang: ");
        String name = Input.readAndValidateLine("Nhap ten KH: ", "[A-Za-z][A-Za-z\\s]*");;
        while (true) {
            try {
                for (KhachHang x : aList) {
                    if (x.getName().equals(name)) {
                        return x.getId();
                    }
                }
                throw new NotFoundItem();
            } catch (NotFoundItem e) {
                System.out.println("Khong tim thay khach hang. Nhap lai ten KH:");
                name = Input.readAndValidateLine("Nhap ten KH: ", "[A-Za-z][A-Za-z\\s]*");;
            }
        }
    }

    static public Integer searchRoomReturnID(List<Phong> aList) {
        System.out.println("Nhap ten Phong: ");
        String name = Input.readAndValidateLine("Nhap ten phong: ", "\\w[\\w\\s]*");
        while (true) {
            try {
                for (Phong x : aList) {
                    if (x.getName().equals(name)) {
                        return x.getId();
                    }
                }
                throw new NotFoundItem();
            } catch (NotFoundItem e) {
                System.out.println("Khong tim thay phong. Nhap lai ten KH:");
                name = Input.readAndValidateLine("Nhap ten phong: ", "\\w[\\w\\s]*");
            }
        }
    }
}
