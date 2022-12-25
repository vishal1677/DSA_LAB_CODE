package com.PICTBank.Services;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Bank
{
    static HashMap<Double,Account>Records = new HashMap<>();
    static Scanner sc = new Scanner(System.in);

    public static void OpenAccount(Account acc)
    {
        Records.put(acc.getAccNo(),acc);
        System.out.println("Account created successfully !");
    }

    public static void DepositMoney(double AccNo)
    {
        double Amount=0;

        try {
            System.out.println("Enter amount that you want to deposit ");
             Amount = sc.nextDouble();

            if (Amount > 100000) {
                throw new DepositLimitExceeded();
            }
        }catch (DepositLimitExceeded e)
        {
            System.out.println(e.getMessage());

        }
        Account acc=Records.get(AccNo);
        if(acc != null)
        {
            acc.setAccBalance(acc.getAccBalance()+Amount);
            Records.put(acc.getAccNo(),acc);

        }
        else
        {
            System.out.println("Account Number not found in records");
        }

    }
    public static void WithdrawMoney(double AccNo)
    {
       Account acc=Records.get(AccNo);
       if( acc != null)
       {
           double amount=0;

           try{
               amount=sc.nextDouble();
               if(acc.getAccBalance() < amount)
               {
                   throw new InsufficientBalance();
               }
               else if(amount > 100000)
               {
                   throw new WithdrawLimitExceeded();
               }
           }
           catch (InsufficientBalance e)
           {
               System.out.println(e.getMessage());
               return;
           }
           catch (WithdrawLimitExceeded e)
           {
               System.out.println(e.getMessage());
               return;
           }

        acc.setAccBalance(acc.getAccBalance()-amount);
        Records.put(acc.getAccNo(),acc);

       }
       else
       {
           System.out.println("Account No not found in records ");
       }

    }
    public static void CheckBalance(Double AccNo)
    {
        Account acc = Records.get(AccNo);
        System.out.println("Your current account balance is :- ");
        acc.getAccBalance();
    }
    public static void DisplayAccount()
    {
        for(Map.Entry<Double,Account> entry: Records.entrySet())
        {
            entry.getValue().getAccInfo();
        }
    }
    public static void DeleteAccount(Double AccNo)
    {
        Records.remove(AccNo);
    }

    public static void SearchAccount(Double AccNo)
    {
       Account acc = Records.get(AccNo);
       if(acc != null)
       {
           acc.getAccInfo();
       }
    }



}
