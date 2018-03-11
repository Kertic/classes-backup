using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab8_BrennanRodriguez
{
    public partial class EmployeeInformation : Form
    {
        List<Employee> mlist = new List<Employee>();
        bool isEmployee = true;
        int inAge = 0;
        float inSal = 0.0f;
        float inBonus = 0.0f;
        string inFirst = "";
        string inLast = "";
        
        bool isBlank = true;
       
        
        

        public EmployeeInformation()
        {
            InitializeComponent();
        }

        private void radiobtn_AddPerson_CheckedChanged(object sender, EventArgs e)
        {
            if (radiobtn_AddPerson.Checked)
            {
                upDown_Bonus.Enabled = false;
                isEmployee = true;     
                
            }
            if (!radiobtn_AddPerson.Checked)
            {
                upDown_Bonus.Enabled = true;
                isEmployee = false;
            }

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void EmployeeInformation_Load(object sender, EventArgs e)
        {

        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void btn_AddPerson_Click(object sender, EventArgs e)
        {
            if (isEmployee && !isBlank)
            {
                mlist.Add(new Employee(inAge, inSal, inFirst, inLast));
                string name = ("(Employee) " + " Name: " + inFirst + " " + inLast + " Age: " + inAge + "Salary: " + inSal);
                box_Employees.Items.Add(name);
                
                ClearFields();
                isBlank = true;

                
            }
            if (!isEmployee && !isBlank)
            {
                mlist.Add(new Manager(inAge, inSal, inFirst, inLast, inBonus));
                string name = ("(Manager)" + " Name: " + inFirst + " " + inLast + " Age: " + inAge + "Salary: " + inSal);
                box_Employees.Items.Add(name);
                
                ClearFields();
                isBlank = true;
            }


        }

        private void upDown_Age_ValueChanged(object sender, EventArgs e)
        {
            inAge = (int)upDown_Age.Value;
            isBlank = false;
        }

        private void box_Employees_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void textBox_FirstName_TextChanged(object sender, EventArgs e)
        {
            inFirst = textBox_FirstName.Text;
            isBlank = false;
            

        }

        private void textBox_LastName_TextChanged(object sender, EventArgs e)
        {
            inLast = textBox_LastName.Text;
            isBlank = false;

        }

        private void upDown_Sal_ValueChanged(object sender, EventArgs e)
        {
            inSal = (float)upDown_Sal.Value;
            isBlank = false;
            
        }

        private void upDown_Bonus_ValueChanged(object sender, EventArgs e)
        {
            inBonus = (float)upDown_Bonus.Value;
            isBlank = false;
        }
        public void ClearFields()
        {
            upDown_Age.Value = 0;
            upDown_Bonus.Value = 0;
            upDown_Sal.Value = 0;
            textBox_FirstName.Text = "";
            textBox_LastName.Text = "";
        }

        private void btn_Remove_Click(object sender, EventArgs e)
        {
            
            box_Employees.Items.Remove(box_Employees.SelectedItem);
            

            
        }
    }


}
