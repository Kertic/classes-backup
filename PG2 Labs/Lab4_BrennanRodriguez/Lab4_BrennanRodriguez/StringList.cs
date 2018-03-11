using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Lab4_BrennanRodriguez
{
    class StringList
    {
        List<string> mList;

        public StringList()
        {
            mList = new List<string>();
        }

        public StringList(List<string> inList)
        {
            mList = new List<string>();
            for (int i = 0; i < inList.Count; i++)
            {
                mList.Add(inList[i]);
            }
        }

        public void AddToList()
        {
            Console.Clear();
            Console.WriteLine("Please type the string you want to add(Blank strings are acceptable): ");
            mList.Add(Console.ReadLine());
        }

        public void AddToList(string inString)
        {

            mList.Add(inString);
        }

        public void RemoveFromList()
        {
            while (true)
            {
                try
                {
                    Console.Clear();
                    Console.WriteLine("What string would you like to remove?(Please be EXACT):");
                    string input = Console.ReadLine();
                    if (!mList.Contains(input))
                    {
                        throw new Exception();
                    }
                    mList.Remove(input);

                    


                }
                catch 
                {
                    Console.WriteLine("The string was not found");
                    Console.WriteLine("Press any key to continue...");
                    Console.ReadKey();
                    break;

                    
                }
                Console.WriteLine("String successfully removed!");
                Console.WriteLine("Press any key to continue...");
                Console.ReadKey();
                break;
            }
        }

        public void RemoveFromList(string inString)
        {
            mList.Remove(inString);

        }

        public void SaveToFile()
        {
            string filename = "";
            while (true)
            {

                try
                {
                    Console.Clear();
                    Console.WriteLine("What would you like to name the file?");
                    string input = Console.ReadLine();
                    if (input == "")
                    {
                        throw new Exception();
                    }
                    else
                    {
                         filename = input + ".txt";
                        break;
                    }

                }
                catch
                {
                    Console.WriteLine("Please enter a file name");
                    Console.WriteLine("Press any key to continue...");
                    Console.ReadKey();
                    
                    
                }
                

            }

            StreamWriter writer = new StreamWriter(filename);
            for (int i = 0; i < mList.Count; i++)
            {
                
                writer.WriteLine(mList[i]);

                
            }
            writer.Close();
        }

        public void SaveToCsvFile()
        {
            string filename = "";
            while (true)
            {

                try
                {
                    Console.Clear();
                    Console.WriteLine("What would you like to name the file?");
                    string input = Console.ReadLine();
                    if (input == "")
                    {
                        throw new Exception();
                    }
                    else
                    {
                        filename = input + ".csv";
                        break;
                    }

                }
                catch
                {
                    Console.WriteLine("Please enter a file name");
                    Console.WriteLine("Press any key to continue...");
                    Console.ReadKey();


                }


            }

            StreamWriter writer = new StreamWriter(filename);
            for (int i = 0; i < mList.Count; i++)
            {

                writer.Write(mList[i] + ",");


            }
            writer.Close();

        }

        public void LoadFromFile()
        {
            try
            {
                Console.WriteLine("What is the file name to load? (Not including the extension)");
                string input = Console.ReadLine();
                StreamReader reader = new StreamReader(input + ".txt");
                mList.RemoveRange(0, mList.Count);
                while (!reader.EndOfStream)
                {
                    mList.Add(reader.ReadLine());
                }

                reader.Close();

            }
            catch 
            {
                Console.WriteLine("File was not located.");
                Console.WriteLine("Press any key to continue...");
                Console.ReadKey();
                
            }

        }
        public void LoadFromCsvFile()
        {
            try
            {
                Console.WriteLine("What is the file name to load? (Not including the extension)");
                string input = Console.ReadLine();
                StreamReader reader = new StreamReader(input + ".csv");
                mList.RemoveRange(0, mList.Count);
                while (!reader.EndOfStream)
                {
                    string line = reader.ReadLine();
                    string[] arrayOfStrings = line.Split(',');
                    for (int i = 0; i < arrayOfStrings.Length-1; i++)
                    {
                        mList.Add(arrayOfStrings[i]);
                    }
                }

                reader.Close();

            }
            catch
            {
                Console.WriteLine("File was not located.");
                Console.WriteLine("Press any key to continue...");
                Console.ReadKey();

            }

        }

        public void Display()
        {
            Console.Clear();
            for (int i = 0; i < mList.Count; i++)
            {
                Console.WriteLine(mList[i]);
            }
        }
        public int GetLength()
        {
            return mList.Count();
        }


    }
}
