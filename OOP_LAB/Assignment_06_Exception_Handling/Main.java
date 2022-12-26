import java.util.Scanner;

public class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        System.out.println("Please enter the marks for 5 Subjects ");
        boolean res=Marks.TakeMarksInput();
        if(res) {
            System.out.println("Enter agregate marks ");
            float marks=sc.nextInt();
            Marks.CalculatePercentage(marks);
        }
        else{
            System.out.println("try again ");
        }



    }
}
