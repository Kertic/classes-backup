using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5_BrennanRodriguez
{
    class Program
    {
        static void Main(string[] args)
        {
            NumList ListImport = new NumList();
            ListImport.LoadDict("variableTypes.txt");
            ListImport.LoadList("variableTypes.txt");
            while (true)
            {
                try
                {
                    Console.Clear();
                    Console.WriteLine("What would you like to do?");
                    Console.WriteLine("1. Search the list");
                    Console.WriteLine("2. Search the Dictionary");
                    Console.WriteLine("3. Exit");
                    int input = int.Parse(Console.ReadLine());

                    if (input == 1)
                    {
                        try
                        {
                            Console.WriteLine("Would you like to search explicitly or generally?");
                            Console.WriteLine("1. Explicitly");
                            Console.WriteLine("2. Generally");
                            int input2 = int.Parse(Console.ReadLine());
                            if (input2 == 1)
                            {
                                Console.Clear();
                                Console.WriteLine("What would you like to search the list for?:");
                                string query = Console.ReadLine();
                                ListImport.SearchListExact(query);

                            }
                            if (input2 == 2)
                            {
                                Console.Clear();
                                Console.WriteLine("What would you like to search the list for?:");
                                string query = Console.ReadLine();
                                ListImport.SearchList(query);

                            }
                            if (input2 != 1 && input2 != 2)
                            {
                                throw new Exception();
                            }


                        }
                        catch 
                        {
                            Console.WriteLine("Invalid option");

                            
                        }


                    }
                    if (input == 2)
                    {
                        try
                        {
                            Console.WriteLine("Would you like to search explicitly or generally?");
                            Console.WriteLine("1. Explicitly");
                            Console.WriteLine("2. Generally");
                            int input2 = int.Parse(Console.ReadLine());
                            if (input2 == 1)
                            {
                                Console.Clear();
                                Console.WriteLine("What would you like to search the Dictionary for?:");
                                string query = Console.ReadLine();
                                ListImport.SearchDictExact(query);

                            }
                            if (input2 == 2)
                            {
                                Console.Clear();
                                Console.WriteLine("What would you like to search the Dictionary for?:");
                                string query = Console.ReadLine();
                                ListImport.SearchDict(query);

                            }
                            if (input2 != 1 && input2 != 2)
                            {
                                throw new Exception();
                            }


                        }
                        catch
                        {
                            Console.WriteLine("Invalid option");


                        }


                    }
                    if (input == 3)
                    {
                        Environment.Exit(0);
                    }
                    if (input != 1 && input != 2 && input != 3)
                    {
                        throw new Exception();
                    }
                    Console.WriteLine("Press any key to continue...");
                    Console.ReadKey();

                }
                catch 
                {
                    Console.WriteLine("Please enter a valid answer.");
                    Console.WriteLine("Press any key to continue...");
                    Console.ReadKey();

                    
                }
            }
        }
    }
}
