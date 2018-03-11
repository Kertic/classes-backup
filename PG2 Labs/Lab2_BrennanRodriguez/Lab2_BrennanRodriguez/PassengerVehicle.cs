using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2_BrennanRodriguez
{
    class PassengerVehicle : Vehicle
    {
        int mCap;
       public PassengerVehicle(string make, string model, int year, int cap) : base(make, model, year)
        {
            mCap = cap;
        }

        
        public int GetCap()
        {
            return mCap;
        }
        public void SetCap(int cap)
        {
            mCap = cap;
        }



        public override void Print()
        {
            base.Print();
            Console.Write(", Max Capacity: " + mCap);
        }
        
    }
}
