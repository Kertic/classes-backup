using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab7_BrennanRodriguez
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                try
                {
                    Console.WriteLine("Which test would you like to perform?");
                    Console.WriteLine("1. AddHead");
                    Console.WriteLine("2. Remove(No Dupes)");
                    Console.WriteLine("3. Remove(Dupes)");
                    Console.WriteLine("4. RemoveAt");
                    Console.WriteLine("5. InsertAt");
                    Console.WriteLine("6. Exit");
                    int input = int.Parse(Console.ReadLine());
                    switch (input)
                    {
                        case 1:
                            Test1();
                            Tools.PressAnyKey();
                            break;
                        case 2:
                            Test2();
                            Tools.PressAnyKey();
                            break;
                        case 3:
                            Test3();
                            Tools.PressAnyKey();
                            break;
                        case 4:
                            Test4();
                            Tools.PressAnyKey();
                            break;
                        case 5:
                            Test5();
                            Tools.PressAnyKey();
                            break;
                        case 6:
                            Environment.Exit(0);
                            break;
                        default:
                            throw new Exception();
                    }

                }
                catch 
                {
                    Console.WriteLine("Please enter a valid option");
                    Tools.PressAnyKey();
                    
                }
                


            }

            

        }

        static public void Test1()
        {
            LinkedList<int> ints = new LinkedList<int>();

            for (int i = 0; i <= 50; i += 5)
                ints.AddHead(i);

            Console.WriteLine("-- Testing AddHead --");
            ints.Print();

        }
        static public void Test2()
        {
            LinkedList<int> ints = new LinkedList<int>();

            for (int i = 0; i <= 50; i += 5)
                ints.AddHead(i);

            Console.WriteLine("-- Testing Remove (No Duplicates) --");
            for (int i = 0; i <= 60; i += 10)
                Console.WriteLine("Removing " + i.ToString() + "s: " + ints.Remove(i) + " removed.");

            Console.WriteLine();
            Console.WriteLine("Remaining List Contents:\n");
            ints.Print();

        }
        static public void Test3()
        {
            LinkedList<int> ints = new LinkedList<int>();

            for (int i = 0; i <= 50; i += 5)
            {
                ints.AddHead(i);
                ints.AddHead(i);
            }

            Console.WriteLine("-- Testing Remove (Duplicates) --");

            for (int i = 0; i <= 60; i += 10)
                Console.WriteLine("Removing " + i.ToString() + "s: " + ints.Remove(i) + " removed.");

            Console.WriteLine("Remaining List Contents:");
            ints.Print();


        }
        static public void Test4()
        {
            LinkedList<String> strings = new LinkedList<String>();

            strings.AddHead("strings.");
            strings.AddHead("of");
            strings.AddHead("list");
            strings.AddHead("a");
            strings.AddHead("is");
            strings.AddHead("This");

            Console.WriteLine("--- Testing RemoveAt ---");
            Console.WriteLine("Before Removing:");

            strings.Print();

            Console.WriteLine();
            Console.WriteLine("Removing at index 4: " + (strings.RemoveAt(4) ? "Succeeded" : "Failed"));
            Console.WriteLine("Removing at index 4: " + (strings.RemoveAt(4) ? "Succeeded" : "Failed"));
            Console.WriteLine();

            Console.WriteLine("After Removing:");
            strings.Print();

            Console.WriteLine("Clearing the List...");
            while (strings.RemoveAt(0)) { }
            Console.WriteLine("List Contents:");
            strings.Print();

            Console.WriteLine("Adding \"Post-clear test\"...");
            strings.AddHead("Post-clear test");

            Console.WriteLine("List Contents:");
            strings.Print();

            Console.WriteLine("Testing Error Checking:");
            Console.WriteLine("Trying to remove at index 10: " + (strings.RemoveAt(10) ? "Succeeded" : "Failed"));
            Console.WriteLine("Trying to remove at index -1: " + (strings.RemoveAt(-1) ? "Succeeded" : "Failed"));


        }
        static public void Test5()
        {
            LinkedList<String> strings = new LinkedList<String>();

            Console.WriteLine("-- Testing InsertAt --");
            Console.WriteLine("List Contents:");
            strings.AddHead("end.");
            strings.AddHead("This");
            strings.Print();

            Console.WriteLine("Inserting \"the\" to index 1: " + (strings.InsertAt(1, "the") ? "Succeeded" : "Failed"));
            Console.WriteLine("Inserting \"is\" to index 1: " + (strings.InsertAt(1, "is") ? "Succeeded" : "Failed"));

            Console.WriteLine("List Contents:");
            strings.Print();

            Console.WriteLine("Testing Error Checking:");
            Console.WriteLine("Inserting \"shouldn't work\" to index -1: " + (strings.InsertAt(-1, "shouldn't work") ? "Succeeded" : "Failed"));
            Console.WriteLine("Inserting \"shouldn't work\" to index 10: " + (strings.InsertAt(10, "shouldn't work") ? "Succeeded" : "Failed"));


        }

    }
}
