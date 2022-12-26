import java.util.*;
class Main
{

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int c1,c2;
       do {
           System.out.println("Enter your choise:- ");
           System.out.println("1) Choose a vehicle:- ");
           System.out.println("2) Exit:-");
           c1=sc.nextInt();
           if(c1 == 1)
           {
               do {
                   System.out.println("Choose :- ");
                   System.out.println("1) Bicycle ");
                   System.out.println("2) Bike ");
                   System.out.println("3) Car ");
                   System.out.println("4) Exit");
                   c2=sc.nextInt();
               if(c2 == 1)
               {
                   System.out.println("Enter initial speed");
                   int speed=sc.nextInt();
                   int brk=0;
                   System.out.println("Enter initial gear");
                   int gear=sc.nextInt();
                   Driver.DriveVehicle(VehicleBuilder.BuildVehicle(1,gear,speed));

               }
               else if( c2 == 2)
               {
                   System.out.println("Enter initial speed");
                   int speed=sc.nextInt();
                   int brk=0;
                   System.out.println("Enter initial gear");
                   int gear=sc.nextInt();
                   Driver.DriveVehicle(VehicleBuilder.BuildVehicle(2,gear,speed));
               }
               else if (c2 == 3)
               {
                   System.out.println("Enter initial speed");
                   int speed=sc.nextInt();
                   int brk=0;
                   System.out.println("Enter initial gear");
                   int gear=sc.nextInt();
                   Driver.DriveVehicle(VehicleBuilder.BuildVehicle(3,gear,speed));


               } else if (c2 == 4) {
                   System.out.println("Program finished");
               }
               else
               {
                   System.out.println("Enter correct choice:- ");
               }


               }while (c2 != 4);

           }
           else if( c1== 2)
           {
               System.out.println("Program finished");
           }
           else
           {
               System.out.println("Enter correct choise ");
           }

       }while (c1 != 2);
    }
}