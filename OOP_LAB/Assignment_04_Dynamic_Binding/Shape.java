abstract class Shape
{
    double length,breadth;
    abstract double ComputeArea();
    abstract void setLength(double l);
    abstract void setBreadth(double b);

    abstract void draw();
    void perimeter()
    {
        System.out.println(length+breadth);
    }



}
