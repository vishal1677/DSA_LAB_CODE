import java.util.Scanner;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int ch;
      do {
          System.out.println("1) Add record to database");
          System.out.println("2) Display all records to database");
          System.out.println("3) Search a record in database");
          System.out.println("4) Delete a record");
          System.out.println("5) Update a record");
          System.out.println("6) Exit");
          ch=sc.nextInt();
          switch (ch)
          {
              case 1:
                     Database.addRecord();
                     break;
              case 2:
                     Database.displayRecord();
                     break;
              case 3:
                  String key="";
                  do {
                      System.out.println("Enter Roll No to search");
                      key = sc.next();
                      if(Database.validateRollNo(key)){
                          break;
                      }
                      else {
                          System.out.println("Enter valid Roll No");
                      }

                  }while (true);
                  Database.searchRecord(key);
                  break;
              case 4:
                  String key1="";
                  do {
                      System.out.println("Enter Roll No to delete");
                      key1 = sc.next();
                      if(Database.validateRollNo(key1)){
                          break;
                      }
                      else{
                          System.out.println("Enter valid Roll No");
                      }

                  }while (true);
                  Database.deleteRecord(key1);
                  break;
              case 5:
                  String key2="";
                  do {
                      System.out.println("Enter Roll No to update");
                      key2 = sc.next();
                      if(Database.validateRollNo(key2)){
                          break;
                      }
                      else{
                          System.out.println("Enter valid Roll No");
                      }

                  }while (true);
                  Database.deleteRecord(key2);




          }

      }while (ch != 6);


    }
}