package com.VishalEcommercesite;

import javax.security.sasl.SaslClient;
import java.util.Scanner;

class CreditCard implements Payment
{

    String CardName;
    String CardNo;
    String ExpiryDate;
    String cvv;

    Scanner sc = new Scanner(System.in);

    @Override
    public void payBill(double amount)
    {
        System.out.println("Rs "+amount+" are successfully debited from your bank account");
    }

    @Override
    public void displayPaymentInfo()
    {
        System.out.println("CardName "+CardName);
        System.out.println("CardNo "+CardNo);
        System.out.println("ExpiryDate "+ExpiryDate);
        System.out.println("CVV "+cvv);

    }

    @Override
    public void setPaymentDetails()
    {
        System.out.println("Enter card Name");
        CardName=sc.next();

    }
}