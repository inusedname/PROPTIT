/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.helloworld;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/**
 *
 * @author inusedname
 */
class Member {

    private String name;

    public String getName() {
        return name;
    }

    public Member(String name) {
        this.name = name;
    }

}

public class Test {

    public static void main(String[] args) {
        List<Member> myList = new ArrayList<>();
        myList.add(new Member("Hi"));
        myList.add(new Member("Xin chao"));
        myList.add(new Member("Konichiwa"));
        myList.add(new Member("Bonjour"));
        Collections.sort(myList, Comparator.comparing(Member::getName, (x1, x2) -> {
            return x2.compareTo(x1);
        }));
        for (Member x : myList) {
            System.out.println(x.getName());
        }
//      Xin chao
//      Konichiwa
//      Hi
//      Bonjour
    }
}
