using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab8_BrennanRodriguez
{
    class Manager : Employee
    {
        float bonus;
        public Manager() : base()
        {
            
            bonus = 0.0f;
        }

        public Manager(int inAge, float inSal, string inFirst, string inLast, float inBonus) : base(inAge, inSal, inFirst, inLast)
        {
            bonus = inBonus;

        }
    }
}
