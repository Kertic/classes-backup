using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2_BrennanRodriguez
{
    class Program
    {
        static void Main(string[] args)
        {
            // Testing out the classes
            // Vehicle someVehic = new Vehicle("PT", "Cruiser", 2001);
            // Truck someTruck = new Truck("Ford", "Explorer", 2012, 500);
            // PassengerVehicle someSUV = new PassengerVehicle("Crysler", "Merry", 1997, 9);
            //
            // someVehic.Print();
            // someTruck.Print();
            // someSUV.Print();
            Showroom room = new Showroom();
            while (true)
            {
                Console.Write("Vehicle database\nChoices are:\n");
                Console.WriteLine("1. Enter a new Passenger vehicle");
                Console.WriteLine("2. Enter a new Truck");
                Console.WriteLine("3. Display current showcase");
                Console.WriteLine("4. Exit");
                //I wanted to use Console.ReadKey() cause it felt more responsive than hitting enter, used microsoft's site to read up on it. https://msdn.microsoft.com/en-us/library/471w8d85(v=vs.110).aspx
                ConsoleKey input = Console.ReadKey().Key;
                //While loop for option 1
                if (input == ConsoleKey.D1 || input == ConsoleKey.NumPad1) {
                        Console.Clear();
                    //Same with names, if the name is Blank, its not up to me to determine if its valid. They can name their cars whatever they want.
                    Console.Write("Enter the Make: ");
                        string make = Console.ReadLine();
                        Console.Write("\nEnter the Model: ");
                        string model = Console.ReadLine();
                    int year = 0;
                    int person = 0;
                    //Error checking for a proper year
                    while (true)
                        {
                            Console.Write("\nEnter the Year: ");
                            try
                            {
                               
                                string yearInput = Console.ReadLine();
                                 year = int.Parse(yearInput);
                            if(year <= 0)
                            {
                                throw new Exception();
                            }
                                break; 

                            }
                            catch
                            {
                                Console.WriteLine("Please write a valid year");
                            }
                        }
                    //Error checking for a seating amount
                    while (true)
                    {
                        Console.Write("\nEnter the Person Capacity: ");
                        try
                        {

                            string personInput = Console.ReadLine();
                             person = int.Parse(personInput);
                            if (person <= 0)
                            {
                                throw new Exception();
                            }
                            break;

                        }
                        catch
                        {
                            Console.WriteLine("Please write a valid year");
                        }
                    }
                    room.AddPassengerVehicle(make, model, year, person);

                }else

                //While loop for option 2
                if (input == ConsoleKey.D2 || input == ConsoleKey.NumPad2)
                {
                    Console.Clear();
                    //Same with names, if the name is Blank, its not up to me to determine if its valid. They can name their cars whatever they want.
                    Console.Write("Enter the Make: ");
                    string make = Console.ReadLine();
                    Console.Write("\nEnter the Model: ");
                    string model = Console.ReadLine();
                    int year = 0;
                    int person = 0;
                    int weight = 0;
                    //Error checking for a proper year
                    while (true)
                    {
                        Console.Write("\nEnter the Year: ");
                        try
                        {

                            string yearInput = Console.ReadLine();
                            year = int.Parse(yearInput);
                            if (year <= 0)
                            {
                                throw new Exception();
                            }
                            break;

                        }
                        catch
                        {
                            Console.WriteLine("Please write a valid year");
                        }
                    }
                    //Error checking for a seating amount
                    while (true)
                    {
                        Console.Write("\nEnter the Person Capacity: ");
                        try
                        {

                            string personInput = Console.ReadLine();
                            person = int.Parse(personInput);
                            if (person <= 0)
                            {
                                throw new Exception();
                            }
                            break;

                        }
                        catch
                        {
                            Console.WriteLine("Please write a valid number");
                        }
                    }
                    //Error checking for a Weight capacity
                    while (true)
                    {
                        Console.Write("\nEnter the Weight Capacity: ");
                        try
                        {

                            string weightInput = Console.ReadLine();
                            weight = int.Parse(weightInput);
                            if (person <= 0)
                            {
                                throw new Exception();
                            }
                            break;

                        }
                        catch
                        {
                            Console.WriteLine("Please write a valid number");
                        }
                    }
                    room.AddTruck(make, model, year, person, weight);

                } else
                if (input == ConsoleKey.D3 || input == ConsoleKey.NumPad3)
                {
                    room.Display();

                }else 
                if (input == ConsoleKey.D4 || input == ConsoleKey.NumPad4)
                {
                    break;
                }







            }
            
        }
    }
}
