package com.mycompany.helloworld;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

class GiaoVien {

    protected String name;
    protected int id;
    protected String email;
    protected String position;
    protected String degree;
    protected String homeAddress;
    protected String telephone;
    protected int hours;
    protected float multi;
    protected float salary;

    public void setInfo() {
        Scanner cin = new Scanner(System.in);
        System.out.println("Ho ten: ");
        name = cin.nextLine();
        System.out.println("ID: ");
        id = Integer.valueOf(cin.nextLine());
        System.out.println("Email: ");
        email = cin.nextLine();
        System.out.println("Hoc ham (khong, giao su, pho giao su): ");
        position = cin.nextLine();
        System.out.println("Hoc vi (dai hoc, thac si, tien si): ");
        degree = cin.nextLine();
        System.out.println("Dia chi nha: ");
        homeAddress = cin.nextLine();
        System.out.println("Di dong: ");
        telephone = cin.nextLine();
        System.out.println("Gio day trong thang nay: ");
        hours = cin.nextInt();
        if (null != degree) {
            switch (degree) {
                case "dai hoc" ->
                    multi = 1f;
                case "thac si" ->
                    multi = 1.1f;
                case "tien si" ->
                    multi = 1.2f;
            }
        }
        if (null != position) {
            switch (position) {
                case "giao su" ->
                    multi += 0.2f;
                case "pho giao su" ->
                    multi += 0.1f;
            }
        }
    }

    public void showInfo() {
        System.out.println("Ho ten: " + name);
        System.out.println("ID: " + id);
        System.out.println("Email: " + email);
        System.out.println("Hoc ham: " + position);
        System.out.println("Hoc vi: " + degree);
        System.out.println("Dia chi nha: " + homeAddress);
        System.out.println("Di dong: " + telephone);
        System.out.println("Gio day trong thang nay: " + hours);
    }

}

class Permanent extends GiaoVien {

    private int fixedSalary;
    private int fixedHour;
    private final int surplusSalary;

    Permanent() {
        surplusSalary = 50;
    }

    @Override
    public void setInfo() {
        super.setInfo();
        Scanner cin = new Scanner(System.in);
        System.out.println("Luong cung: ");
        fixedSalary = cin.nextInt();
        System.out.println("So gio quy dinh: ");
        fixedHour = cin.nextInt();
        salary = multi * Math.min(fixedHour, hours) * fixedSalary;
        if (hours > fixedHour) {
            salary += multi * surplusSalary * (hours - fixedHour);
        }
    }

    @Override
    public void showInfo() {
        super.showInfo();
        System.out.println("So gio quy dinh: " + fixedHour);
        System.out.println("Luong ngoai gio: " + surplusSalary);
        System.out.println("TONG LUONG = " + salary);
    }
}

class Temporary extends GiaoVien {

    private String workAddress;
    private String workTelephone;
    private final int wagePerHour;

    Temporary() {
        wagePerHour = 200;
    }

    @Override
    public void setInfo() {
        super.setInfo();
        Scanner cin = new Scanner(System.in);
        System.out.println("Dia chi co quan: ");
        workAddress = cin.nextLine();
        System.out.println("SDT co quan: ");
        workTelephone = cin.nextLine();
        salary = hours * multi * wagePerHour;
    }

    @Override
    public void showInfo() {
        super.showInfo();
        System.out.println("Dia chi co quan: " + workAddress);
        System.out.println("SDT co quan: " + workTelephone);
        System.out.println("Tien luong 1 gio: " + wagePerHour);
        System.out.println("TONG LUONG = " + salary);
    }
}

class TeacherManager {

    private ArrayList<Temporary> tempTeacher = new ArrayList<>();
    private ArrayList<Permanent> permaTeacher = new ArrayList<>();

    public void createTeacher() {
        GiaoVien tmp;
        Scanner cin = new Scanner(System.in);
        System.out.println("=".repeat(30));
        System.out.println("So luong ? ");
        int n = Integer.parseInt(cin.nextLine());
        for (int i = 0; i < n; i++) {
            System.out.println("=".repeat(30));
            System.out.println("Giang vien ? (co huu, thinh giang): ");
            String opt = cin.nextLine();
            if ("co huu".equals(opt)) {
                tmp = new Permanent();
                tmp.setInfo();
                permaTeacher.add((Permanent) tmp);
                System.out.println("Them giang vien co huu thanh cong!");
            } else if ("thinh giang".equals(opt)) {
                tmp = new Temporary();
                tmp.setInfo();
                tempTeacher.add((Temporary) tmp);
                System.out.println("Them giang vien thinh giang thanh cong!");
            } else {
                System.err.println("Chi dien thinh giang hoac co huu!");
            }
        }
    }

