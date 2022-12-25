import java.util.Scanner;

public class Main
{
    public static void main(String args[])
    {
        int ch;
        Scanner sc = new Scanner(System.in);

        System.out.println("Choose your employee type to generate salary slip ");
        System.out.println("1) Programmer");
        System.out.println("2) Team Lead");
        System.out.println("3) Assistent Project Manager");
        System.out.println("4) Project Manager");
        ch=sc.nextInt();

        if(ch == 1)
        {
            Programmer p = new Programmer();
            p.setBasicPay(120000);
            p.getEmployeeDetails();
            p.GeneratePayslip(p.getBasicPay()); // similarly generate basic pay for others

        }
        else if(ch == 2)
        {

        }
        else if(ch == 3)
        {

        }
        else if(ch == 4)
        {

        }
        // add validations to mobile no email id name basic pay
        

    }
}
