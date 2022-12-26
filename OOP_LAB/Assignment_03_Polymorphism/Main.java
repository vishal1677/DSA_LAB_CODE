package com.VishalBookPublication.application;

import java.util.Scanner;

public class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int ch;
        do {
            System.out.println("Choose an option ");
            System.out.println("1) Login as a customer ");
            System.out.println("2) Login as a admin");
            System.out.println("3) Exit");
            ch=sc.nextInt();

            if(ch == 1)
            {
                int op;
                do {
                    System.out.println("Choose an option ");
                    System.out.println("1) Buy a book ");
                    System.out.println("2) Buy a magazine ");
                    System.out.println("3) Exit");
                    op=sc.nextInt();
                    if(op == 1)
                    {
                        Book.OrderCopies();
                        Book.saleCopy();
                    }
                    else if(op == 2)
                    {
                        Magazine.orderMagazine();
                        Magazine.saleCopy();
                    }

                }while (op != 3);

            }
            else if(ch == 2)
            {
                int op2=0;

                do {
                    System.out.println("1) Display revenue of publication ");
                    System.out.println("2) Display sale of publication ");
                    System.out.println("3) Exit");
                    op2 = sc.nextInt();
                    if (op2 == 1) {
                        Publication.getTotalSale();
                    } else if (op2 == 2) {
                        Publication.saleCopy();
                    }
                }while (op2 != 3);

            }

        }while (ch != 3);

    }
}
