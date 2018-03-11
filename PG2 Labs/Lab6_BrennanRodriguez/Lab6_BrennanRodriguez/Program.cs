using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;


namespace Lab6_BrennanRodriguez
{
    class Program
    {
        static void Main(string[] args)
        {
            List<string> importList = new List<string>();
            StreamReader reader = new StreamReader("testFile.csv");
            while (!reader.EndOfStream)
            {
                string importedLine = reader.ReadLine();
                string[] splitLine = importedLine.Split(',');
                for (int i = 0; i < splitLine.Length; i++)
                {
                    importList.Add(splitLine[i]);
                }
            }
            reader.Close();
            bool bubblesort = false;
            bool selectionsort = false;
            bool insertionsort = false;

            while (true)
            {
                try
                {
                    Console.Clear();
                    Console.WriteLine("What would you like to do?");
                    Console.WriteLine("1. Bubble sort\n2. Selection Sort\n3. Insertion sort\n4. Randomize the data\n5. Display the data\n6. Exit");
                    int input = int.Parse(Console.ReadLine());
                    
                    if (input == 1)
                    {
                        BubbleSort(importList, bubblesort);
                        bubblesort = !bubblesort;

                    }
                    if (input == 2)
                    {
                        SelectionSort(importList, selectionsort);
                        selectionsort = !selectionsort;

                    }
                    if (input == 3)
                    {
                        InsertionSort(importList, insertionsort);
                        insertionsort = !insertionsort;

                    }
                    if (input == 4)
                    {
                        Randomize(importList);
                        Console.WriteLine("Data randomized");
                        Tools.PressAnyKey();

                    }
                    if (input == 5)
                    {
                        //Displays the list
                          for (int i = 0; i < importList.Count; i++)
                          {
                              Console.WriteLine(importList[i]);
                       
                          }
                        Console.WriteLine();
                        Tools.PressAnyKey();//I was tired of retyping that so I made a tool for it in my personal library.


                    }
                    if (input == 6)
                    {
                        Environment.Exit(0);

                    }
                    if (input != 1 && input != 2 && input != 3 && input != 4 && input != 5 && input != 6)
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

        private static void Randomize(List<string> importList)
        {
            Random rand = new Random();
            for (int i = 0; i < 501; i++)
            {
                string temp = "";
                int one = rand.Next(0, importList.Count);
                int two = rand.Next(0, importList.Count);
                temp = importList[one];
                importList[one] = importList[two];
                importList[two] = temp;

            }
        }

        private static void BubbleSort(List<string> importList, bool reverse)
        {
            int numSwapped = 0;
            // Loop through the entire list/array
            while (true)
            {
               bool swapped = false;
                
                for (int currentListSpot = 0; currentListSpot < importList.Count - 1; currentListSpot++)
                {

                    string string1 = importList[currentListSpot];
                    string string2 = importList[currentListSpot + 1];
                    if (string1.CompareTo(string2) > 0) // if the current spot should come after the spot to its right
                    {
                        string temp = "";
                        temp = importList[currentListSpot];
                        importList[currentListSpot] = importList[currentListSpot + 1];
                        importList[currentListSpot + 1] = temp;
                        swapped = true;
                        numSwapped++;
                    }
                }
                if (swapped == false)
                {
                    Console.WriteLine(numSwapped + " Values swapped.");
                    Tools.PressAnyKey();
                    break;

                }

                

            }


            // Compare the current index and the one right after it
            // If they are out of order...
            // Swap the values.

            // If a swap has happened, repeat the process.  If not, all done!
        }

        private static void SelectionSort(List<string> importList, bool reverse)
        {
            for (int i = 0; i < importList.Count; i++)// " i " is the first unsorted place in the list
            {
                string min = importList[i];
                for (int j = i + 1; j < importList.Count; j++)//J " j " is the place we compare i to
                {
                    bool toSwap = false;

                    if (importList[i].CompareTo(importList[j]) > 0) //If the spot we started with is higher than the spot we observed
                    {
                        min = importList[j]; // we set min to the object we observed
                        toSwap = true;//Say we need to swap.

                    }
                    if (toSwap == true)
                    {
                        string temp = "";
                       
                        
                        temp = importList[i];
                        importList[i] = importList[j];
                        importList[j] = temp;

                    }
                    

                }

            }
            
            // Loop through the list.
            // Assume the current index is the smallest value.

            // Loop again, through ALL entries PAST the last loop index (don't want to compare things twice)
            // Did we find a smaller value?
            // Update the min_index to reflect the location of the new minimum value.

            // AFTER looping through all to find a new minimum... If there is a new min_index... swap it with the current value.
        }

        static public void InsertionSort(List<string> importList, bool reverse)
        {

            for (int i = 1; i < importList.Count; i++)
            {
                int counter = i; // Create a counter variable equal to your current index variable
                                 // We're assuming that the beginning of the array is the sorted part.
                int innerCounter = i;
                while (innerCounter > 0)// Create an inner while loop that starts at the outer loop index, and goes to 0
                {
                    // Moving from our index toward the front of the array (i.e. the sorted part), checking to see if swaps are needed

                    if (innerCounter > 0)//	If the inner loop counter is greater than zero,
                    {
                        if (importList[innerCounter].CompareTo(importList[innerCounter - 1]) < 0)// AND the value[loop counter] is less than value[loop counter - 1]
                        {
                            
                            


                            // Swap
                            string temp = importList[innerCounter];
                            importList[innerCounter] = importList[innerCounter - 1];
                            importList[innerCounter - 1] = temp;
                            
                        }
                    }
                    innerCounter--;// Decrement the while loop counter


                }  



            }




        }
    }
}
