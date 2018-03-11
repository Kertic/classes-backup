using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2_BrennanRodriguez
{
    class Truck : PassengerVehicle
    {
        int Weight;
        public Truck(string make, string model, int year, int cap, int weight) : base(make, model, year, cap)
        {
            this.Weight = weight;
        }
        public int GetWeight()
        {
            return Weight;
        }
        public void SetWeight(int weight)
        {
            this.Weight = weight;
        }

        public override void Print()
        {
            base.Print();
            Console.Write(", Maximum Load: " + this.Weight);
        }
    }
}
