import jdk.security.jarsigner.JarSigner;

import javax.sound.midi.Soundbank;
import java.io.*;
import java.util.Locale;
import java.util.Scanner;

class Database
{
   private static File file = new File("data.txt");
   public static Scanner sc = new Scanner(System.in);

   public static void addRecord()
   {
       PrintWriter pw =null;

       try {
           pw = new PrintWriter(new BufferedWriter(new FileWriter(file,true)));
           System.out.println("Enter your RollNo ");
           String rn=sc.nextLine();
           System.out.println("Enter your Name ");
           String name=sc.nextLine();
           System.out.println("Enter your marks");
           String marks=sc.nextLine();
           System.out.println("Enter your address");
           String add=sc.nextLine();
           Student s1 = new Student(rn,name,marks,add);
           s1.writeInRecord(pw);

       }
       catch (IOException e)
       {
           System.out.println(e.getMessage());
       }
       finally {
           pw.close();
       }
   }
   public static void  displayRecord()
   {
       BufferedReader br = null;
       try {
            br = new BufferedReader(new FileReader(file));
           Student.readFromFile(br);
       }
       catch (FileNotFoundException e)
       {
           System.out.println(e.getMessage());
       }
       finally {
           try {
               br.close();
           }
           catch (IOException e)
           {
               System.out.println(e.getMessage());
           }
       }
   }

   public static void deleteRecord(String key)
   {
       File newfile = new File("new.txt");
       BufferedReader br = null;
       PrintWriter pw = null;
       try{
           br=new BufferedReader(new FileReader(file));
           pw = new PrintWriter(new FileWriter(newfile));
           String s=br.readLine();
           while (s != null)
           {
               String token[]=s.split(",");
               if(!token[0].equals(key))
               {
                   pw.println(s);
               }
               s=br.readLine();
           }
       }catch (IOException e)
       {
           System.out.println(e.getMessage());
       }
       finally {
           try {
               br.close();
               pw.close();
           }
           catch (IOException e)
           {
               System.out.println(e.getMessage());
           }

       }
       file.delete();
       newfile.renameTo(file);


   }

   public static void updateRecord(String key)
   {
       System.out.println("Enter what you want to update");
       System.out.println("1) RollNo ");
       System.out.println("2) Name ");
       System.out.println("3) Marks");
       System.out.println("4) Address");
       int ch=sc.nextInt();
       ch-=1;

       System.out.println("Enter modified value");
       String modifyKey;
       modifyKey=sc.next();

       if(ch > 4 || ch<0)
       {
           System.out.println("Invalid input");
           return;
       }

       BufferedReader br = null;
       PrintWriter pw = null;
       File newfile = new File("new.txt");

       try
       {
         br = new BufferedReader( new FileReader(file));
         pw = new PrintWriter(new BufferedWriter(new FileWriter(newfile)));
         String s= br.readLine();
         while (s != null)
         {
             String token[]=s.split(",");
             if(token[0].equals(key))
             {
                token[ch]=modifyKey;
                String newkey =token[0]+","+token[1]+","+token[2]+","+token[3];
                pw.println(newkey);
                s= br.readLine();
                continue;
             }

             pw.println(s);
             s= br.readLine();
         }

       }catch (IOException e)
       {
           System.out.println(e.getMessage());
       }

       try {
           br.close();
           pw.close();
       }catch (IOException e)
       {
           e.getMessage();
       }
       file.delete();
       newfile.renameTo(file);

   }
   public static void searchRecord(String key)
   {
       BufferedReader br = null;
       boolean flag = true;

       try {
           br = new BufferedReader(new FileReader(file));
           String s=br.readLine();
           while(s != null)
           {
               String token[] = s.split(",");
               if(token[0].equals(key))
               {
                   System.out.println("Student found in record");
                   Student.printInfo(s);
                   flag=false;
                   break;
               }
               s= br.readLine();
           }
           if(flag){
               System.out.println("Student not found in record");
           }

       }catch (IOException e)
       {
           System.out.println(e.getMessage());
       }

   }
   public static boolean validateRollNo(String key)
   {
       try {
           double val = Double.parseDouble(key);
           if(val>0)
           {
               return true;
           }


       }catch (NumberFormatException e)
       {
           System.out.println("Please enter valid Roll No");
       }
       return false;
   }


}