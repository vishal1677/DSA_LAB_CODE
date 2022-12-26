import java.util.Scanner;

public class Driver
{
    public static void DriveVehicle(Vehicle vehicle)
    {
        Scanner sc = new Scanner(System.in);

        int c3;
        do{
            System.out.println("Choose what do you want ");
            System.out.println("1) Increase speed");
            System.out.println("2) Change gear ");
            System.out.println("3) Apply break ");
            System.out.println("4) Exit the program");
            c3=sc.nextInt();
            if(c3 == 1)
            {
                System.out.println("Enter spped ");
                int sp=sc.nextInt();
                vehicle.speedUp(sp);
            }
            else if (c3 == 2)
            {
                System.out.println("Enter gear from 1 to 4");
                int g2=sc.nextInt();
                vehicle.changeGear(g2);
            }
            else if (c3== 3)
            {
                vehicle.applyBreak(1);

            }
            else if (c3 == 4)
            {
                System.out.println("Program finished");
            }
        }while (c3 != 4);
    }
}
