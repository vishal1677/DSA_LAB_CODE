package com.PICTBank.Services;

public class Account
{
    Double AccNo;
    String FirstName;
    String LastName;
    double AccBalance;
    static double AccCount=0;


    Account( String FirstName, String LastName, double AccBalance)
    {
        AccCount++;
        AccNo=AccCount;
        this.FirstName=FirstName;
        this.LastName=LastName;
        this.AccBalance=AccBalance;

    }

    Double getAccNo(){ return AccNo; }
    String getFirstName(){ return FirstName ;}
    String getLastName(){ return  LastName; }
    double getAccBalance(){ return  AccBalance; }
    void setAccBalance(double AccBalance)
    {
        this.AccBalance=AccBalance;
    }
    public void getAccInfo()
    {
        System.out.println("Name :- "+FirstName+" "+LastName);
        System.out.println("Account No :- "+AccNo);
        System.out.println("Account Balance :- "+AccBalance);
    }

}
