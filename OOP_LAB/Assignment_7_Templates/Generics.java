import java.util.List;

interface Generics <T>
{
  boolean match(T t);

}
class Prime implements Generics<Integer>
{
    @Override
    public boolean match(Integer integer) {
     if(integer <=1){
         return false;
     }

     if(integer <= 3)
     {
         return true;
     }

     if(integer%2 == 0 || integer%3 == 0)
     {
         return false;
     }

     for(int i=5; i*i<=integer;i+=6 )
     {
         if(integer%i == 0)
         {
             return false;
         }
     }
    return true;

    }
}

class Odd implements Generics<Integer>
{
    @Override
    public boolean match(Integer integer) {
        if(integer%2 == 1)
        {
            return true;
        }
      return false;
    }
}

class Even implements Generics<Integer>
{
    @Override
    public boolean match(Integer integer) {
        if(integer%2 == 0)
        {
            return true;
        }
      return false;
    }
}

class Palindrome implements  Generics<String>
{
    @Override
    public boolean match(String s) {
        int i=0;
        int j=s.length()-1;

        while (i<j)
        {
            if(s.charAt(i) != s.charAt(j))
            {
                return false;
            }
            i++;
            j--;

        }

     return true;
    }
}

class Counting
{
   public static <T> int Count(List<T>list , Generics<T> gn)
   {
       int count=0;
       for(int i=0; i<list.size(); i++)
       {
           if(gn.match(list.get(i)))
           {
               count++;
           }
       }
      return count;
   }

}




