public class Main
{
    public static void main(String args[])
    {
        Complex c1 = new Complex(1,2);
        Complex c2 = new Complex(1,2);

        ComplexOp.Add(c1,c2);

        ComplexOp.Multiply(c1,c2);
        ComplexOp.Divide(c1,c2);
    }
}
