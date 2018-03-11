using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1_BrennanRodriguez
{
  public class Students
    {
        

            string mName;
            int mAge;
            public Students()
            {
                mName = "default";
                mAge = 0;
            }
           public string GetName()
            {
                return mName;
            }

        public int GetAge()
            {
                return mAge;
            }

        public void SetAge(int age)
            {
                mAge = age;
            }
        public void SetName(string name)
            {
                mName = name;
            }


        
    }
}
