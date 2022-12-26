import java.util.*;
interface Vehicle
{

    public void speedUp(int a);
    public void changeGear(int b);
    public void applyBreak(int c);
}

class Bicycle implements Vehicle
{
    int speed,brk,gear;
    Bicycle(int s, int b, int g)
    {
        speed=s;
        brk=b;
        gear=g;
    }

    @Override
    public void speedUp(int a)
    {
        speed+=a;
        System.out.println("The speed of Bicycle is "+speed);
    }

    @Override
    public void changeGear(int b) {
        brk=b;
        System.out.println("The current gear of Bicycle is "+b);
    }

    @Override
    public void applyBreak(int c) {
        brk=c;
        if(c==1)
        {
            System.out.println("Break applied ");
        }
        else
        {
            System.out.println("Break not applied");
        }
    }
}

class Car implements Vehicle
{
    int speed,brk,gear;
    Car(int s, int b, int g)
    {
      speed=s;
      brk=b;
      gear=g;
    }
    @Override
    public void speedUp(int a)
    {
        speed+=a;
        System.out.println("The speed of car is "+speed);
    }

    @Override
    public void changeGear(int b)
    {
        gear=b;
        System.out.println("The current gear of car is "+b);

    }

    @Override
    public void applyBreak(int c)
    {
        brk=c;
        if(c== 1)
        {
            System.out.println("Break applied");
        }
        else
        {
            System.out.println("Break not applied");
        }
    }
}

class Bike implements Vehicle
{
    int speed,brk,gear;
    Bike(int s, int b, int g)
    {
        speed=s;
        brk=b;
        gear=g;
    }
    @Override
    public void speedUp(int a)
    {
        speed+=a;
        System.out.println("THe current speed of bike is "+speed);

    }

    @Override
    public void changeGear(int b)
    {
        gear=b;
        System.out.println("The current gear of bike is "+b);
    }

    @Override
    public void applyBreak(int c)
    {
        brk=c;
        if(c== 1)
        {
            System.out.println("Break apllied");
        }
        else
        {
            System.out.println("Break not applied");
        }
    }
}