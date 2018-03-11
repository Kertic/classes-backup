using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AddressBook_BrennanRodriguez
{
    class Program
    {
        static void Main(string[] args)
        {
            AddressBook list = new AddressBook();

            while (true)
            {
                try
                {
                    Console.WriteLine("What would you like to do?");
                    Console.WriteLine("1. Add an entry");
                    Console.WriteLine("2. Remove an entry");
                    Console.WriteLine("3. Edit an entry");
                    Console.WriteLine("4. Export the current list");
                    Console.WriteLine("5. Import a list from a file");
                    Console.WriteLine("6. Search the list for entries");
                    Console.WriteLine("7. Sort the list");
                    Console.WriteLine("8. Display the current list");
                    Console.WriteLine("9. Open a new file(Overwrites the current list)");
                    Console.WriteLine("10. Exit");

                    int input = int.Parse(Console.ReadLine());

                    if (input == 1)
                    {
                        list.AddToList();
                        Tools.PressAnyKey();
                        Console.Clear();
                    }
                    if (input == 2)
                    {
                        list.RemoveFromList();
                        Tools.PressAnyKey();
                        Console.Clear();

                    }
                    if (input == 3)
                    {
                        list.EditEntry();
                        Tools.PressAnyKey();
                        Console.Clear();
                    }
                    if (input == 4)
                    {
                        list.Export();
                        Tools.PressAnyKey();
                        Console.Clear();
                    }
                    if (input == 5)
                    {
                       list.Import();
                        Tools.PressAnyKey();
                        Console.Clear();
                    }
                    if (input == 6)
                    {
                        list.Search();
                        Tools.PressAnyKey();
                        Console.Clear();
                    }
                    if (input == 7)
                    {
                        list.SortList();
                        Tools.PressAnyKey();
                        Console.Clear();
                    }
                    if (input == 8 )
                    {
                        list.Display();
                        Tools.PressAnyKey();
                        Console.Clear();
                    }
                    if (input == 9)
                    {
                        list.Open();
                    }
                    if (input == 10)
                    {
                        Environment.Exit(0);
                    }
                    if (input < 1 || input > 10)
                    {
                        throw new Exception();
                    }

                }
                catch
                {
                    Console.WriteLine("Please write a valid answer");
                    Tools.PressAnyKey();

                    
                }

            }


        }
    }
}
