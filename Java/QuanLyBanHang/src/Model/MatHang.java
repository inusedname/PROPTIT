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
public class MatHang implements Serializable {

    private String id;
    private String name;
    private String category;
    private double price;

    public MatHang() {

    }

    public MatHang(String idString, String nameString, String catString, double price) {
        this.id = idString;
        this.name = nameString;
        this.category = catString;
        this.price = price;
    }

    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getCategory() {
        return category;
    }

    public double getPrice() {
        return price;
    }
}
