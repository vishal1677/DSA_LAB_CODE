public class Rectangle extends Shape
{
    @Override
    void setBreadth(double b) {
        breadth=b;
    }

    @Override
    void setLength(double l) {
        length=l;
    }

    @Override
    double ComputeArea() {
        return length*breadth;

    }

    @Override
    void draw() {
        System.out.println("Drawing rectangle ");
    }
}
