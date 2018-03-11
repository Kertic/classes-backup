using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace Lab9_BrennanRodriguez
{
    public partial class Form1 : Form
    {
        Dictionary<string, string> dict_A = new Dictionary<string, string>();
        public Form1()
        {
            InitializeComponent();
            MessageBox.Show("Both the program and the example mess up on \"Aaron's rod\" Due to the fact that the word has a space in it", "Error with the example and mine", MessageBoxButtons.OK, MessageBoxIcon.Information);
             
            
            

        }

        

        private void MenuStrip_File_Open_Click(object sender, EventArgs e)
        {
            OpenFileDialog open = new OpenFileDialog();
            open.Filter = "Text files (*.txt)|*.txt";
            open.Filter += "|Dictionary files (*.dcf)|*.dcf";

            if (open.ShowDialog() == DialogResult.OK)
            {
                dict_A.Clear();

                if (open.FilterIndex == 1 || open.FilterIndex == 2)
                {
                    ReadFileToDictionary(open);

                }

            }
            listBox_DictionaryWords.Items.Clear();
            foreach (string k in dict_A.Keys)
            {
                listBox_DictionaryWords.Items.Add(k);
            }

            
            
           
        }

        private void ReadFileToDictionary(OpenFileDialog open)
        {
            StreamReader reader = new StreamReader(open.FileName);
            char[] charSep = { ' ' };
            while (!reader.EndOfStream)
            {
                string line = reader.ReadLine();

                if (line != "")//If its not blank
                {
                    string[] splitline = line.Split(charSep, 2);
                   
                    if (dict_A.ContainsKey(splitline[0]))//If we already have a key for that word
                    {
                        dict_A[splitline[0]] += splitline[1];//Add the definition to the value
                    }
                    else
                    {
                        dict_A.Add(splitline[0], splitline[1]);//Add the word and definition
                    }
                    
                    


                }
                
                
            }

            reader.Close();
        }

        private void txtBox_Search_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)Keys.Enter)
            {
                listBox_DictionaryWords.Items.Clear();
                string query = txtBox_Search.Text.ToLower();
                foreach (string k in dict_A.Keys)
                {
                    if (k.ToLower().Contains(query))
                    {
                        listBox_DictionaryWords.Items.Add(k);
                    }
                }
            }
        }

        private void listBox_DictionaryWords_SelectedIndexChanged(object sender, EventArgs e)
        {
            richTxtBox_Definition.Clear();
            richTxtBox_Definition.Text = dict_A[(string)listBox_DictionaryWords.SelectedItem];
        }
    }
}
