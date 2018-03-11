using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace AddressBook_BrennanRodriguez
{
    class AddressBook
    {
        List<string[]> mAddressList = new List<string[]>();

        public void AddToList()
        {
            Console.WriteLine("Please write their name");
            string name = Console.ReadLine();
            Console.WriteLine("Please enter their street name(Don't include the number)");
            string streetName = Console.ReadLine();
            Console.WriteLine("Please enter their street number");
            string streetNumber = Console.ReadLine();
            Console.WriteLine("Please enter their city");
            string city = Console.ReadLine();
            Console.WriteLine("Please enter their state");
            string state = Console.ReadLine();
            Console.WriteLine("Please enter their zipcode");
            string zip = Console.ReadLine();

            string[] newEntry = { name, streetNumber, streetName, city, state, zip };
            mAddressList.Add(newEntry);
        }

        public void RemoveFromList()
        {
            this.Display();
            while (true)
            {
                try
                {
                    Console.WriteLine("Which entry would you like to remove?");
                    int input = int.Parse(Console.ReadLine());
                    if (input > 0 && input <= mAddressList.Count)
                    {
                        mAddressList.Remove(mAddressList[input - 1]);
                        Console.WriteLine("Entry number #" + input + " removed.");
                        Tools.PressAnyKey();
                        break;
                    }
                    else
                    {
                        throw new Exception();
                    }

                }
                catch
                {
                    Console.WriteLine("Please enter a valid choice");

                }
            }


           
           
           
            
        }

        public void EditEntry()
        {
            this.Display();
            while (true)
            {
                try
                {
                    Console.WriteLine("Which entry would you like to edit?");
                    int input = int.Parse(Console.ReadLine());
                    if (input > 0 && input <= mAddressList.Count)
                    {
                        Console.WriteLine("Please write their name");
                        string name = Console.ReadLine();
                        Console.WriteLine("Please enter their street name(Don't include the number)");
                        string streetName = Console.ReadLine();
                        Console.WriteLine("Please enter their street number");
                        string streetNumber = Console.ReadLine();
                        Console.WriteLine("Please enter their city");
                        string city = Console.ReadLine();
                        Console.WriteLine("Please enter their state");
                        string state = Console.ReadLine();
                        Console.WriteLine("Please enter their zipcode");
                        string zip = Console.ReadLine();

                        string[] newEntry = { name, streetNumber, streetName, city, state, zip };
                        mAddressList[input - 1] = newEntry;
                        Console.WriteLine("Entry Successfully edited");
                        Tools.PressAnyKey();
                        break;
                    }
                    else
                    {
                        throw new Exception();
                    }

                }
                catch
                {
                    Console.WriteLine("Please enter a valid choice");

                }
            }

        }

        public void Export()
        {
            Console.WriteLine("What would you like to name the file?(Don't include extention)");
            string input = Console.ReadLine();
            StreamWriter writer = new StreamWriter(input + ".adb");
            for (int i = 0; i < mAddressList.Count; i++)
            {
                writer.WriteLine(mAddressList[i][0] + ',' + mAddressList[i][1] + ',' + mAddressList[i][2] + ',' + mAddressList[i][3] + ',' + mAddressList[i][4] + ',' + mAddressList[i][5]);
            }
            writer.Close();
            
        }
        public void Import()
        {
            Console.WriteLine("What is the file called?(Default extention is .adb)");
            string input = Console.ReadLine();
            StreamReader reader = new StreamReader(input);
            int NumDupes = 0;
            while (!reader.EndOfStream) {
                char[] seperator = { ',' };
                string readerInput = reader.ReadLine();
                string[] inputArray = readerInput.Split(',');
                bool IsDuplicate = false;
                
                
                for (int i = 0; i < mAddressList.Count; i++)
                {
                    if (inputArray == mAddressList[i])
                    {
                        IsDuplicate = true;
                        NumDupes++;
                    }
                }
                if (IsDuplicate == false)
                {
                    mAddressList.Add(inputArray);
                }
                
            }
            if (NumDupes > 0)
            {
                Console.WriteLine(NumDupes + " duplicates found. Those were not imported.");

            }

            reader.Close();
        }
        public void Open()
        {
            mAddressList = new List<string[]>();
            this.Import();


        }
        public void SortList()
        {
            while (true)
            {
                try
                {
                    Console.WriteLine("What would you like to sort by?");
                    Console.WriteLine("1. Name");
                    Console.WriteLine("2. Address number");
                    Console.WriteLine("3. Street name");
                    Console.WriteLine("4. City");
                    Console.WriteLine("5. State");
                    Console.WriteLine("6. Zip code");
                    int input = int.Parse(Console.ReadLine());
                    if (input > 0 && input < 7)
                    {
                        while (true)
                        {
                            bool swapped = false;
                            for (int i = 0; i< mAddressList.Count - 1; i++){
                                if (mAddressList[i][input - 1].CompareTo(mAddressList[i + 1][input - 1]) > 0)
                                {
                                    string[] temp = mAddressList[i];
                                    mAddressList[i] = mAddressList[i + 1];
                                    mAddressList[i + 1] = temp;
                                    //Swap them
                                    swapped = true;
                                    //Mark swapped as true
                                }
                            }
                            if (swapped == false)
                            {
                                break;
                            }
                        }
                        Console.WriteLine("List sorted by option " + input);
                        Tools.PressAnyKey();
                        break;


                    }
                    else
                    {
                        throw new Exception();
                    }
                }
                catch
                {
                    Console.WriteLine("Please write a valid answer");
                }
            }
        }

        public void Search()
        {
            Console.WriteLine("What would you like to search for?");
            string query = Console.ReadLine();
            List<string[]> SearchResults = new List<string[]>();
             int numFound = 0;
            for (int i = 0; i < mAddressList.Count; i++)
            {
                for (int j = 0; j > mAddressList[i].Length; j++){
                    if (mAddressList[i][j] == query){
                        SearchResults.Add(mAddressList[i]);
                        numFound++;
                        break;
                    }
                }
            }


            //Out of the for loops
            Console.WriteLine(numFound + " entries found.");
            for (int i = 0; i < SearchResults.Count; i++)
            {

                Console.WriteLine();
                for (int j = 0; j > SearchResults[i].Length; j++)
                {

                    Console.WriteLine(SearchResults[i][j]);
                }
            }
        }

        public void Display()
        {
            for (int i = 0; i < mAddressList.Count; i++)
            {
                Console.WriteLine("Entry number " + (i + 1) + ". ");
                for (int j = 0; j < mAddressList[i].Length; j++)
                {
                    Console.WriteLine(mAddressList[i][j]);

                }
            }
        }
    }
}
