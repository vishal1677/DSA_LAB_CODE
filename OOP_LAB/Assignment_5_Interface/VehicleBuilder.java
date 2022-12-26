public class VehicleBuilder
{
    public static Vehicle BuildVehicle(int choice,int gear, int speed)
    {
        Vehicle vehicle = null;

        if(choice == 1)
        {
            vehicle=new Bicycle(speed,0,gear);
        }
        else if(choice == 2)
        {
            vehicle=new Bike(speed,0,gear);
        }
        else if(choice == 3)
        {
            vehicle=new Car(speed,0,gear);
        }

        return vehicle;
    }
}
