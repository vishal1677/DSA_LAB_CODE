package VishalCarfactory;

import javax.xml.validation.Validator;
import java.util.*;
class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int ch;
        do
        {
            System.out.println("Welcome to  carFactory !");
            System.out.println("1) Initiate car ");
            System.out.println("2) Assemble Engine");
            System.out.println("3) Add tyres");
            System.out.println("4) Add steering ");
            System.out.println("5) Add suspension");
            System.out.println("6) Test car");
            System.out.println("7) Sell car");
            System.out.println("8) Exit");
            ch=sc.nextInt();
            switch (ch)
            {
                case 1:
                    System.out.println("Choose car model");
                    System.out.println("1) SUV ");
                    System.out.println("2) Hachback");
                    System.out.println("3) Sedan");
                    int opt=sc.nextInt();
                    if(opt == 1)
                    {
                        Carfactory.Buildcar(Cartype.SUV).initiateCar();
                    }
                    else if(opt == 2)
                    {
                        Carfactory.Buildcar(Cartype.Hachback).initiateCar();

                    }
                    else if(opt == 3)
                    {
                        Carfactory.Buildcar(Cartype.Sedan).initiateCar();

                    }

                       break;
                case 2: // Similary U can implement other part too its easy though 
                       break;
                case 3:
                       break;
            }

        }while(ch != 8);


    }

}