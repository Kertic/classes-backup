using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3._2_BrennanRodriguez
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> searchList = new List<int>();
            Random rand = new Random();
            int lowest = 1000;
            int highest = -1000;
            for (int i = 0; i < 50; i++)//Populating the list
            {
                
                searchList.Add(rand.Next(1, 101));

            }

            Console.WriteLine("The numbers are:");
            for (int i = 0; i < searchList.Count; i++)//Printing out the numbers
            {
                Console.ForegroundColor = ConsoleColor.Cyan;
                Console.Write(" " + searchList[i] + " ");
                Console.ForegroundColor = ConsoleColor.White;
            }

            for (int i = 0; i < searchList.Count; i++)//changing the highest and lowest
            {
                if (searchList[i] > highest)
                {
                    highest = searchList[i];
                }
                if (searchList[i] < lowest)
                {
                    lowest = searchList[i];
                }

            }

            Console.Write("\nThe Lowest number is:");
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.Write(lowest);
            Console.ForegroundColor = ConsoleColor.Gray;
            Console.Write("\nThe Highest number is:");
            Console.ForegroundColor = ConsoleColor.Green;
            Console.Write(highest);
            Console.ForegroundColor = ConsoleColor.Gray;
            int oldListSize = searchList.Count;
            for (int i = searchList.Count-1; i > 0; i--)//Remove the highest and lowest number... Also RemoveAll() exists but I guess the lab instructions say no to that.
            {
                if (searchList[i] == highest || searchList[i] == lowest)
                {
                    searchList.Remove(searchList[i]);
                }

            }
            Console.WriteLine("\nWe removed " + (oldListSize - searchList.Count) + " numbers from the list");
            Console.WriteLine("The new list is:");

            for (int i = 0; i < searchList.Count; i++)//Printing out the numbers
            {
                Console.ForegroundColor = ConsoleColor.Cyan;
                Console.Write(" " + searchList[i] + " ");
                Console.ForegroundColor = ConsoleColor.White;
            }
            Console.Write("\nPress any key to continue...");
            Console.ReadKey();
        }
    }
}
