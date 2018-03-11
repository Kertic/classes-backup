using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab4_BrennanRodriguez
{
    class Program
    {
        static void Main(string[] args)
        {
            StringList primaryList = new StringList();
             bool exit = false;
             while (!exit)
             {
                Console.Clear();
                Console.WriteLine("String list");
                Console.WriteLine("Please enter an option");
                Console.WriteLine("1. Add to the list");
                Console.WriteLine("2. Remove from the list");
                Console.WriteLine("3. Show the list");
                Console.WriteLine("4. Save the list to a file");
                Console.WriteLine("5. Load the list from a file");
                Console.WriteLine("6. Exit the program");

                try
                {
                    int input = int.Parse(Console.ReadLine());
                    if (input == 1)
                    {
                        primaryList.AddToList();

                    }
                    if (input == 2)
                    {
                        primaryList.RemoveFromList();

                    }
                    if (input == 3)
                    {
                        primaryList.Display();
                        Console.WriteLine("Press any key to continue...");
                        Console.ReadKey();

                    }
                    if (input == 4)
                    {

                        while (true)
                        {
                            try
                            {
                                Console.Clear();
                                Console.WriteLine("Would you like to save it as a text file or a CSV file? (Enter txt or csv)");
                                string input2 = Console.ReadLine();
                                if (input2 == "txt")
                                {
                                    if (primaryList.GetLength() < 1)
                                    {
                                        Console.Clear();
                                        Console.WriteLine("There is nothing in the list to save.");
                                        Console.WriteLine("Press any key to continue...");
                                        Console.ReadKey();
                                        break;
                                    }
                                    else
                                    {
                                        primaryList.SaveToFile();
                                        break;
                                    }

                                }
                                if (input2 == "csv")
                                {
                                    if (primaryList.GetLength() < 1)
                                    {
                                        Console.Clear();
                                        Console.WriteLine("There is nothing in the list to save.");
                                        Console.WriteLine("Press any key to continue...");
                                        Console.ReadKey();
                                        break;
                                    }
                                    else
                                    {
                                        primaryList.SaveToCsvFile();
                                        break;
                                    }
                                }
                                if (input2 != "csv" || input2 != "txt")
                                {
                                    throw new Exception();
                                }
                            }
                            catch 
                            {
                                Console.WriteLine("Please enter a valid answer");
                                Console.WriteLine("Press any key to continue...");
                                Console.ReadKey();


                            }

                        }


                    }   
                    if (input == 5)
                    {
                        while (true)
                        {
                            try
                            {
                                Console.Clear();
                                Console.WriteLine("Would you like to Load it as a text file or a CSV file? (Enter txt or csv)");
                                string input2 = Console.ReadLine();
                                if (input2 == "txt")
                                {

                                        primaryList.LoadFromFile();
                                        break;
                                    

                                }
                                if (input2 == "csv")
                                {

                                        primaryList.LoadFromCsvFile();
                                        break;
                                    
                                }
                                if (input2 != "csv" || input2 != "txt")
                                {
                                    throw new Exception();
                                }
                            }
                            catch
                            {
                                Console.WriteLine("Please enter a valid answer");
                                Console.WriteLine("Press any key to continue...");
                                Console.ReadKey();


                            }

                        }

                    }
                    if (input == 6)
                    {
                        exit = true;

                    } if(input > 6 || input < 1)
                    {
                        throw new Exception();
                    }

                }
                catch
                {
                    Console.WriteLine("Please enter a valid selection");
                    Console.WriteLine("Press any key to continue...");
                    Console.ReadKey();
                }




            }
 
        }
    }
}
