/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package com.mycompany.helloworld;

/**
 *
 * @author inusedname
 */
class Animal {

    public void Eat() {
        System.out.println("Eating...");
    }

    public void Move() {
        System.out.println("Moving...");
    }
}

class Bird extends Animal {

    @Override
    public void Eat() {
        System.out.println("Bird is Eating...");
    }

    @Override
    public void Move() {
        System.out.println("Bird is Moving...");
    }

    public void Dicu() {
        System.out.println("Di cu-ing");
    }
}

class Cat extends Animal {

    public String owner;

    Cat() {
        owner = "Nguyen Van A";
    }

    @Override
    public void Eat() {
        System.out.println("Cat is Eating...");
    }

    @Override
    public void Move() {
        System.out.println("Cat is Moving...");
    }

}

public class SchoolWork1 {

    public static void main(String[] args) {
        Animal aBird = new Bird();
        Cat aCat = new Cat();
        aBird.Move();
        aCat.Move();
        System.out.println(aCat.owner);
    }
}
