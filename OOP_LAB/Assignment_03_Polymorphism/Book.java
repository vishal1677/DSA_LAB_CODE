package com.VishalBookPublication.application;

import java.util.ArrayList;
import java.util.Scanner;

public class Book extends Publication {
    private String author;
    static Scanner sc = new Scanner(System.in);


    public static ArrayList<Integer>ID = new ArrayList<>();


    Book(String title , String author, double price , double NoOfCopies)
    {
        super.title=title;
        this.author=author;
        super.price=price;
        super.NoOfCopies=NoOfCopies;

    }

    public String getAuthor() {
        return author;
    }


    public static void OrderCopies()
    {
        Store.setStore();
        Store.DisplayBooks();
        System.out.println("Enter how many books you want to buy ");
        int n=sc.nextInt();
        for(int i=0; i<n; i++)
        {
            System.out.println("Enter a book ID");
            ID.add(sc.nextInt());
        }

    }


    public static void saleCopy() {
        double customerBill=0;

        for (int i=0 ; i<ID.size(); i++)
        {
            BookQty++;
            customerBill+= Store.BookStore.get(ID.get(i)).getPrice();
        }
        BookSale+=customerBill;

        System.out.println("Total bill :- "+customerBill );
        System.out.println("Your order will be shipped within 24 hours ");
        ID.clear();
    }
}
