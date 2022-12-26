package com.VishalBookPublication.application;

import java.util.ArrayList;
import java.util.Scanner;

public class Magazine extends Publication{
 private String currentIssue;
 private double orderQty;
 public static ArrayList<Integer> ID = new ArrayList<>();

 public static Scanner sc = new Scanner(System.in);


    Magazine(String title, double price, double NoOfCopies, String currentIssue)
    {
        super.title=title;
        super.price=price;
        super.NoOfCopies=NoOfCopies;
        this.currentIssue=currentIssue;
    }

    public double getOrderQty() {
        return orderQty;
    }

    public void setOrderQty(double orderQty) {
        this.orderQty = orderQty;
    }

    public String getCurrentIssue() {
        return currentIssue;
    }

    public void setCurrentIssue(String currentIssue) {
        this.currentIssue = currentIssue;
    }

    public static void orderMagazine()
    {
        Store.setStore();
        Store.DisplayMagazine();
        System.out.println("Enter how many magazine you want to buy ");
        int n=sc.nextInt();
        for(int i=0; i<n; i++)
        {
            System.out.println("Enter a magazine ID");
            ID.add(sc.nextInt());
        }

    }

    public static void saleCopy() {
        double customerBill=0;

        for (int i=0 ; i<ID.size(); i++)
        {
            MagazineQty++;
            customerBill+= Store.MagazineStore.get(ID.get(i)).getPrice();
        }
        MagazineSale+=customerBill;

        System.out.println("Total bill :- "+customerBill );
        System.out.println("Your order will be shipped within 24 hours ");
        ID.clear();

    }
}
