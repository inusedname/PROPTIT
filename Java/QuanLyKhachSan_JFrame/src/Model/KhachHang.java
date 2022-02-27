/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Model;

import java.io.Serializable;


public class KhachHang implements Serializable {

    public enum LOAIKH_ENUM {
        SINHVIEN, HOGIADINH, DOANHNGHIEP;
    }
    public static int idKhachCount = 0;
    private int id;
    private String name;
    private String address;
    private String telephone;
    private LOAIKH_ENUM loaiKhachHang;
    private int maPhong;

    public int getMaPhong() {
        return maPhong;
    }

    public LOAIKH_ENUM getLoaiKhachHang() {
        return loaiKhachHang;
    }

    public KhachHang(String name, String address, String telephone, LOAIKH_ENUM cusType, int maPhong) {
        this.id = idKhachCount;
        idKhachCount++;
        this.name = name;
        this.address = address;
        this.telephone = telephone;
        this.loaiKhachHang = cusType;
        this.maPhong = maPhong;
    }

    public KhachHang(KhachHang y) {
        this.id = y.getId();
        this.name = y.getName();
        this.address = y.getAddress();
        this.telephone = y.getTelephone();
        this.loaiKhachHang = y.getLoaiKhachHang();
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getAddress() {
        return address;
    }

    public String getTelephone() {
        return telephone;
    }

    @Override
    public String toString() {
        return this.id + " - " + this.name + " - " + this.address + " - " + this.telephone;
    }
}
