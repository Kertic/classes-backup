using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2_BrennanRodriguez
{
    class Vehicle
    {
        string mMake;
        string mModel;
        int mYear;
        public Vehicle(string make, string model, int year)
        {
            mMake = make;
            mModel = model;
            mYear = year;

        }

        public string GetMake()
        {
            return mMake;
        }
        public string GetModel()
        {
            return mModel;

        }
        public int GetYear()
        {
            return mYear;
        }
        public void SetMake(string make)
        {
            mMake = make;
        }
        public void SetModel(string model)
        {
            mModel = model;
        }
        public void SetYear(int year)
        {
            mYear = year;
        }

        virtual public void Print()
        {
            Console.Write("\n");
            Console.Write("Make: " + mMake + ", Model: " + mModel + ", Year: " + mYear);
        }

    }
}
