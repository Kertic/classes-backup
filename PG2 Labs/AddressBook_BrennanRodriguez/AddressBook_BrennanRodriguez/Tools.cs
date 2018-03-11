using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace AddressBook_BrennanRodriguez
{
    static public class Tools
    {
        static public void ScrollType(string message, int speed)
        {
            bool SearchForNewLine = false;
            for (int i = 0; i < message.Length; i++)//Iterate through the loop until you reach the last indecie, starting from 0
            {

                if ((i) % 50/*the number of characters before attempting to wrap*/ == 0 && i != 0)
                {
                    SearchForNewLine = true;
                }

                if (SearchForNewLine == true && message[i] == ' ')
                {
                    Console.Write(message[i]);
                    i++;
                    Console.Write("\n");
                    SearchForNewLine = false;
                }
                Console.Write(message[i]);
                Thread.Sleep(speed);
            }
        }

        static public void ClearLine(int ypos)
        {
            Console.SetCursorPosition(0, ypos);
            Console.Write(new string(' ', Console.WindowWidth));
            Console.SetCursorPosition(0, ypos - 1);
        }

        static public void PressAnyKey()
        {
            Console.WriteLine("Press any key to continue...");
            Console.ReadKey();
        }
    }
}
