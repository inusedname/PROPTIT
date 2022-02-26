/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.helloworld;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author inusedname
 */
class Vehicle {

    protected String id;
    protected String manafactor;
    protected String date;
    protected double price;
    protected String color;

    Vehicle() {
        this.id = "";
        this.manafactor = "";
        this.date = "";
    }

    public void setInfo() {
        Scanner cin = new Scanner(System.in);
        while (id.matches("[a-zA-Z]{2}\\d{3}") == false) {
            System.out.println("Ma so xe (2 chu 3 so): ");
            id = cin.nextLine();
        }
        while (manafactor.matches("[a-zA-Z]+") == false) {
            System.out.println("Ten nsx (chi gom cac chu cai, it nhat 1 chu): ");
            manafactor = cin.nextLine();
        }
        while (date.matches("\\d{4}") == false) {
            System.out.println("Nam san xuat (4 so): ");
            date = cin.nextLine();
        }
        System.out.println("Gia mot xe: ");
        price = Double.parseDouble(cin.nextLine());
        System.out.println("Mau xe: ");
        color = cin.nextLine();
    }

    public void showInfo() {
        System.out.println("ID: " + id);
        System.out.println("NSX: " + manafactor);
        System.out.println("Nam san xuat: " + date);
        System.out.println("Gia xe: " + price);
        System.out.println("Mau xe: " + color);

    }
}

class Car extends Vehicle {

    private String engineSeries;
    private int nSeats;

    @Override
    public void setInfo() {
        super.setInfo();
        System.out.println("Loai dong co: ");
        Scanner cin = new Scanner(System.in);
        engineSeries = cin.nextLine();
        System.out.println("So ghe: ");
        nSeats = Integer.parseInt(cin.nextLine());
    }

    @Override
    public void showInfo() {
        super.showInfo();
        System.out.println("Loai dong co: " + engineSeries);
        System.out.println("So ghe: " + nSeats);
    }

    public String getEngineSeries() {
        return engineSeries;
    }

    public int getNSeats() {
        return nSeats;
    }
}

class Motorbike extends Vehicle {

    private double power;

    @Override
    public void setInfo() {
        super.setInfo();
        System.out.println("Cong suat dong co: ");
        Scanner cin = new Scanner(System.in);
        power = Double.parseDouble(cin.nextLine());
    }

    @Override
    public void showInfo() {
        super.showInfo();
        System.out.println("Cong suat dong co: " + power);
    }

    public double getPower() {
        return power;
    }
}

class Truck extends Vehicle {

    private double load;

    @Override
    public void setInfo() {
        super.setInfo();
        System.out.println("Tai trong: ");
        Scanner cin = new Scanner(System.in);
        load = Double.parseDouble(cin.nextLine());
    }

    @Override
    public void showInfo() {
        super.showInfo();
        System.out.println("Tai trong: " + load);
    }

    public double getLoad() {
        return load;
    }
}

class VehicleManager {

    private List<Vehicle> vehicle = new ArrayList<>();

    public void addVehicle() {
        int opt;
        Scanner cin = new Scanner(System.in);
        System.out.println("=".repeat(30));
        System.out.println("Them xe: ");
        System.out.println("1.Oto   2.Xe may   3.Xe tai");
        opt = cin.nextInt();
        Vehicle tmp;
        switch (opt) {
            case 1:
                tmp = new Car();
                break;
            case 2:
                tmp = new Motorbike();
                break;
            default:
                tmp = new Truck();
                break;
        }
        tmp.setInfo();
        vehicle.add(tmp);
    }

    public void showVehicle() {
        int opt;
        int count = 0;
        Scanner cin = new Scanner(System.in);
        System.out.println("=".repeat(30));
        System.out.println("In danh sach: ");
        System.out.println("1.Oto   2.Xe may   3.Xe tai");
        opt = cin.nextInt();
        switch (opt) {
            case 1 -> {
                for (Vehicle tmp : vehicle) {
                    if (tmp instanceof Car) {
                        tmp.showInfo();
                        count++;
                    }
                }
                System.out.println("=".repeat(10));
                System.out.println("Tong: " + count + " o to");
            }
            case 2 -> {
                for (Vehicle tmp : vehicle) {
                    if (tmp instanceof Motorbike) {
                        tmp.showInfo();
                        count++;
                    }
                }
                System.out.println("=".repeat(10));
                System.out.println("Tong: " + count + " xe may");
            }
            case 3 -> {
                for (Vehicle tmp : vehicle) {
                    if (tmp instanceof Truck) {
                        tmp.showInfo();
                        count++;
                    }
                }
                System.out.println("=".repeat(10));
                System.out.println("Tong: " + count + " xe tai");
            }
            default ->
                throw new AssertionError();
        }
    }

