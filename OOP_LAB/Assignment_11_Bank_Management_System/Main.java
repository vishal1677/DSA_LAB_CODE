package com.PICTBank.Services;

import java.util.Scanner;

public class Main
{
    static double validate(String AccNo)
    {
        double res=0;
       try {
          res=Double.parseDouble(AccNo);
       }
       catch (NumberFormatException e)
       {
           return 0;
       }

      return res;
    }
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int ch;
        do {
            System.out.println("Enter what you want ");
            System.out.println("1) Open account in bank ");
            System.out.println("2) Display all accounts ");
            System.out.println("3) Delete account ");
            System.out.println("4) Search account ");
            System.out.println("5) Deposit money");
            System.out.println("6) Withdraw money ");
            System.out.println("7) Exit ");
            ch=sc.nextInt();
            switch (ch)
            {
                case 1:
                    System.out.println("Enter your First Name ");
                    String fn;
                    fn=sc.next();
                    System.out.println("Enter your Last Name ");
                    String ln;
                    ln=sc.next();
                    System.out.println("Enter your initial account balance ");
                    String amount;
                    double amountd=0;
                    amount=sc.next();
                    if(validate(amount) != 0)
                    {
                        amountd=validate(amount);
                    }else {
                        System.out.println("Enter valid amount ");
                    }

                    Account acc = new Account(fn, ln,amountd);
                    Bank.OpenAccount(acc);
                       break;
                case 2:
                       Bank.DisplayAccount();
                       break;
                case 3:
                    System.out.println("Enter account number to delete ");
                    String accno=sc.next();
                    double accnod=0;
                    if(validate(accno) != 0)
                    {
                       accnod=validate(accno);
                    }
                    Bank.DeleteAccount(accnod);
                      break;
                case 4:
                    System.out.println("Enter account number to search");
                    double accNo=sc.nextDouble();
                    Bank.SearchAccount(accNo);
                      break;
                case 5:
                    System.out.println("Enter your account no");
                    double aNo=sc.nextDouble();
                    Bank.DepositMoney(aNo);

                      break;
                case 6:
                    System.out.println("Enter your account no");
                    double aNo1=sc.nextDouble();
                    Bank.WithdrawMoney(aNo1);
                      break;
                case 7:
                    System.out.println("finished");
                      break;

            }

        }while (ch != 7);

    }
}
