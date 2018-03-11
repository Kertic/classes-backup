using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Lab5_BrennanRodriguez
{
    class NumList
    {
        List<string[]> mList;
        Dictionary<string, int> mDict;

        public NumList()
        {
            mList = new List<string[]>();
            mDict = new Dictionary<string, int>();
        }

        public void LoadList(string filename)
        {
            StreamReader reader = new StreamReader(filename);

            while (!reader.EndOfStream)
            {
                string readline = reader.ReadLine();
                string[] readlineArray = readline.Split('|');
                string type = readlineArray[0];
                string value = readlineArray[1];
                string[] output = { type, value };
                mList.Add(output);


            }

            reader.Close();
        }

        public void LoadDict(string filename)
        {
            StreamReader reader = new StreamReader(filename);

            while (!reader.EndOfStream)
            {
                string readline = reader.ReadLine();
                string[] readlineArray = readline.Split('|');
                string type = readlineArray[0];
                int value = int.Parse(readlineArray[1]);

                mDict.Add(type, value);



            }

            reader.Close();
        }

        public void SearchList(string query)
        {
            int numFound = 0;
            for (int i = 0; i < mList.Count; i++)
            {
                for (int j = 0; j < mList[i].Length; j++)
                {
                    if (mList[i][j].Contains(query))
                    {
                        Console.WriteLine("Type: " + mList[i][0] + " Value: " + mList[i][1]);
                        numFound++;

                    }
                }
                

            }
            Console.WriteLine(numFound + " entries found.");
            

        }

        public void SearchListExact(string query)
        {
            for (int i = 0; i < mList.Count; i++)
            {


                if (mList[i][0] == query)
                {
                    Console.WriteLine("Type: " + mList[i][0] + " Value: " + mList[i][1]);

                }

            }
        }

        public void SearchDict(string query)
        {
            int numfound = 0;
            foreach (KeyValuePair<string, int> entry in mDict)
            {
                if (entry.Key.Contains(query))
                {
                    Console.WriteLine("Type: " + entry.Key + " Value: " + entry.Value);
                    numfound++;

                }
                

            }
            Console.WriteLine("Entries found: " + numfound);

         
        }

        public void SearchDictExact(string query)
        {
            foreach (KeyValuePair<string, int> entry in mDict)
            {
                if (entry.Key.Equals(query) == true)
                {
                    Console.WriteLine("Type: " + entry.Key + " Value: " + entry.Value);
                    

                }


            }

        }


    }
}
