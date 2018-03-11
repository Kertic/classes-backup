using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3._1_BrennanRodriguez
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> primeList = new List<int>();
            for (int i = 1; i < 100; i++)
            {
                int numberOfDivisors = 0;
                for (int j = 1; j < i; j++)
                {
                    
                    if (i % j == 0)
                    {
                        numberOfDivisors += 2;
                    }
                }
                if (numberOfDivisors == 2)
                {
                    primeList.Add(i);
                }

            }





            for (int i = 0; i < primeList.Count; i++)
            {
                Console.WriteLine(primeList[i]);
            }
            Console.Write("\nPress any key to continue...");
            Console.ReadKey();
        }
    }
}
