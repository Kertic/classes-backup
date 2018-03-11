/* Addresses are stored locally as a list<string[]>
 *                          string[] is (name, street number, street name, city, state, zip)
 * 
 * Have a menu:
 * Add entry
 *      Goes directly to menu prompts to add
 *          Asks what the name is, asks what the street, asks what number, asks what city, asks for state, asks for zip
 *          listobject.Add(list<string> )
 *          

 * Remove entry
 *      Displays a list, and asks what entry to delete by entry number
 *      
 *      for list.count{
 *          write "\n"
 *          for list[i].length - 1   {
 *              
 *              write list[i][j];
 *              }
 *              write list[i] last spot
 *              write "."
 *      }
 *              
 * Edit entry
 *      Displays a list, and asks what entry to edit.
 *          Asks to enter updated information
 *          
 * Export list  
 *      Ask what to save the file as (only CSV will be accepted, ext is .adb for address book)
 *      Export lists in 1 line per entry, different pieces seperated by ","
 *      
 *          streamwriter writer writeline (name + , + number + , + street + , city + , + state + , + zip)
 *          writer.close();
 * Import list
 *      Search for the file name, and add .adb to it. 
 *      Read each line, with each line being seperated by commas
 *      import them into the current address book
*          streamreader reader 
 *      while(!reader.EndOfStream)
 
 *          string input = reader.Readline();
 *          string inputArray = input.Split();
 *          bool IsDuplicate = false;
 *          int NumDupes = 0;
 *          for list.count{
 *              if inputArray == list[i]
 *                  IsDuplicate = true;
 *                  NumDupes++;
 *          }
 *          if (IsDuplicate == false){
 *              list.Add(inputarray);
 *          } 
 *          writeline NumDupes + " duplicates found. Those were not imported.";
 *     reader.close();
 * Search list
 *      Tell them to input any set of data, and we will search the list and add them to a temporary list. Display the temporary list.
 *          List<string[]> SearchResults = new list
 *          int numFound = 0;
 *          for list.count
 *              for list[i].length
 *                  if list[i][j] == query
 *                  SearchResults.Add(list[i]);
 *                  numFound++;
 *                  break;
 *               
 *               
 *          //Out of the for loops
 *          Console.WriteLine(numFound + " entries found.");  
 *          for SearchResults.Count
 *              Console.Writeline();
 *              for SearchResults[i].Length
 *                  Console.Writeline(SearchResults[i][j]);
 *                  
 *                     
 *                  
 *          
 * Sort list
 *      Ask what field to sort by
 *      1 = name
 *      2 = address number
 *      3 = stree name
 *      4 = city
 *      5 = state
 *      6 = zip
 *          while (true)
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
                        while (true){
                            bool swapped = false;
                            for list.count - 1{
                                if (list[i][input - 1].Compareto(list[i + 1][input - 1]) > 0){
                                    //Swap them
                                    //Mark swapped as true
                                }
                            }
                            if (swapped == false){
                                break;
                            }
                        }
                        Console.WriteLine("List sorted by option " + input);
                        Tools.PressAnyKey();


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
 *      
 *      
 *      
 *      
 *      
 *      
 *      
 *      
 *      
 *      
 *      
 *      
 *      
 *      
 *      
 *      
 *      
 *      
 *      
 *      
 *      
 *      
 *      
 *      
 *      
 *      
 *      
 *      
 *                                                                                                     
 *      
 *          
 * Display list
 *      Display all items in the list
 *                  for (int i = 0; i < mAddressList.Count; i++)
            {
                Console.WriteLine(i + ". ");
                for (int j = 0; j < mAddressList[i].Length; j++)
                {
                    Console.WriteLine(mAddressList[i][j]);

                }
            }
 *      
 *      
 * Menu class
 *      public MainMenu()
 *          a while loop, with a try catch. Before the user can make a choice, input is set to 0. Each option launches the proper function. 
 *          The catch will ask them to re-enter their input.
 *          
 * 
 * 
 * 
 * 
 * 
 * 
 */



