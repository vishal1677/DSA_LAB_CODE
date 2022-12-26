import java.util.ArrayList;
import java.util.Scanner;

public class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter size of integer collection ");
        int n=sc.nextInt();
        ArrayList<Integer>arr = new ArrayList<>();

        for(int i=0; i<n; i++)
        {
            System.out.println("Enter number ");
            String input =sc.next();
            try {
                int val=Integer.parseInt(input);
                arr.add(val);
            }catch (NumberFormatException e)
            {
                System.out.println("Enter valid number ");
            }
        }
        Prime p1 = new Prime();
        Even e1 = new Even();
        Odd o1 = new Odd();

        System.out.println("Prime numbers "+Counting.Count(arr,p1));
        System.out.println("Even numbers "+Counting.Count(arr,e1));
        System.out.println("Odd numbers "+Counting.Count(arr,o1));

        System.out.println("Enter size of string collection ");
        int sz=sc.nextInt();
        ArrayList<String>strarr = new ArrayList<>();

        for(int i=0; i<sz; i++)
        {
            strarr.add(sc.next());
        }
        Palindrome pm = new Palindrome();

        System.out.println("Number of palindrome "+Counting.Count(strarr,pm));

    }
}
