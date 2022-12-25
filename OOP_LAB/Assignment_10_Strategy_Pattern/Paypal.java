package com.VishalEcommercesite;

import java.util.Scanner;

class Paypal implements Payment
{
    String PaypalID;
    String PaypalCode;

    Scanner sc = new Scanner(System.in);

    @Override
    public void payBill(double amount)
    {
        System.out.println("Rs "+amount+" are successfully debited from your paypal wallet ! ");

    }

    @Override
    public void displayPaymentInfo()
    {
        System.out.println("Paypal ID :- "+PaypalID);
        System.out.println("Paypal Code :- "+PaypalCode);
    }

    @Override
    public void setPaymentDetails()
    {
        System.out.println("Enter paypal ID ");
        PaypalID=sc.nextLine();
        System.out.println("Enter paypal code ");
        PaypalCode=sc.nextLine();


    }
}