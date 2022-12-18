package VishalCarfactory;

class Carfactory
{
    static Car car = null;

    public static Car Buildcar(Cartype model)
    {
       switch (model)
       {
           case SUV -> car= new SUV();
           case Sedan -> car = new Sedan();
           case Hachback -> car= new Hachback();

       }

       return car;


    }

}