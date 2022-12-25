public class ComplexOp {

    public static void Add(Complex c1, Complex c2)
    {
        Complex c3 = new Complex();

        c3.real=c1.real+c2.real;
        c3.img=c1.img+c2.img;
        c3.Print();
    }

    public static void Multiply(Complex c1, Complex c2)
    {
        Complex c3= new Complex();

        c3.real=c1.real*c2.real-c1.img*c2.img;
        c3.img=c1.real*c2.img+c1.img*c2.real;
        c1.Print();
        c2.Print();
        c3.Print();

    }

    public static void Divide(Complex c1 , Complex c2)
    {
        float div=c2.real*c2.real + c2.img*c2.img;
        Complex c3= new Complex();

        c3.real=(c1.real*c2.real+c1.img*c2.img)/div;
        c3.img=(c1.img*c2.real- c1.real*c2.img);
        c1.Print();
        c2.Print();
        c3.Print();

    }
}