    public void findVehicle() {
        int opt;
        Scanner cin = new Scanner(System.in);
        System.out.println("=".repeat(30));
        System.out.println("Tim kiem - Lua chon tieu chi: ");
        System.out.println("1.ID\n2.Hang SX\n3.Nam SX\n4.Gia ban\n5.Mau sac");
        System.out.println("6.Kieu dong co (oto)\n7.So cho ngoi (oto)\n8.Cong suat(xe may)\n9.Trong tai(xe tai)");
        opt = Integer.parseInt(cin.nextLine());
        String target = cin.nextLine();
        switch (opt) {
            case 1 -> {
                for (Vehicle tmp : vehicle) {
                    if (tmp.id.contains(target)) {
                        System.out.println("=".repeat(10));
                        tmp.showInfo();
                    }
                }
            }
            case 2 -> {
                for (Vehicle tmp : vehicle) {
                    if (tmp.manafactor.contains(target)) {
                        System.out.println("=".repeat(10));
                        tmp.showInfo();
                    }
                }
            }
            case 3 -> {
                for (Vehicle tmp : vehicle) {
                    if (tmp.date.contains(target)) {
                        System.out.println("=".repeat(10));
                        tmp.showInfo();
                    }
                }
            }
            case 4 -> {
                for (Vehicle tmp : vehicle) {
                    if (Double.parseDouble(target) == tmp.price) {
                        System.out.println("=".repeat(10));
                        tmp.showInfo();
                    }
                }
            }
            case 5 -> {
                for (Vehicle tmp : vehicle) {
                    if (tmp.color.contains(target)) {
                        System.out.println("=".repeat(10));
                        tmp.showInfo();
                    }
                }
            }
            case 6 -> {
                for (Vehicle tmp : vehicle) {
                    if (tmp instanceof Car car) {
                        if (car.getEngineSeries().contains(target)) {
                            System.out.println("=".repeat(10));
                            tmp.showInfo();
                        }
                    }
                }
            }
            case 7 -> {
                for (Vehicle tmp : vehicle) {
                    if (tmp instanceof Car car) {
                        if (car.getNSeats() == Integer.parseInt(target)) {
                            System.out.println("=".repeat(10));
                            tmp.showInfo();
                        }
                    }
                }
            }
            case 8 -> {
                for (Vehicle tmp : vehicle) {
                    if (tmp instanceof Motorbike mb) {
                        if (mb.getPower() == Double.parseDouble(target)) {
                            System.out.println("=".repeat(10));
                            tmp.showInfo();
                        }
                    }
                }
            }
            case 9 -> {
                for (Vehicle tmp : vehicle) {
                    if (tmp instanceof Truck truck) {
                        if (truck.getLoad() == Double.parseDouble(target)) {
                            System.out.println("=".repeat(10));
                            tmp.showInfo();
                        }
                    }
                }
            }
            default ->
                throw new AssertionError();

        }
    }

    public void findVehiclebyRange() {
        int opt;
        Scanner cin = new Scanner(System.in);
        System.out.println("=".repeat(30));
        System.out.println("Tim kiem theo khoang - Lua chon tieu chi: ");
        System.out.println("1.Year - Year\n2.Price - Price");
        opt = Integer.parseInt(cin.nextLine());
        if (opt == 1) {
            String startString, endString;
            System.out.println("Nhap nam bat dau:");
            startString = cin.nextLine();
            System.out.println("Nhap nam ket thuc:");
            endString = cin.nextLine();
            for (Vehicle x : vehicle) {
                if (x.date.compareTo(startString) >= 0 && x.date.compareTo(endString) <= 0) {
                    System.out.println("=".repeat(10));
                    x.showInfo();
                }
            }
        } else {
            double a, b;
            System.out.println("Nhap gia thap nhat:");
            a = Double.parseDouble(cin.nextLine());
            System.out.println("Nhap gia cao nhat:");
            b = Double.parseDouble(cin.nextLine());
            for (Vehicle x : vehicle) {
                if (x.price >= a && x.price <= b) {
                    System.out.println("=".repeat(10));
                    x.showInfo();
                }
            }
        }
    }

    public void sortVehicle() {
        int opt;
        Scanner cin = new Scanner(System.in);
        System.out.println("=".repeat(30));
        System.out.println("Sap xep - Lua chon tieu chi: ");
        System.out.println("1.Hang SX\n2.Gia ban\n3.Nam SX");
        opt = Integer.parseInt(cin.nextLine());
        List<Vehicle> tmp = List.copyOf(vehicle);
        switch (opt) {
            case 1 -> {
                tmp.sort((Vehicle o1, Vehicle o2) -> o1.manafactor.compareTo(o2.manafactor));
            }
            case 2 -> {
                tmp.sort((Vehicle o1, Vehicle o2) -> (o1.price < o2.price) ? -1 : 1);
            }
            case 3 -> {
                tmp.sort((Vehicle o1, Vehicle o2) -> (o1.date.compareTo(o2.date)));
            }
        }
    }
}

public class W2B1 {

    public static void main(String[] args) {
        VehicleManager prog = new VehicleManager();
        prog.addVehicle();
        prog.showVehicle();

    }
}
