namespace Lab9_BrennanRodriguez
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
            this.MenuStrip_File = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuStrip_File_Open = new System.Windows.Forms.ToolStripMenuItem();
            this.txtBox_Search = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.listBox_DictionaryWords = new System.Windows.Forms.ListBox();
            this.richTxtBox_Definition = new System.Windows.Forms.RichTextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.MenuStrip_File});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(788, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // MenuStrip_File
            // 
            this.MenuStrip_File.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.MenuStrip_File_Open});
            this.MenuStrip_File.Name = "MenuStrip_File";
            this.MenuStrip_File.Size = new System.Drawing.Size(37, 20);
            this.MenuStrip_File.Text = "File";
            // 
            // MenuStrip_File_Open
            // 
            this.MenuStrip_File_Open.Name = "MenuStrip_File_Open";
            this.MenuStrip_File_Open.Size = new System.Drawing.Size(103, 22);
            this.MenuStrip_File_Open.Text = "Open";
            this.MenuStrip_File_Open.Click += new System.EventHandler(this.MenuStrip_File_Open_Click);
            // 
            // txtBox_Search
            // 
            this.txtBox_Search.Location = new System.Drawing.Point(13, 69);
            this.txtBox_Search.Name = "txtBox_Search";
            this.txtBox_Search.Size = new System.Drawing.Size(100, 20);
            this.txtBox_Search.TabIndex = 1;
            this.txtBox_Search.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtBox_Search_KeyPress);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(13, 50);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(99, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Enter text to search";
            // 
            // listBox_DictionaryWords
            // 
            this.listBox_DictionaryWords.FormattingEnabled = true;
            this.listBox_DictionaryWords.Location = new System.Drawing.Point(184, 69);
            this.listBox_DictionaryWords.Name = "listBox_DictionaryWords";
            this.listBox_DictionaryWords.Size = new System.Drawing.Size(153, 290);
            this.listBox_DictionaryWords.TabIndex = 3;
            this.listBox_DictionaryWords.SelectedIndexChanged += new System.EventHandler(this.listBox_DictionaryWords_SelectedIndexChanged);
            // 
            // richTxtBox_Definition
            // 
            this.richTxtBox_Definition.Location = new System.Drawing.Point(382, 69);
            this.richTxtBox_Definition.Name = "richTxtBox_Definition";
            this.richTxtBox_Definition.Size = new System.Drawing.Size(323, 290);
            this.richTxtBox_Definition.TabIndex = 4;
            this.richTxtBox_Definition.Text = "";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(184, 50);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(38, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "Words";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(379, 50);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(51, 13);
            this.label3.TabIndex = 6;
            this.label3.Text = "Definition";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(788, 424);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.richTxtBox_Definition);
            this.Controls.Add(this.listBox_DictionaryWords);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txtBox_Search);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem MenuStrip_File;
        private System.Windows.Forms.ToolStripMenuItem MenuStrip_File_Open;
        private System.Windows.Forms.TextBox txtBox_Search;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ListBox listBox_DictionaryWords;
        private System.Windows.Forms.RichTextBox richTxtBox_Definition;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
    }
}

