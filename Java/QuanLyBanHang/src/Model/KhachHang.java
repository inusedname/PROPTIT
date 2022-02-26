/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Model;

import java.io.Serializable;

/**
 *
 * @author inusedname
 */
public class KhachHang implements Serializable {

    private String id;
    private String name;
    private String address;
    private String mobile;
    private String email;

    public KhachHang() {
    }

    public KhachHang(String id, String name, String address, String mobile, String email) {
        this.id = id;
        this.name = name;
        this.address = address;
        this.mobile = mobile;
        this.email = email;
    }

    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getAddress() {
        return address;
    }

    public String getMobile() {
        return mobile;
    }

    public String getEmail() {
        return email;
    }

}
