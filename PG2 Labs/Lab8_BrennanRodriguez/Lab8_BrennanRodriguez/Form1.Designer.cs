namespace Lab8_BrennanRodriguez
{
    partial class EmployeeInformation
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.radiobtn_AddPerson = new System.Windows.Forms.RadioButton();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label5 = new System.Windows.Forms.Label();
            this.upDown_Bonus = new System.Windows.Forms.NumericUpDown();
            this.label4 = new System.Windows.Forms.Label();
            this.upDown_Sal = new System.Windows.Forms.NumericUpDown();
            this.label3 = new System.Windows.Forms.Label();
            this.upDown_Age = new System.Windows.Forms.NumericUpDown();
            this.label2 = new System.Windows.Forms.Label();
            this.textBox_LastName = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.textBox_FirstName = new System.Windows.Forms.TextBox();
            this.btn_AddPerson = new System.Windows.Forms.Button();
            this.fontDialog1 = new System.Windows.Forms.FontDialog();
            this.box_Employees = new System.Windows.Forms.ListBox();
            this.btn_Remove = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.upDown_Bonus)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.upDown_Sal)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.upDown_Age)).BeginInit();
            this.SuspendLayout();
            // 
            // radiobtn_AddPerson
            // 
            this.radiobtn_AddPerson.AutoSize = true;
            this.radiobtn_AddPerson.Location = new System.Drawing.Point(17, 32);
            this.radiobtn_AddPerson.Name = "radiobtn_AddPerson";
            this.radiobtn_AddPerson.Size = new System.Drawing.Size(71, 17);
            this.radiobtn_AddPerson.TabIndex = 0;
            this.radiobtn_AddPerson.TabStop = true;
            this.radiobtn_AddPerson.Text = "Employee";
            this.radiobtn_AddPerson.UseVisualStyleBackColor = true;
            this.radiobtn_AddPerson.CheckedChanged += new System.EventHandler(this.radiobtn_AddPerson_CheckedChanged);
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Location = new System.Drawing.Point(127, 32);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(67, 17);
            this.radioButton2.TabIndex = 1;
            this.radioButton2.TabStop = true;
            this.radioButton2.Text = "Manager";
            this.radioButton2.UseVisualStyleBackColor = true;
            this.radioButton2.CheckedChanged += new System.EventHandler(this.radioButton2_CheckedChanged);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.upDown_Bonus);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.upDown_Sal);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.upDown_Age);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.textBox_LastName);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.textBox_FirstName);
            this.groupBox1.Controls.Add(this.radioButton2);
            this.groupBox1.Controls.Add(this.radiobtn_AddPerson);
            this.groupBox1.Location = new System.Drawing.Point(31, 19);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(218, 265);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Data Fields";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(33, 233);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(37, 13);
            this.label5.TabIndex = 11;
            this.label5.Text = "Bonus";
            // 
            // upDown_Bonus
            // 
            this.upDown_Bonus.DecimalPlaces = 2;
            this.upDown_Bonus.Location = new System.Drawing.Point(98, 233);
            this.upDown_Bonus.Maximum = new decimal(new int[] {
            50000,
            0,
            0,
            0});
            this.upDown_Bonus.Name = "upDown_Bonus";
            this.upDown_Bonus.Size = new System.Drawing.Size(96, 20);
            this.upDown_Bonus.TabIndex = 10;
            this.upDown_Bonus.ThousandsSeparator = true;
            this.upDown_Bonus.ValueChanged += new System.EventHandler(this.upDown_Bonus_ValueChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(98, 170);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(36, 13);
            this.label4.TabIndex = 9;
            this.label4.Text = "Salary";
            // 
            // upDown_Sal
            // 
            this.upDown_Sal.DecimalPlaces = 2;
            this.upDown_Sal.Location = new System.Drawing.Point(98, 189);
            this.upDown_Sal.Maximum = new decimal(new int[] {
            1000000,
            0,
            0,
            0});
            this.upDown_Sal.Name = "upDown_Sal";
            this.upDown_Sal.Size = new System.Drawing.Size(96, 20);
            this.upDown_Sal.TabIndex = 8;
            this.upDown_Sal.ThousandsSeparator = true;
            this.upDown_Sal.ValueChanged += new System.EventHandler(this.upDown_Sal_ValueChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(17, 170);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(26, 13);
            this.label3.TabIndex = 7;
            this.label3.Text = "Age";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // upDown_Age
            // 
            this.upDown_Age.Location = new System.Drawing.Point(17, 189);
            this.upDown_Age.Maximum = new decimal(new int[] {
            120,
            0,
            0,
            0});
            this.upDown_Age.Name = "upDown_Age";
            this.upDown_Age.Size = new System.Drawing.Size(52, 20);
            this.upDown_Age.TabIndex = 6;
            this.upDown_Age.ValueChanged += new System.EventHandler(this.upDown_Age_ValueChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(14, 122);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(58, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "Last Name";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // textBox_LastName
            // 
            this.textBox_LastName.Location = new System.Drawing.Point(17, 138);
            this.textBox_LastName.Name = "textBox_LastName";
            this.textBox_LastName.Size = new System.Drawing.Size(100, 20);
            this.textBox_LastName.TabIndex = 4;
            this.textBox_LastName.TextChanged += new System.EventHandler(this.textBox_LastName_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(14, 72);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(55, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "First name";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // textBox_FirstName
            // 
            this.textBox_FirstName.Location = new System.Drawing.Point(17, 88);
            this.textBox_FirstName.Name = "textBox_FirstName";
            this.textBox_FirstName.Size = new System.Drawing.Size(100, 20);
            this.textBox_FirstName.TabIndex = 2;
            this.textBox_FirstName.TextChanged += new System.EventHandler(this.textBox_FirstName_TextChanged);
            // 
            // btn_AddPerson
            // 
            this.btn_AddPerson.Location = new System.Drawing.Point(31, 300);
            this.btn_AddPerson.Name = "btn_AddPerson";
            this.btn_AddPerson.Size = new System.Drawing.Size(75, 34);
            this.btn_AddPerson.TabIndex = 3;
            this.btn_AddPerson.Text = "Add Person";
            this.btn_AddPerson.UseVisualStyleBackColor = true;
            this.btn_AddPerson.Click += new System.EventHandler(this.btn_AddPerson_Click);
            // 
            // box_Employees
            // 
            this.box_Employees.FormattingEnabled = true;
            this.box_Employees.Location = new System.Drawing.Point(270, 19);
            this.box_Employees.Name = "box_Employees";
            this.box_Employees.Size = new System.Drawing.Size(387, 264);
            this.box_Employees.TabIndex = 4;
            this.box_Employees.SelectedIndexChanged += new System.EventHandler(this.box_Employees_SelectedIndexChanged);
            // 
            // btn_Remove
            // 
            this.btn_Remove.Location = new System.Drawing.Point(132, 300);
            this.btn_Remove.Name = "btn_Remove";
            this.btn_Remove.Size = new System.Drawing.Size(92, 34);
            this.btn_Remove.TabIndex = 5;
            this.btn_Remove.Text = "Remove Person";
            this.btn_Remove.UseVisualStyleBackColor = true;
            this.btn_Remove.Click += new System.EventHandler(this.btn_Remove_Click);
            // 
            // EmployeeInformation
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(677, 346);
            this.Controls.Add(this.btn_Remove);
            this.Controls.Add(this.box_Employees);
            this.Controls.Add(this.btn_AddPerson);
            this.Controls.Add(this.groupBox1);
            this.Name = "EmployeeInformation";
            this.Text = "Employee Information";
            this.Load += new System.EventHandler(this.EmployeeInformation_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.upDown_Bonus)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.upDown_Sal)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.upDown_Age)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.RadioButton radiobtn_AddPerson;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBox_LastName;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBox_FirstName;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.NumericUpDown upDown_Age;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.NumericUpDown upDown_Bonus;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.NumericUpDown upDown_Sal;
        private System.Windows.Forms.Button btn_AddPerson;
        private System.Windows.Forms.FontDialog fontDialog1;
        private System.Windows.Forms.ListBox box_Employees;
        private System.Windows.Forms.Button btn_Remove;
    }
}

