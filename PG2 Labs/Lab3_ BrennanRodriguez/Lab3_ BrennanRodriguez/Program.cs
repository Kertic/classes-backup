using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3__BrennanRodriguez
{
    class Program
    {
        static void Main(string[] args)
        {
            List<char> letterList = new List<char>();
            Random rand = new Random();
            string letters = "abcdefghijklmnopqrstuvwxyz";//The trick to use "a" and "z" didn't work for me, I'm not sure what I did wrong, so I used this instead.

            for (int i = 0; i < 25; i++)//Populate the list
            {
                letterList.Add(letters[rand.Next(0, 26)]);
            }
            Console.WriteLine("The list of " + letterList.Count + " letters is:\n");//Printing the list
            for (int i = 0; i < letterList.Count; i++)
            {
                Console.Write(" " + letterList[i]);
            }





            char? charinput = null;//char? is a char variable that allows char to defualt to null instead of 0 (this way people can check for 0 if they wish) information gained here: http://stackoverflow.com/questions/17772510/how-to-check-if-a-char-array-element-is-empty
            string input;
            bool quit = false;
            while (!quit)
            {
                while (true)
                {
                    try
                    {
                        Console.Write("\nPlease enter a letter to search for or ? to quit: ");
                        input = Console.ReadLine();
                        charinput = input[0];

                    }
                    catch
                    {
                        Console.Write("\nPlease enter a valid letter");
                    }
                    if(charinput == '?')
                    {
                        quit = true;
                    }
                    if (charinput != null)
                    {
                        break;
                    }
                    {

                    }
                }


                int timesFound = 0;
                for (int i = 0; i < letterList.Count; i++)
                {
                    if (charinput == letterList[i])
                    {
                        timesFound++;
                    }

                }

                if (timesFound > 0)
                {
                    Console.ForegroundColor = ConsoleColor.Green;
                    Console.Write("\nYour character was found " + timesFound + " times.");
                    Console.ForegroundColor = ConsoleColor.Gray;

                }
                else if (timesFound == 0)
                {
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.Write("\nYour character was found " + timesFound + " times.");
                    Console.ForegroundColor = ConsoleColor.Gray;

                }
                
                
            }
            

            
        }
    }
}
