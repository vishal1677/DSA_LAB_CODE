package com.VishalEcommercesite;

import java.util.Scanner;

class Bitcoin implements Payment
{
    String MetamaskID;
    String TradingPlatform;

    Scanner sc = new Scanner(System.in);

    @Override
    public void payBill(double amount)
    {
        System.out.println(amount+" matic coins are successfully debited from your metamask bitcoin wallet");
    }

    @Override
    public void displayPaymentInfo()
    {
        System.out.println("MataMaskID :- "+MetamaskID);
        System.out.println("Trading Platform "+TradingPlatform);

    }

    @Override
    public void setPaymentDetails()
    {
        System.out.println("Enter metamask ID");
        MetamaskID=sc.next();
        System.out.println("Enter trading platform");
        TradingPlatform=sc.next();

    }
}