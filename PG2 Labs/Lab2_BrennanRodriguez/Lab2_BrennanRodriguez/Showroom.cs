using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2_BrennanRodriguez
{
    public class Showroom
    {
        Vehicle[] room = new Vehicle[4];
        int maxCap;
        int currentCap;

        public Showroom()
        {
          //  for (int i = 0; i < room.Length; i++)
          //  {
          //      
          //      room[i].SetMake("Default make");
          //      room[i].SetModel("Default model");
          //      room[i].SetYear(9999);
          //  }
             maxCap = 3;
             currentCap = 0;
        }

        public void AddPassengerVehicle(string make, string model, int year, int memberCap)
        {
            if(currentCap <= maxCap)
            {
                room[currentCap] = new PassengerVehicle(make, model, year, memberCap);
                currentCap++;
            }
            else
            {
                Console.Clear();
                Console.WriteLine("The Showroom is at Maximum capacity.");
                Console.ReadKey();
            }


        }
        public void AddTruck(string make, string model, int year, int memberCap, int WeightCap)
        {
            if (currentCap <= maxCap)
            {
                room[currentCap] = new Truck(make, model, year, memberCap, WeightCap);
                currentCap++;
            }
            else
            {
                Console.Clear();
                Console.WriteLine("The Showroom is at Maximum capacity.");
                Console.ReadKey();
            }


        }
        public void Display()
        {
            Console.Clear();
            for (int i = 0; i < currentCap; i++)
            {
                room[i].Print();
            }
            Console.WriteLine("\nPress any key to contiue...");
            Console.ReadKey();
            Console.Clear();
        }


    }
}
