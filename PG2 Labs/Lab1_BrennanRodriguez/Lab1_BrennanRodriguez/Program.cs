using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1_BrennanRodriguez
{
    class Program
    {
        static void Main(string[] args)
        {
            Classroom mathClass = new Classroom();
            Classroom artClass = new Classroom();
            Classroom sciClass = new Classroom();
            Students Student = new Students();
            //Console.WriteLine("Enter a new student - 1\nDisplay all classrooms - 2\nEnter your choice: ");

            while (true)
            {
                try
                {
                    //Menu
                    Console.WriteLine("Enter a new student - 1\nDisplay all classrooms - 2\nEnter your choice: ");
                    string option = Console.ReadLine();
                    
                    int intOption = int.Parse(option);
                    if (intOption <1 || intOption > 2)
                    {
                        throw new Exception();
                    }
                    if (intOption == 1) {
                        //Making a student
                        Console.WriteLine("What is the students name?: ");
                        Student.SetName(Console.ReadLine());//We are not the ones to judge any name, including weird names, a name consisting of a space, or a name consisting of nothing.
                        //Error checking for ages
                        bool ageIsGood = false;
                        do
                        {
                            try
                            {
                                Console.WriteLine("What is the students age?: ");
                                string ageOption = Console.ReadLine();
                                int intAge = int.Parse(ageOption);
                                if (intAge <= 0)
                                {
                                    throw new Exception();
                                }
                                if (intAge > 0)
                                {
                                    Student.SetAge(intAge);
                                    ageIsGood = true;
                                }


                            }catch
                            {
                                Console.WriteLine("Please put in a valid age");
                            }

                            

                        } while (!ageIsGood);
                        //Error checking for class
                        bool classIsGood = false;
                        do
                        {
                            try
                            {
                                Console.WriteLine("What Class should they join? (1 for math, 2 for art, 3 for science): ");
                                string classOption = Console.ReadLine();
                                int intClass = int.Parse(classOption);
                                if (intClass <= 0 || intClass > 3)
                                {
                                    throw new Exception();
                                }
                                if (intClass > 0 && intClass <= 3)
                                {
                                    if(intClass == 1)
                                    {
                                        if(mathClass.GetRemainingSpace() > 0)
                                        mathClass.addToClass(Student);
                                    }
                                    if (intClass == 2)
                                    {
                                        if (artClass.GetRemainingSpace() > 0)
                                            artClass.addToClass(Student);
                                    }
                                    if (intClass == 3)
                                    {
                                        if (sciClass.GetRemainingSpace() > 0)
                                            sciClass.addToClass(Student);
                                    }
                                    classIsGood = true;
                                }


                            }
                            catch
                            {
                                Console.WriteLine("Please put in a class with open space (Classes have a max space of 30)");
                            }



                        } while (!classIsGood);



                    }

                    if (intOption == 2)
                    {
                        Console.WriteLine("Math class:");
                        mathClass.DisplayClass();
                        Console.WriteLine("Art class:");
                        artClass.DisplayClass();
                        Console.WriteLine("Science class:");
                        sciClass.DisplayClass();

                    }


                }
                catch
                {
                    Console.WriteLine("Please input a valid choice");
                    Console.WriteLine("Press any key to continue...");
                    Console.ReadKey();
                }
                

               
            }

            Console.SetCursorPosition(0, Console.WindowHeight-1);
            Console.Write("Press any key to continue...");
            Console.ReadKey();

        }
    }



    
}


