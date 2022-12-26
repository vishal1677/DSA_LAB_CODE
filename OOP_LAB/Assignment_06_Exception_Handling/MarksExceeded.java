public class MarksExceeded extends Exception
{
    @Override
    public String getMessage() {
        return "Total marks can't be grater than agreagrate marks";
    }
}
