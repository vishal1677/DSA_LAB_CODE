package com.VishalBookPublication.application;

public class Publication {
    protected String title;
    protected double price;
    protected double NoOfCopies;

    protected static double BookSale;
    protected static double MagazineSale;
    protected static double BookQty;
    protected static double MagazineQty;


    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public double getNoOfCopies() {
        return NoOfCopies;
    }

    public void setNoOfCopies(double noOfCopies) {
        NoOfCopies = noOfCopies;
    }

     public static void getTotalSale()
     {
         System.out.println("Total book sale :- "+BookSale);
         System.out.println("Total magazine sale :- "+MagazineSale);
         System.out.println("Total revenue of publication :- "+(BookSale+MagazineSale));
     }

    public static void saleCopy()
    {
        System.out.println("Numbers of books sold "+BookQty);
        System.out.println("Number of magazine sold "+MagazineQty);
        System.out.println("Total copies sold by publication :- "+(BookQty+MagazineQty));

    }


}
