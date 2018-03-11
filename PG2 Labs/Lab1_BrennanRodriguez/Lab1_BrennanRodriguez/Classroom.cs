using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1_BrennanRodriguez
{
    public class Classroom
    {

        Students[] mStudents = new Students[30];
        int mAmountIn = 0;
       public Classroom()
        {
            for (int i = 0; i < mStudents.Length; i++)
            {
                mStudents[i] = new Students();
            }
        }

        public void addToClass(Students student)
        {
            bool added = false;
            while (!added)
            {
                for (int i = 0; i < mStudents.Length && added == false; i++)
                {
                    if (mStudents[i].GetName() == "default" && mStudents[i].GetAge() == 0)//If its a default space
                    {
                        mStudents[i] = student;
                        added = true;
                        mAmountIn++;
                    }
                  // if (!(mStudents[i].GetName() == "default name" && mStudents[i].GetAge() == 0) ) //Redundant code left for refrencing
                  // {
                  //     i++;
                  // }
                    
                }
            }
        }

        public int GetClassCap()
        {
            return mStudents.Length;
        }
        public int GetRemainingSpace()
        {
            return mStudents.Length - mAmountIn;
        }
        public void DisplayClass()
        {
            for (int i = 0; i < mStudents.Length; i++)
            {
                if (!(mStudents[i].GetName() == "default" && mStudents[i].GetAge() == 0)) // If its not a default space
                {
                    Console.WriteLine(mStudents[i].GetName() + " Age: " + mStudents[i].GetAge());
                }
                
            }
            Console.WriteLine(" ");
        }


    }
}
