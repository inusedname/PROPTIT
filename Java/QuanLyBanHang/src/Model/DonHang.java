/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Model;

import java.io.Serializable;
import java.time.LocalDate;

/**
 *
 * @author inusedname
 */
public class DonHang implements Serializable {

    private static int idCount = 1;
    String idOrder;
    private String idProduct;
    private String idCustomer;
    private String idSeller;
    private int quantity;
    private LocalDate purchaseDate;

    public DonHang() {
    }

    public DonHang(String idProduct, String idCustomer, String idSeller, int quantity) {
        String id = Integer.toString(idCount);
        idOrder = "0".repeat(6 - id.length()) + id;
        this.idProduct = idProduct;
        this.idCustomer = idCustomer;
        this.idSeller = idSeller;
        this.quantity = quantity;
        this.purchaseDate = LocalDate.now();
    }
    
    public String getIdOrder() {
        return idOrder;
    }

    public String getIdProduct() {
        return idProduct;
    }

    public String getIdCustomer() {
        return idCustomer;
    }

    public String getIdSeller() {
        return idSeller;
    }

    public int getQuantity() {
        return quantity;
    }

    public LocalDate getPurchaseDate() {
        return purchaseDate;
    }

}