    public void showTeacher() {
        System.out.println("=".repeat(30));
        System.out.println("In danh sach: (co huu / thinh giang / toan bo)");
        Scanner cin = new Scanner(System.in);
        String opt = cin.nextLine();
        if ("co huu".equals(opt)) {
            for (Permanent x : permaTeacher) {
                System.out.println("=".repeat(30));
                x.showInfo();
            }
            System.out.println("Tong giao vien co huu: " + permaTeacher.size());
        } else if ("thinh giang".equals(opt)) {
            for (Temporary x : tempTeacher) {
                System.out.println("=".repeat(30));
                x.showInfo();
            }
            System.out.println("Tong giao vien thinh giang: " + tempTeacher.size());
        } else if ("toan bo".equals(opt)) {
            for (Permanent x : permaTeacher) {
                System.out.println("=".repeat(30));
                x.showInfo();
            }
            for (Temporary x : tempTeacher) {
                System.out.println("=".repeat(30));
                x.showInfo();
            }
            System.out.println("Tong giao vien thinh giang: " + (tempTeacher.size() + permaTeacher.size()));
        } else {
            System.err.println("Chi dien thinh giang hoac co huu!");
        }
    }

    public void removeTeacher() {
        System.out.println("=".repeat(30));
        System.out.println("Xoa giao vien: Nhap ID gv:");
        boolean found = false;
        Scanner cin = new Scanner(System.in);
        Integer whatID = Integer.parseInt(cin.nextLine());
        for (Temporary x : tempTeacher) {
            if (x.id == whatID) {
                System.out.println("Found!");
                x.showInfo();
                System.out.println("Confirm delete ? (Y/N)");
                String opt = cin.nextLine();
                if ("Y".equals(opt)) {
                    tempTeacher.remove(x);
                    found = true;
                    System.out.println("Remove sucessfully");
                    break;
                }
            }
        }
        if (found == false) {
            for (Permanent x : permaTeacher) {
                if (x.id == whatID) {
                    System.out.println("Found!");
                    x.showInfo();
                    System.out.println("Confirm delete ? (Y/N)");
                    String opt = cin.nextLine();
                    if ("Y".equals(opt)) {
                        permaTeacher.remove(x);
                        System.out.println("Remove sucessfully");
                        break;
                    }
                }
            }
        }
    }

    public void findTeacher() {
        System.out.println("=".repeat(30));
        System.out.println("Nhap ten giao vien:");
        Scanner cin = new Scanner(System.in);
        String target = cin.nextLine().toLowerCase();
        int res = 0;
        for (GiaoVien i : tempTeacher) {
            if (i.name.contains(target)) {
                System.out.println(i.id + ":   " + i.name);
                res++;
            }
        }
        if (res == 0) {
            System.out.println("NOT FOUND");
        } else {
            System.out.println(res + " results");
        }
    }

    public void sortTeacher() {
        ArrayList<GiaoVien> allGV = new ArrayList<>();
        allGV.addAll(tempTeacher);
        allGV.addAll(permaTeacher);
        allGV.sort(new Comparator<GiaoVien>() {
            @Override
            public int compare(GiaoVien o1, GiaoVien o2) {
                return (o1.multi > o2.multi) ? -1 : 1;
            }
        });
    }

    public void sumOfSalary() {
        float SUMSALARY = 0;
        GiaoVien tmp = new GiaoVien();
        for (GiaoVien x : permaTeacher) {
            SUMSALARY += x.salary;
        }
        for (GiaoVien x : tempTeacher) {
            SUMSALARY += x.salary;
        }
        System.out.println("TONG LUONG TAT CA GIAO VIEN = " + SUMSALARY);
        System.out.println("TRUNG BINH LUONG TAT CA GIAO VIEN = " + (SUMSALARY / (permaTeacher.size() + tempTeacher.size())));
    }

    public void mostPaidTeacher() {
        float MAXSALARY = 0;
        GiaoVien tmp = new GiaoVien();
        for (GiaoVien x : permaTeacher) {
            if (MAXSALARY < x.salary) {
                tmp = x;
                MAXSALARY = x.salary;
            }
        }
        for (GiaoVien x : tempTeacher) {
            if (MAXSALARY < x.salary) {
                tmp = x;
                MAXSALARY = x.salary;
            }
        }
        System.out.println("=".repeat(30));
        System.out.println("Giao vien co luong cao nhat: ");
        tmp.showInfo();
    }
}

public class Bai3 {

    public static void main(String[] args) {
        TeacherManager manager = new TeacherManager();
        System.out.println("Hello World!");
        manager.createTeacher();
        manager.showTeacher();
        manager.removeTeacher();
        manager.findTeacher();
        manager.sortTeacher();
        manager.sumOfSalary();
        manager.mostPaidTeacher();
    }
}
