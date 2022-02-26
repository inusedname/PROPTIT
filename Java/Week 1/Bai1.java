/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.helloworld;

import java.util.Scanner;

/**
 *
 * @author inusedname
 */
public class Bai1 {

    static public boolean isThuanNghich(char[] str) {
        for (int i = 0; i < str.length; i++) {
            if (str[i] != str[str.length - i - 1]) {
                return false;
            }
        }
        return true;
    }

    static public boolean isEvenNumber(char[] str) {
        for (int i = 0; i < str.length; i++) {
            if ((int) Character.getNumericValue(str[i]) % 2 == 1) {
                return false;
            }
        }
        return true;
    }

    static public boolean isEightAndDivisibleTo10(char[] str) {
        if (str[0] != '8' && str[str.length - 1] != '8') {
            return false;
        }
        int sum = 0;
        for (int i = 0; i < str.length; i++) {
            sum += (int) Character.getNumericValue(str[i]);
        }
        return sum % 10 == 0;
    }

    static public boolean isPrime(int x) {
        if (x < 2) {
            return false;
        }
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

    static public boolean isStringPrime(char[] str) {
        for (int i = 0; i < str.length; i++) {
            if (!isPrime(Character.getNumericValue(str[i]))) {
                return false;
            }
        }
        return true;
    }

    static public void main(String[] args) {
        System.out.println("Nhap chuoi: ");
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        char[] strtoChar = str.toCharArray();
        if (isThuanNghich(strtoChar) && isEvenNumber(strtoChar)) {
            System.out.println("So dep");
        } else {
            System.out.println("So khong dep");
        }
        // isThuanNghich(strtoChar) && isEvenNumber(strtoChar)
        // 4224 4226 3223
        // isThuanNghich(strtoChar) && isEightAndDivisibleTo10(strtoChar)
        // 8228 8246 8338
        // isThuanNghich(strtoChar) && isStringPrime(strtoChar)
        // 7337 7447 2357
    }
}
