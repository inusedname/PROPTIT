/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.helloworld;

import java.util.Scanner;
import java.util.regex.Pattern;

/**
 *
 * @author inusedname
 */
public class Bai2 {

    public static String yMot(String str) {
        String[] splited = str.trim().split("\\s+");
        for (int x = 0; x < splited.length; x++) {
            char[] tmp = splited[x].toLowerCase().toCharArray();
            tmp[0] = Character.toUpperCase(tmp[0]);
            splited[x] = String.valueOf(tmp);
        }
        return String.join(" ", splited);

    }

    public static String yHai(String str) {
        String[] splited = str.trim().split("\\s+");
        splited[0] = splited[0].toUpperCase();
        for (int x = 1; x < splited.length; x++) {
            char[] tmp = splited[x].toLowerCase().toCharArray();
            tmp[0] = Character.toUpperCase(tmp[0]);
            splited[x] = String.valueOf(tmp);
        }
        String res = "";
        for (int i = 1; i < splited.length - 1; i++) {
            res += splited[i] + " ";
        }
        return res + splited[splited.length - 1] + ", " + splited[0];
    }

    public static String yBa(String str) {
        String[] splited = str.trim().split("\\s+");
        for (int x = 0; x < splited.length; x++) {
            splited[x] = splited[x].toLowerCase();
        }
        String res = splited[splited.length - 1];
        for (int i = 0; i < splited.length - 1; i++) {
            res += splited[i].substring(0, 1);
        }
        return res + "@ptit.edu.vn";

    }

    public static void upperTheFirst(String[] splited, int index) {
        char first = Character.toUpperCase(splited[index].charAt(0));
        splited[index] = String.valueOf(first + splited[index].substring(1));
    }

    public static String yBon(String str) {
        String[] splited = str.trim().split("\\s+");
        for (int x = 0; x < splited.length; x++) {
            splited[x] = splited[x].toLowerCase();
        }
        upperTheFirst(splited, 0);
        String res = splited[0];
        Pattern pattern = Pattern.compile("[\\!\\?\\.;]");
        for (int i = 1; i < splited.length; i++) {
            String findRegex[] = pattern.split(splited[i]);
            if (findRegex.length == 0) {
                res += splited[i];
                if (i != splited.length - 1) {
                    upperTheFirst(splited, i + 1);
                }
            }
            if (findRegex.length == 1) {
                res += " " + splited[i];
            }
            if (findRegex.length == 2) {
                res += " " + splited[i].substring(0, findRegex[0].length() + 1) + " ";
                upperTheFirst(findRegex, 1);
                res += findRegex[1];
            }
        }
        return res;
    }

    public static void main(String[] args) {
        System.out.println("Nhap xau: ");
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        String standardrized = yBon(str);
        System.out.println(standardrized);
    }
}
