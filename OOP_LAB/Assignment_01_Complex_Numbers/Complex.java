public class Complex
{
    float real;
    float img;
    Complex()
    {
        real=0;
        img=0;
    }

    Complex(float real, float img)
    {
        this.real=real;
        this.img=img;
    }

    void Print()
    {
        if(img == 0)
        {
            System.out.println(real);
        }
        else
        {
            System.out.println(real+" + "+img+"i");
        }
    }

    float getReal(){ return real; }
    float getImg(){ return img; }

}
