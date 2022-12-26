package com.VishalBookPublication.application;

import java.util.HashMap;
import java.util.Map;

public class Store {
    public static HashMap<Integer,Book>BookStore = new HashMap<>();
    public static HashMap<Integer,Magazine>MagazineStore = new HashMap<>();

    public static void setStore()
    {
        Book b1 = new Book("Wings of fire","Abdul Kalam",300,2);
        Book b2 = new Book("Hind Swaraj","Mahatma Gandhi",200,2);
        BookStore.put(1,b1);
        BookStore.put(2,b2);

        Magazine m1 = new Magazine("Vision 360",300,3,"December 2022");
        Magazine m2 = new Magazine("Yojana",500,4,"December 2022");
        MagazineStore.put(1,m1);
        MagazineStore.put(2,m2);
    }

    public static void DisplayBooks()
    {
        for(Map.Entry<Integer,Book>entry : BookStore.entrySet())
        {
            System.out.println("Title  :- "+entry.getValue().getTitle());
            System.out.println("Author :- "+entry.getValue().getAuthor());
            System.out.println("Price  :- "+entry.getValue().getPrice());
            System.out.println("No of copies :- "+entry.getValue().getNoOfCopies());
            System.out.println("Book ID :- "+entry.getKey());
        }

    }

    public static void DisplayMagazine()
    {
       for (Map.Entry<Integer,Magazine>entry : MagazineStore.entrySet())
       {
           System.out.println("Title "+entry.getValue().getTitle());
           System.out.println("Current issue "+entry.getValue().getCurrentIssue());
           System.out.println("Price :- "+entry.getValue().getPrice());
           System.out.println("Magazine ID :-"+entry.getKey());
       }
    }
}
