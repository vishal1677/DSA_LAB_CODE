import java.util.Arrays;
import java.util.Scanner;

public class Marks
{
   public static int arr[]= new int[5];
   public static Scanner sc = new Scanner(System.in);
    static float sum=0;

   public static boolean TakeMarksInput()
   {

       try {
           for(int i=0; i<5; i++)
           {
               System.out.println("Subject "+(i+1));
               String input;
               input=sc.next();
               int val =Integer.parseInt(input);
               if(val < 0)
               {
                   throw new NegativeMarks();
               }

               if(val > 100)
               {
                   throw  new MarksExceeded();
               }

               sum+=val;
           }

           return true;
       }catch (ArrayIndexOutOfBoundsException e)
       {
           System.out.println("Please enter marks for 5 subjects only ");
       }
       catch (NumberFormatException e)
       {
           System.out.println("Please enter valid marks ");
       }
       catch (NegativeMarks e)
       {
           System.out.println(e.getMessage());
       }
       catch (MarksExceeded e)
       {
           System.out.println(e.getMessage());
       }

    return false;
   }

   public static void CalculatePercentage( float totalMarks)
   {

       try {
          if(totalMarks <= 0)
          {
              throw new ArithmeticException();
          }

          if(sum > totalMarks)
          {
              throw  new MarksExceeded();
          }

          float res=(sum/totalMarks);
           System.out.println("Score :- "+res*100);
       }catch (ArithmeticException e)
       {
           System.out.println("Total marks can't be zero ");
       }
       catch (MarksExceeded e)
       {
           System.out.println(e.getMessage());
       }
   }

}
