package com.VishalEcommercesite;

import java.util.ArrayList;
import java.util.Scanner;

class Shopping
{
    static Scanner sc = new Scanner(System.in);
    static ArrayList<Integer>ID = new ArrayList<>();

    static void shoppingCart()
    {
        Shop.addItems();
        Shop.displayItems();
    }

    static void addToCart()
    {
        Shop.displayItems();
        System.out.println("How many items you want to buy ? ");
        int ch=sc.nextInt();

        for(int i=0; i<ch; i++)
        {
            System.out.println("Choose the item ID's which want to add to cart");
            ID.add(sc.nextInt());
        }
    }

    static void RemoveFromCart()
    {
        ID.clear();
    }

    static void paymentGateway(double billAmount)
    {
        System.out.println("Choose the payment option ");
        int ch;
        System.out.println("1) Paypal ");
        System.out.println("2) Bitcoin ");
        System.out.println("3) Credit card ");
        Payment p =null;
        ch =sc.nextInt();

        if(ch == 1)
        {
            p= new Paypal();

        }
        else if(ch == 2)
        {
            p=new Bitcoin();

        }
        else if(ch == 3)
        {
            p= new CreditCard();
        }
        p.setPaymentDetails();
        p.displayPaymentInfo();
        System.out.println("Initiating payment ");
        p.payBill(billAmount);
        RemoveFromCart();
    }

    static void flashDeal()
    {
        System.out.println("These are the items that you selected ");
        double billAmount=0;

       for(int i=0; i<ID.size(); i++)
       {
           System.out.println("Name  :- "+Shop.products.get(ID.get(i)).name);
           System.out.println("Price :- "+Shop.products.get(ID.get(i)).price);
           billAmount+=Shop.products.get(ID.get(i)).price;

       }
        System.out.println("Initiating payment gateway");
        paymentGateway(billAmount);

    }


}