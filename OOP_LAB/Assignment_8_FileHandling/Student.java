import javax.lang.model.element.Name;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;

class Student
{
    private String RollNo;
    private String name;
    private String marks;
    private String address;

    Student(String RollNo, String name,String marks,String address)
    {
        this.RollNo=RollNo;
        this.name=name;
        this.marks=marks;
        this.address=address;
    }
    public String getRollNo(){ return  RollNo;}
    public String getName(){ return name;}
    public String getMarks(){ return marks;}
    public String getAddress(){ return  address;}

    public void writeInRecord(PrintWriter pw)
    {
        pw.println(RollNo+","+name+","+marks+","+address);
    }
    public  static void printInfo(String s)
    {
        String token[]=s.split(",");
        System.out.println("Roll No :- "+token[0]);
        System.out.println("Name    :- "+token[1]);
        System.out.println("Marks   :- "+token[2]);
        System.out.println("Address :- "+token[3]);
    }
    public static void readFromFile(BufferedReader br)
    {
        String s="";
        try {
             s = br.readLine();
             while(s != null)
             {
                 printInfo(s);
                 s=br.readLine();
             }
        }catch (IOException e)
        {
            System.out.println(e.getMessage());
        }

    }

}