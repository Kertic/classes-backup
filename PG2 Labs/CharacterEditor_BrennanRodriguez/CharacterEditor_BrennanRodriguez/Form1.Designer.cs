namespace CharacterEditor_BrennanRodriguez
{
    partial class Form1
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
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.toolstrip_File = new System.Windows.Forms.ToolStripMenuItem();
            this.toolstrip_File_New = new System.Windows.Forms.ToolStripMenuItem();
            this.toolstrip_File_Exit = new System.Windows.Forms.ToolStripMenuItem();
            this.toolstrip_Actions = new System.Windows.Forms.ToolStripMenuItem();
            this.toolstrip_Actions_Add = new System.Windows.Forms.ToolStripMenuItem();
            this.toolstrip_Actions_Remove = new System.Windows.Forms.ToolStripMenuItem();
            this.toolstrip_Actions_Update = new System.Windows.Forms.ToolStripMenuItem();
            this.gb_BasicInfo = new System.Windows.Forms.GroupBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.cb_Class = new System.Windows.Forms.ComboBox();
            this.cb_Race = new System.Windows.Forms.ComboBox();
            this.num_Age = new System.Windows.Forms.NumericUpDown();
            this.tb_LastName = new System.Windows.Forms.TextBox();
            this.tb_FirstName = new System.Windows.Forms.TextBox();
            this.gb_Stats = new System.Windows.Forms.GroupBox();
            this.label11 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.bt_Roll = new System.Windows.Forms.Button();
            this.num_Cha = new System.Windows.Forms.NumericUpDown();
            this.num_Wis = new System.Windows.Forms.NumericUpDown();
            this.num_Int = new System.Windows.Forms.NumericUpDown();
            this.num_Con = new System.Windows.Forms.NumericUpDown();
            this.num_Dex = new System.Windows.Forms.NumericUpDown();
            this.num_Str = new System.Windows.Forms.NumericUpDown();
            this.gb_ClassSpec = new System.Windows.Forms.GroupBox();
            this.lbl_Familiar = new System.Windows.Forms.Label();
            this.lbl_top = new System.Windows.Forms.Label();
            this.lbl_PetSize = new System.Windows.Forms.Label();
            this.cb_Familar = new System.Windows.Forms.ComboBox();
            this.lbl_bottom = new System.Windows.Forms.Label();
            this.num_Misc = new System.Windows.Forms.NumericUpDown();
            this.cb_PetRace = new System.Windows.Forms.ComboBox();
            this.cb_PetSize = new System.Windows.Forms.ComboBox();
            this.lb_Characters = new System.Windows.Forms.ListBox();
            this.menuStrip1.SuspendLayout();
            this.gb_BasicInfo.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.num_Age)).BeginInit();
            this.gb_Stats.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.num_Cha)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_Wis)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_Int)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_Con)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_Dex)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_Str)).BeginInit();
            this.gb_ClassSpec.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.num_Misc)).BeginInit();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolstrip_File,
            this.toolstrip_Actions});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(674, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // toolstrip_File
            // 
            this.toolstrip_File.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolstrip_File_New,
            this.toolstrip_File_Exit});
            this.toolstrip_File.Name = "toolstrip_File";
            this.toolstrip_File.Size = new System.Drawing.Size(37, 20);
            this.toolstrip_File.Text = "File";
            // 
            // toolstrip_File_New
            // 
            this.toolstrip_File_New.Name = "toolstrip_File_New";
            this.toolstrip_File_New.Size = new System.Drawing.Size(98, 22);
            this.toolstrip_File_New.Text = "New";
            this.toolstrip_File_New.Click += new System.EventHandler(this.toolstrip_File_New_Click);
            // 
            // toolstrip_File_Exit
            // 
            this.toolstrip_File_Exit.Name = "toolstrip_File_Exit";
            this.toolstrip_File_Exit.Size = new System.Drawing.Size(98, 22);
            this.toolstrip_File_Exit.Text = "Exit";
            // 
            // toolstrip_Actions
            // 
            this.toolstrip_Actions.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolstrip_Actions_Add,
            this.toolstrip_Actions_Remove,
            this.toolstrip_Actions_Update});
            this.toolstrip_Actions.Name = "toolstrip_Actions";
            this.toolstrip_Actions.Size = new System.Drawing.Size(59, 20);
            this.toolstrip_Actions.Text = "Actions";
            // 
            // toolstrip_Actions_Add
            // 
            this.toolstrip_Actions_Add.Name = "toolstrip_Actions_Add";
            this.toolstrip_Actions_Add.Size = new System.Drawing.Size(171, 22);
            this.toolstrip_Actions_Add.Text = "Add Character";
            this.toolstrip_Actions_Add.Click += new System.EventHandler(this.toolstrip_Actions_Add_Click);
            // 
            // toolstrip_Actions_Remove
            // 
            this.toolstrip_Actions_Remove.Name = "toolstrip_Actions_Remove";
            this.toolstrip_Actions_Remove.Size = new System.Drawing.Size(171, 22);
            this.toolstrip_Actions_Remove.Text = "Remove Character";
            this.toolstrip_Actions_Remove.Click += new System.EventHandler(this.toolstrip_Actions_Remove_Click);
            // 
            // toolstrip_Actions_Update
            // 
            this.toolstrip_Actions_Update.Name = "toolstrip_Actions_Update";
            this.toolstrip_Actions_Update.Size = new System.Drawing.Size(171, 22);
            this.toolstrip_Actions_Update.Text = "Update character";
            this.toolstrip_Actions_Update.Click += new System.EventHandler(this.toolstrip_Actions_Update_Click);
            // 
            // gb_BasicInfo
            // 
            this.gb_BasicInfo.Controls.Add(this.label5);
            this.gb_BasicInfo.Controls.Add(this.label4);
            this.gb_BasicInfo.Controls.Add(this.label3);
            this.gb_BasicInfo.Controls.Add(this.label2);
            this.gb_BasicInfo.Controls.Add(this.label1);
            this.gb_BasicInfo.Controls.Add(this.cb_Class);
            this.gb_BasicInfo.Controls.Add(this.cb_Race);
            this.gb_BasicInfo.Controls.Add(this.num_Age);
            this.gb_BasicInfo.Controls.Add(this.tb_LastName);
            this.gb_BasicInfo.Controls.Add(this.tb_FirstName);
            this.gb_BasicInfo.Location = new System.Drawing.Point(18, 37);
            this.gb_BasicInfo.Name = "gb_BasicInfo";
            this.gb_BasicInfo.Size = new System.Drawing.Size(192, 157);
            this.gb_BasicInfo.TabIndex = 1;
            this.gb_BasicInfo.TabStop = false;
            this.gb_BasicInfo.Text = "Basic Info";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(36, 124);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(32, 13);
            this.label5.TabIndex = 9;
            this.label5.Text = "Class";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(36, 97);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(33, 13);
            this.label4.TabIndex = 8;
            this.label4.Text = "Race";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(42, 71);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(26, 13);
            this.label3.TabIndex = 7;
            this.label3.Text = "Age";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(11, 45);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(58, 13);
            this.label2.TabIndex = 6;
            this.label2.Text = "Last Name";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(11, 19);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(57, 13);
            this.label1.TabIndex = 5;
            this.label1.Text = "First Name";
            // 
            // cb_Class
            // 
            this.cb_Class.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cb_Class.FormattingEnabled = true;
            this.cb_Class.Location = new System.Drawing.Point(74, 124);
            this.cb_Class.Name = "cb_Class";
            this.cb_Class.Size = new System.Drawing.Size(100, 21);
            this.cb_Class.TabIndex = 4;
            this.cb_Class.SelectedIndexChanged += new System.EventHandler(this.cb_Class_SelectedIndexChanged);
            // 
            // cb_Race
            // 
            this.cb_Race.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cb_Race.FormattingEnabled = true;
            this.cb_Race.Location = new System.Drawing.Point(74, 97);
            this.cb_Race.Name = "cb_Race";
            this.cb_Race.Size = new System.Drawing.Size(100, 21);
            this.cb_Race.TabIndex = 3;
            this.cb_Race.SelectedIndexChanged += new System.EventHandler(this.cb_Race_SelectedIndexChanged);
            // 
            // num_Age
            // 
            this.num_Age.Location = new System.Drawing.Point(74, 71);
            this.num_Age.Name = "num_Age";
            this.num_Age.Size = new System.Drawing.Size(100, 20);
            this.num_Age.TabIndex = 2;
            this.num_Age.ValueChanged += new System.EventHandler(this.num_Age_ValueChanged);
            // 
            // tb_LastName
            // 
            this.tb_LastName.Location = new System.Drawing.Point(74, 45);
            this.tb_LastName.Name = "tb_LastName";
            this.tb_LastName.Size = new System.Drawing.Size(100, 20);
            this.tb_LastName.TabIndex = 1;
            this.tb_LastName.TextChanged += new System.EventHandler(this.tb_LastName_TextChanged);
            // 
            // tb_FirstName
            // 
            this.tb_FirstName.Location = new System.Drawing.Point(74, 19);
            this.tb_FirstName.Name = "tb_FirstName";
            this.tb_FirstName.Size = new System.Drawing.Size(100, 20);
            this.tb_FirstName.TabIndex = 0;
            this.tb_FirstName.TextChanged += new System.EventHandler(this.tb_FirstName_TextChanged);
            // 
            // gb_Stats
            // 
            this.gb_Stats.Controls.Add(this.label11);
            this.gb_Stats.Controls.Add(this.label10);
            this.gb_Stats.Controls.Add(this.label9);
            this.gb_Stats.Controls.Add(this.label8);
            this.gb_Stats.Controls.Add(this.label7);
            this.gb_Stats.Controls.Add(this.label6);
            this.gb_Stats.Controls.Add(this.bt_Roll);
            this.gb_Stats.Controls.Add(this.num_Cha);
            this.gb_Stats.Controls.Add(this.num_Wis);
            this.gb_Stats.Controls.Add(this.num_Int);
            this.gb_Stats.Controls.Add(this.num_Con);
            this.gb_Stats.Controls.Add(this.num_Dex);
            this.gb_Stats.Controls.Add(this.num_Str);
            this.gb_Stats.Location = new System.Drawing.Point(18, 200);
            this.gb_Stats.Name = "gb_Stats";
            this.gb_Stats.Size = new System.Drawing.Size(192, 215);
            this.gb_Stats.TabIndex = 2;
            this.gb_Stats.TabStop = false;
            this.gb_Stats.Text = "Stats";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(21, 125);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(45, 13);
            this.label11.TabIndex = 12;
            this.label11.Text = "Wisdom";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(18, 151);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(50, 13);
            this.label10.TabIndex = 11;
            this.label10.Text = "Charisma";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(7, 97);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(61, 13);
            this.label9.TabIndex = 10;
            this.label9.Text = "Intelligence";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(7, 73);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(62, 13);
            this.label8.TabIndex = 9;
            this.label8.Text = "Constitution";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(18, 47);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(48, 13);
            this.label7.TabIndex = 8;
            this.label7.Text = "Dexterity";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(19, 21);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(47, 13);
            this.label6.TabIndex = 7;
            this.label6.Text = "Strength";
            // 
            // bt_Roll
            // 
            this.bt_Roll.Location = new System.Drawing.Point(45, 175);
            this.bt_Roll.Name = "bt_Roll";
            this.bt_Roll.Size = new System.Drawing.Size(75, 23);
            this.bt_Roll.TabIndex = 6;
            this.bt_Roll.Text = "Roll";
            this.bt_Roll.UseVisualStyleBackColor = true;
            this.bt_Roll.Click += new System.EventHandler(this.bt_Roll_Click);
            // 
            // num_Cha
            // 
            this.num_Cha.Location = new System.Drawing.Point(72, 149);
            this.num_Cha.Name = "num_Cha";
            this.num_Cha.Size = new System.Drawing.Size(120, 20);
            this.num_Cha.TabIndex = 5;
            this.num_Cha.ValueChanged += new System.EventHandler(this.num_Cha_ValueChanged);
            // 
            // num_Wis
            // 
            this.num_Wis.Location = new System.Drawing.Point(72, 123);
            this.num_Wis.Name = "num_Wis";
            this.num_Wis.Size = new System.Drawing.Size(120, 20);
            this.num_Wis.TabIndex = 4;
            this.num_Wis.ValueChanged += new System.EventHandler(this.num_Wis_ValueChanged);
            // 
            // num_Int
            // 
            this.num_Int.Location = new System.Drawing.Point(72, 97);
            this.num_Int.Name = "num_Int";
            this.num_Int.Size = new System.Drawing.Size(120, 20);
            this.num_Int.TabIndex = 3;
            this.num_Int.ValueChanged += new System.EventHandler(this.num_Int_ValueChanged);
            // 
            // num_Con
            // 
            this.num_Con.Location = new System.Drawing.Point(72, 71);
            this.num_Con.Name = "num_Con";
            this.num_Con.Size = new System.Drawing.Size(120, 20);
            this.num_Con.TabIndex = 2;
            this.num_Con.ValueChanged += new System.EventHandler(this.num_Con_ValueChanged);
            // 
            // num_Dex
            // 
            this.num_Dex.Location = new System.Drawing.Point(72, 45);
            this.num_Dex.Name = "num_Dex";
            this.num_Dex.Size = new System.Drawing.Size(120, 20);
            this.num_Dex.TabIndex = 1;
            this.num_Dex.ValueChanged += new System.EventHandler(this.num_Dex_ValueChanged);
            // 
            // num_Str
            // 
            this.num_Str.Location = new System.Drawing.Point(72, 19);
            this.num_Str.Name = "num_Str";
            this.num_Str.Size = new System.Drawing.Size(120, 20);
            this.num_Str.TabIndex = 0;
            this.num_Str.ValueChanged += new System.EventHandler(this.num_Str_ValueChanged);
            // 
            // gb_ClassSpec
            // 
            this.gb_ClassSpec.Controls.Add(this.lbl_Familiar);
            this.gb_ClassSpec.Controls.Add(this.lbl_top);
            this.gb_ClassSpec.Controls.Add(this.lbl_PetSize);
            this.gb_ClassSpec.Controls.Add(this.cb_Familar);
            this.gb_ClassSpec.Controls.Add(this.lbl_bottom);
            this.gb_ClassSpec.Controls.Add(this.num_Misc);
            this.gb_ClassSpec.Controls.Add(this.cb_PetRace);
            this.gb_ClassSpec.Controls.Add(this.cb_PetSize);
            this.gb_ClassSpec.Location = new System.Drawing.Point(18, 421);
            this.gb_ClassSpec.Name = "gb_ClassSpec";
            this.gb_ClassSpec.Size = new System.Drawing.Size(192, 101);
            this.gb_ClassSpec.TabIndex = 3;
            this.gb_ClassSpec.TabStop = false;
            this.gb_ClassSpec.Text = "Class Specific";
            // 
            // lbl_Familiar
            // 
            this.lbl_Familiar.AutoSize = true;
            this.lbl_Familiar.Location = new System.Drawing.Point(11, 75);
            this.lbl_Familiar.Name = "lbl_Familiar";
            this.lbl_Familiar.Size = new System.Drawing.Size(40, 13);
            this.lbl_Familiar.TabIndex = 10;
            this.lbl_Familiar.Text = "Familar";
            this.lbl_Familiar.Visible = false;
            // 
            // lbl_top
            // 
            this.lbl_top.AutoSize = true;
            this.lbl_top.Location = new System.Drawing.Point(26, 22);
            this.lbl_top.Name = "lbl_top";
            this.lbl_top.Size = new System.Drawing.Size(62, 13);
            this.lbl_top.TabIndex = 1;
            this.lbl_top.Text = "DefaultText";
            // 
            // lbl_PetSize
            // 
            this.lbl_PetSize.AutoSize = true;
            this.lbl_PetSize.Location = new System.Drawing.Point(112, 75);
            this.lbl_PetSize.Name = "lbl_PetSize";
            this.lbl_PetSize.Size = new System.Drawing.Size(46, 13);
            this.lbl_PetSize.TabIndex = 8;
            this.lbl_PetSize.Text = "Pet Size";
            this.lbl_PetSize.Visible = false;
            // 
            // cb_Familar
            // 
            this.cb_Familar.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cb_Familar.FormattingEnabled = true;
            this.cb_Familar.Location = new System.Drawing.Point(10, 72);
            this.cb_Familar.Name = "cb_Familar";
            this.cb_Familar.Size = new System.Drawing.Size(79, 21);
            this.cb_Familar.TabIndex = 9;
            this.cb_Familar.SelectedIndexChanged += new System.EventHandler(this.cb_Familar_SelectedIndexChanged);
            // 
            // lbl_bottom
            // 
            this.lbl_bottom.AutoSize = true;
            this.lbl_bottom.Location = new System.Drawing.Point(19, 45);
            this.lbl_bottom.Name = "lbl_bottom";
            this.lbl_bottom.Size = new System.Drawing.Size(70, 13);
            this.lbl_bottom.TabIndex = 6;
            this.lbl_bottom.Text = "Default text 2";
            // 
            // num_Misc
            // 
            this.num_Misc.Location = new System.Drawing.Point(107, 19);
            this.num_Misc.Name = "num_Misc";
            this.num_Misc.Size = new System.Drawing.Size(79, 20);
            this.num_Misc.TabIndex = 0;
            this.num_Misc.ValueChanged += new System.EventHandler(this.num_Misc_ValueChanged);
            // 
            // cb_PetRace
            // 
            this.cb_PetRace.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cb_PetRace.FormattingEnabled = true;
            this.cb_PetRace.Location = new System.Drawing.Point(107, 45);
            this.cb_PetRace.Name = "cb_PetRace";
            this.cb_PetRace.Size = new System.Drawing.Size(79, 21);
            this.cb_PetRace.TabIndex = 5;
            this.cb_PetRace.SelectedIndexChanged += new System.EventHandler(this.cb_PetRace_SelectedIndexChanged);
            // 
            // cb_PetSize
            // 
            this.cb_PetSize.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cb_PetSize.FormattingEnabled = true;
            this.cb_PetSize.Location = new System.Drawing.Point(95, 72);
            this.cb_PetSize.Name = "cb_PetSize";
            this.cb_PetSize.Size = new System.Drawing.Size(79, 21);
            this.cb_PetSize.TabIndex = 7;
            this.cb_PetSize.SelectedIndexChanged += new System.EventHandler(this.cb_PetSize_SelectedIndexChanged);
            // 
            // lb_Characters
            // 
            this.lb_Characters.FormattingEnabled = true;
            this.lb_Characters.Location = new System.Drawing.Point(230, 37);
            this.lb_Characters.Name = "lb_Characters";
            this.lb_Characters.Size = new System.Drawing.Size(247, 485);
            this.lb_Characters.TabIndex = 4;
            this.lb_Characters.SelectedIndexChanged += new System.EventHandler(this.lb_Characters_SelectedIndexChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(674, 529);
            this.Controls.Add(this.lb_Characters);
            this.Controls.Add(this.gb_ClassSpec);
            this.Controls.Add(this.gb_Stats);
            this.Controls.Add(this.gb_BasicInfo);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Character Editor";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.gb_BasicInfo.ResumeLayout(false);
            this.gb_BasicInfo.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.num_Age)).EndInit();
            this.gb_Stats.ResumeLayout(false);
            this.gb_Stats.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.num_Cha)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_Wis)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_Int)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_Con)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_Dex)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_Str)).EndInit();
            this.gb_ClassSpec.ResumeLayout(false);
            this.gb_ClassSpec.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.num_Misc)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem toolstrip_File;
        private System.Windows.Forms.ToolStripMenuItem toolstrip_File_New;
        private System.Windows.Forms.ToolStripMenuItem toolstrip_File_Exit;
        private System.Windows.Forms.ToolStripMenuItem toolstrip_Actions;
        private System.Windows.Forms.ToolStripMenuItem toolstrip_Actions_Add;
        private System.Windows.Forms.ToolStripMenuItem toolstrip_Actions_Remove;
        private System.Windows.Forms.ToolStripMenuItem toolstrip_Actions_Update;
        private System.Windows.Forms.GroupBox gb_BasicInfo;
        private System.Windows.Forms.GroupBox gb_Stats;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox cb_Class;
        private System.Windows.Forms.ComboBox cb_Race;
        private System.Windows.Forms.NumericUpDown num_Age;
        private System.Windows.Forms.TextBox tb_LastName;
        private System.Windows.Forms.TextBox tb_FirstName;
        private System.Windows.Forms.GroupBox gb_ClassSpec;
        private System.Windows.Forms.ListBox lb_Characters;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button bt_Roll;
        private System.Windows.Forms.NumericUpDown num_Cha;
        private System.Windows.Forms.NumericUpDown num_Wis;
        private System.Windows.Forms.NumericUpDown num_Int;
        private System.Windows.Forms.NumericUpDown num_Con;
        private System.Windows.Forms.NumericUpDown num_Dex;
        private System.Windows.Forms.NumericUpDown num_Str;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label lbl_top;
        private System.Windows.Forms.NumericUpDown num_Misc;
        private System.Windows.Forms.ComboBox cb_PetRace;
        private System.Windows.Forms.Label lbl_bottom;
        private System.Windows.Forms.ComboBox cb_PetSize;
        private System.Windows.Forms.Label lbl_PetSize;
        private System.Windows.Forms.ComboBox cb_Familar;
        private System.Windows.Forms.Label lbl_Familiar;
    }
}

