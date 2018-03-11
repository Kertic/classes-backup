using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab8_BrennanRodriguez
{
    class Employee
    {
        int age;
        float salary;
        
        string firstName ;
        string lastName;

        public Employee()
        {
            age = 0;
            salary = 0.0f;
           
            firstName = "";
            lastName = "";

        }

        public Employee(int inAge, float inSal, string inFirst, string inLast)
        {
            age = inAge;
            salary = inSal;
            firstName = inFirst;
            lastName = inLast;
        }
    }
}
