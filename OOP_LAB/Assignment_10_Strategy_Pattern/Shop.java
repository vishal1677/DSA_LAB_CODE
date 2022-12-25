package com.VishalEcommercesite;


import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

class Shop
{
    static HashMap<Integer,Item>products = new HashMap<>();


    public static void addItems()
    {
        Item i1 = new Item("Dell Laptop", 45000);
        Item i2 = new Item( "Ipad", 10000);
        products.put(1,i1);
        products.put(2,i2);
    }

    public static void displayItems()
    {
        for(Map.Entry<Integer,Item> entry : products.entrySet())
        {
            System.out.println("Name  :- "+entry.getValue().name);
            System.out.println("Price :- "+entry.getValue().price);
            System.out.println("ID    :- "+entry.getKey());

        }


    }



}