package com.VishalEcommercesite;

import java.util.Scanner;

class Main
{
    public static void main(String  args[])
    {
        int ch;
        Scanner sc = new Scanner(System.in);

        do {
            System.out.println("What you want to do ");
            System.out.println("1) Explore the items in shop ");
            System.out.println("2) Add items to cart ");
            System.out.println("3) See the cart and pay bill");
            System.out.println("4) Exit");
            ch=sc.nextInt();

            if(ch == 1)
            {
               Shopping.shoppingCart();

            }
            else if(ch == 2)
            {
                Shopping.addToCart();
            }
            else if(ch == 3)
            {
                Shopping.flashDeal();
            }


        }while (ch != 4);




    }

}