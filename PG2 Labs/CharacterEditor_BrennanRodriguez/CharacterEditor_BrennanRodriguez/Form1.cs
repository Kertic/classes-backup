using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CharacterEditor_BrennanRodriguez
{//TODO
 //Finish the update and remove buttons
 //Add in the class specific stuff

    
    public partial class Form1 : Form
    {
        int top_xLabelPos = 0;
        int top_yLabelPos = 0;
        int bottom_xLabelPos = 0;
        int bottom_yLabelPos = 0;

        int top_xMenuPos = 0;
        int top_yMenuPos = 0;
        int bottom_xMenuPos = 0;
        int bottom_yMenuPos = 0;
        int finalWidth = 540;
        int finalHeight = 568;
        //These are the places to move the menu's to at the beginning

        List<Character> toons = new List<Character>();
        string mFirstName = "";
        string mLastName = "";
        int mAge = 0;
        Character.Race mRace = Character.Race.Default;
        Character.Class mClass = Character.Class.Default;
        int mStr = 0;
        int mDex = 0;
        int mCon = 0;
        int mInt = 0;
        int mWis = 0;
        int mCha = 0;
        int miscNum = 0;
        PetRace mPetRace = PetRace.Default;
        PetSize mPetSize = PetSize.Default;
        FamiliarRace mFamRace = FamiliarRace.Default;

        public enum PetRace
        {
            Default,
            Bear,
            Cat,
            Hawk,
            Wolf
        }
        public enum FamiliarRace
        {
            Default,
            Bat,
            Owl,
            Toad
        }
        public enum PetSize
        {
            Default,
            Small,
            Medium,
            Large
        }
        private void toolstrip_File_New_Click(object sender, EventArgs e)
        {
            lb_Characters.Items.Clear();
            toons.Clear();
            restartFields();

        }

        public Form1()//Place innitializing things here
        {
            InitializeComponent();
            this.Width = finalWidth;
            this.Height = finalHeight;
            top_xLabelPos = lbl_top.Left;
            top_yLabelPos = lbl_top.Top;
            bottom_xLabelPos = lbl_bottom.Left;
            bottom_yLabelPos = lbl_bottom.Top;

            top_xMenuPos = num_Misc.Left;
            top_yMenuPos = num_Misc.Top;
            bottom_xMenuPos = cb_PetRace.Left;
            bottom_yMenuPos = cb_PetRace.Top;

            cb_Race.DataSource = Enum.GetValues(typeof(Character.Race));
            cb_Class.DataSource = Enum.GetValues(typeof(Character.Class));
            cb_Familar.DataSource = Enum.GetValues(typeof(Form1.FamiliarRace));
            cb_Familar.Top = cb_PetRace.Top;
            cb_Familar.Left = cb_PetRace.Left;
            cb_Familar.Visible = false;
            cb_PetSize.DataSource = Enum.GetValues(typeof(Form1.PetSize));
            cb_PetSize.Top = cb_PetRace.Top;
            cb_PetSize.Left = cb_PetRace.Left;
            cb_PetSize.Visible = false;
            cb_PetRace.DataSource = Enum.GetValues(typeof(Form1.PetRace));
            cb_PetRace.Top = num_Misc.Top;
            cb_PetRace.Left = num_Misc.Left;
            cb_PetRace.Visible = false;
            num_Misc.Visible = false;
            lbl_top.Visible = false;
            lbl_bottom.Visible = false;





        }
        

        private void toolstrip_Actions_Add_Click(object sender, EventArgs e)
        {
            if (tb_FirstName.Text != "" && tb_LastName.Text != "")
            {
                if (cb_Race.Text != "Default" && cb_Class.Text != "Default")
                {//error checking done, Actually add the character
                    
                    switch (cb_Race.Text)
                    {
                        case "Dwarf":
                            mRace = Character.Race.Dwarf;
                            break;
                        case "Elf":
                            mRace = Character.Race.Elf;
                            break;
                        case "Gnome":
                            mRace = Character.Race.Gnome;
                            break;
                        case "HalfElf":
                            mRace = Character.Race.HalfElf;
                            break;
                        case "HalfOrc":
                            mRace = Character.Race.HalfOrc;
                            break;
                        case "Halfling":
                            mRace = Character.Race.Halfling;
                            break;
                        case "Human":
                            mRace = Character.Race.Human;
                            break;
                        default:
                            break;
                    }
                    switch (cb_Class.Text)
                    {
                        
                        case "Druid":
                            
                            if (cb_PetRace.Text != "Default")
                            {
                                mClass = Character.Class.Druid;
                                toons.Add(new Druid(mFirstName, mLastName, mAge, mStr, mDex, mCon, mInt, mWis, mCha, mRace, mClass, mPetRace));
                                lb_Characters.Items.Add(toons[toons.Count - 1]);//Add the last object in the toons object

                            }
                            else
                            {
                                MessageBox.Show("Please enter a pet race", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                            }

                            break;
                        case "Cleric":
                            
                            

                            
                            mClass = Character.Class.Cleric;
                            toons.Add(new Cleric(mFirstName, mLastName, mAge, mStr, mDex, mCon, mInt, mWis, mCha, mRace, mClass, miscNum));
                            lb_Characters.Items.Add(toons[toons.Count - 1]);//Add the last object in the toons object
                            break;
                        case "Fighter":
                            mClass = Character.Class.Fighter;
                            toons.Add(new Fighter(mFirstName, mLastName, mAge, mStr, mDex, mCon, mInt, mWis, mCha, mRace, mClass, miscNum));
                            lb_Characters.Items.Add(toons[toons.Count - 1]);//Add the last object in the toons object
                            break;
                        case "Monk":
                            mClass = Character.Class.Monk;
                            toons.Add(new Monk(mFirstName, mLastName, mAge, mStr, mDex, mCon, mInt, mWis, mCha, mRace, mClass, miscNum));
                            lb_Characters.Items.Add(toons[toons.Count - 1]);//Add the last object in the toons object
                            break;
                        case "Paladin":
                            mClass = Character.Class.Paladin;
                            toons.Add(new Paladin(mFirstName, mLastName, mAge, mStr, mDex, mCon, mInt, mWis, mCha, mRace, mClass, miscNum));
                            lb_Characters.Items.Add(toons[toons.Count - 1]);//Add the last object in the toons object
                            break;
                        case "Ranger":
                            if (cb_PetRace.Text != "Default" && cb_PetSize.Text != "Default")
                            {
                                mClass = Character.Class.Ranger;
                                toons.Add(new Ranger(mFirstName, mLastName, mAge, mStr, mDex, mCon, mInt, mWis, mCha, mRace, mClass, mPetRace, mPetSize));
                                lb_Characters.Items.Add(toons[toons.Count - 1]);//Add the last object in the toons object

                            }
                            else
                            {
                                MessageBox.Show("Please enter a pet race and a pet size", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                            }

                            break;
                        case "Rogue":
                            mClass = Character.Class.Rogue;
                            toons.Add(new Rogue(mFirstName, mLastName, mAge, mStr, mDex, mCon, mInt, mWis, mCha, mRace, mClass, miscNum));
                            lb_Characters.Items.Add(toons[toons.Count - 1]);//Add the last object in the toons object
                            break;
                        case "Sorcerer":
                            mClass = Character.Class.Sorcerer;
                            toons.Add(new Sorcerer(mFirstName, mLastName, mAge, mStr, mDex, mCon, mInt, mWis, mCha, mRace, mClass, miscNum));
                            lb_Characters.Items.Add(toons[toons.Count - 1]);//Add the last object in the toons object
                            break;
                        case "Wizard":
                            if (cb_Familar.Text != "Default")
                            {
                                mClass = Character.Class.Wizard;
                                toons.Add(new Wizard(mFirstName, mLastName, mAge, mStr, mDex, mCon, mInt, mWis, mCha, mRace, mClass, miscNum, mFamRace));
                                lb_Characters.Items.Add(toons[toons.Count - 1]);//Add the last object in the toons object

                            }
                            else
                            {
                                MessageBox.Show("Please enter a familiar race", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                            }

                            break;
                        case "scat man":
                            //ba booda boop scaddada sca doo da boop
                            break;
                        default:
                            break;
                        
                    }




                    restartFields();
                     mFirstName = "";
                     mLastName = "";
                     mAge = 0;
                     mRace = Character.Race.Default;
                     mClass = Character.Class.Default;
                     mStr = 0;
                     mDex = 0;
                     mCon = 0;
                     mInt = 0;
                     mWis = 0;
                     mCha = 0;
                     miscNum = 0;
                    lb_Characters.ClearSelected();

                }
                else
                {
                    MessageBox.Show("Please enter both a race and a class", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }

            }
            else
            {
                MessageBox.Show("Please enter both a first and last name", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        public void restartFields()
        {
            tb_FirstName.Clear();
            tb_LastName.Clear();
            cb_Race.SelectedIndex = 0;
            cb_Class.SelectedIndex = 0;
            num_Age.Value = 0;
            num_Str.Value = 0;
            num_Dex.Value = 0;
            num_Con.Value = 0;
            num_Int.Value = 0;
            num_Wis.Value = 0;
            num_Cha.Value = 0;
            cb_PetRace.SelectedIndex = 0;
            cb_PetSize.SelectedIndex = 0;
            cb_Familar.SelectedIndex = 0;

        }

        private void tb_FirstName_TextChanged(object sender, EventArgs e)
        {
            mFirstName = tb_FirstName.Text;
        }

        private void tb_LastName_TextChanged(object sender, EventArgs e)
        {
            mLastName = tb_LastName.Text;
        }

        private void num_Age_ValueChanged(object sender, EventArgs e)
        {
            mAge = (int)num_Age.Value;
        }

        private void cb_Race_SelectedIndexChanged(object sender, EventArgs e)
        {
            
        }

        private void cb_Class_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (cb_Class.SelectedIndex)
            {
                case (int)Character.Class.Default:
                    HideCharSpecifics();
                    AlignCharSpecifcs();

                    break;
                case (int)Character.Class.Cleric:
                    HideCharSpecifics();
                    AlignCharSpecifcs();
                    lbl_top.Visible = true;
                    num_Misc.Visible = true;
                    lbl_top.Left -= 20;
                    lbl_top.Text = "Turn Undead Uses";

                    break;
                case (int)Character.Class.Druid:
                    HideCharSpecifics();
                    AlignCharSpecifcs();
                    lbl_top.Visible = true;
                    cb_PetRace.Visible = true;
                    lbl_top.Text = "Pet Race";

                    break;
                case (int)Character.Class.Fighter:
                    HideCharSpecifics();
                    AlignCharSpecifcs();
                    lbl_top.Visible = true;
                    num_Misc.Visible = true;
                    lbl_top.Left -= 0;
                    lbl_top.Text = "Extra Feats";
                    break;
                case (int)Character.Class.Monk:
                    HideCharSpecifics();
                    AlignCharSpecifcs();
                    lbl_top.Visible = true;
                    num_Misc.Visible = true;
                    lbl_top.Left -= 0;
                    lbl_top.Text = "Extra Attacks";

                    break;
                case (int)Character.Class.Paladin:
                    HideCharSpecifics();
                    AlignCharSpecifcs();
                    lbl_top.Visible = true;
                    num_Misc.Visible = true;
                    lbl_top.Left -= 20;
                    lbl_top.Text = "Lay on Hands uses";
                    break;
                case (int)Character.Class.Ranger:
                    HideCharSpecifics();
                    AlignCharSpecifcs();
                    lbl_top.Visible = true;
                    cb_PetRace.Visible = true;
                    lbl_top.Text = "Pet Race";
                    cb_PetSize.Visible = true;
                    lbl_bottom.Visible = true;
                    lbl_bottom.Text = "Pet Size";
                    lbl_bottom.Left += 7;

                    break;
                case (int)Character.Class.Rogue:
                    HideCharSpecifics();
                    AlignCharSpecifcs();
                    lbl_top.Visible = true;
                    num_Misc.Visible = true;
                    lbl_top.Left -= 20;
                    lbl_top.Text = "Sneak Attack dice";
                    break;
                case (int)Character.Class.Sorcerer:
                    HideCharSpecifics();
                    AlignCharSpecifcs();
                    lbl_top.Visible = true;
                    num_Misc.Visible = true;
                    lbl_top.Left -= 0;
                    lbl_top.Text = "Spells known";
                    break;
                case (int)Character.Class.Wizard:
                    HideCharSpecifics();
                    AlignCharSpecifcs();
                    lbl_top.Visible = true;
                    num_Misc.Visible = true;
                    lbl_top.Left -= 0;
                    lbl_top.Text = "Spells known";
                    cb_Familar.Visible = true;
                    lbl_bottom.Visible = true;
                    lbl_bottom.Text = "Familiar race";
                    lbl_bottom.Left += 0;

                    break;

                default:
                    break;
            }



        }

        private void HideCharSpecifics()
        {
            cb_PetRace.Visible = false;
            num_Misc.Visible = false;
            lbl_top.Visible = false;
            lbl_bottom.Visible = false;
            cb_Familar.Visible = false;
            cb_PetSize.Visible = false;
        }

        private void AlignCharSpecifcs()
        {
            lbl_top.Left = top_xLabelPos;
            lbl_top.Top = top_yLabelPos;
            lbl_bottom.Left = bottom_xLabelPos;
            lbl_bottom.Top = bottom_yLabelPos;
        }

        private void num_Str_ValueChanged(object sender, EventArgs e)
        {
            mStr = (int)num_Str.Value;
        }

        private void num_Dex_ValueChanged(object sender, EventArgs e)
        {
            mDex = (int)num_Dex.Value;
        }

        private void num_Con_ValueChanged(object sender, EventArgs e)
        {
            mCon = (int)num_Con.Value;
        }

        private void num_Int_ValueChanged(object sender, EventArgs e)
        {
            mInt = (int)num_Int.Value;
        }

        private void num_Wis_ValueChanged(object sender, EventArgs e)
        {
            mWis = (int)num_Wis.Value;
        }

        private void num_Cha_ValueChanged(object sender, EventArgs e)
        {
            mCha = (int)num_Cha.Value;
        }

        private void lb_Characters_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                if (lb_Characters.SelectedIndex < toons.Count)
                {
                    ChangeFields(toons[lb_Characters.SelectedIndex]);
                }

            }
            catch 
            {
                
                
            }




            
            
        }

        public void ChangeFields(Character inToon)
        {
            try
            {
                Cleric sendToon = (Cleric)inToon;
                ChangeFields(sendToon);
                
            }
            catch 
            {

                
            }

            try
            {
                Druid sendToon = (Druid)inToon;
                ChangeFields(sendToon);
            }
            catch 
            {

                
            }
            try
            {
                Fighter sendToon = (Fighter)inToon;
                ChangeFields(sendToon);
            }
            catch
            {


            }
            try
            {
                Monk sendToon = (Monk)inToon;
                ChangeFields(sendToon);
            }
            catch
            {


            }
            try
            {
                Ranger sendToon = (Ranger)inToon;
                ChangeFields(sendToon);
            }
            catch
            {


            }
            try
            {
                Paladin sendToon = (Paladin)inToon;
                ChangeFields(sendToon);
            }
            catch
            {


            }
            try
            {
                Rogue sendToon = (Rogue)inToon;
                ChangeFields(sendToon);
            }
            catch
            {


            }
            try
            {
                Wizard sendToon = (Wizard)inToon;
                ChangeFields(sendToon);
            }
            catch
            {


            }
            try
            {
                Sorcerer sendToon = (Sorcerer)inToon;
                ChangeFields(sendToon);
            }
            catch
            {


            }





        }
        public void ChangeFields(Cleric inToon)
        {
            Cleric tempToon = inToon;
            tb_FirstName.Text = inToon.MFirstName;
            tb_LastName.Text = inToon.MLastName;
            num_Age.Value = inToon.MAge;
            cb_Class.SelectedIndex = (int)inToon.MClass;
            cb_Race.SelectedIndex = (int)inToon.MRace;
            num_Str.Value = inToon.MStr;
            num_Dex.Value = inToon.MDex;
            num_Con.Value = inToon.MCon;
            num_Int.Value = inToon.MInt;
            num_Wis.Value = inToon.MWis;
            num_Cha.Value = inToon.MCha;
            num_Misc.Value = inToon.TurnUndeadUsed;

        }
            public void ChangeFields(Druid inToon)
        {
            Character tempToon = inToon;
            tb_FirstName.Text = inToon.MFirstName;
            tb_LastName.Text = inToon.MLastName;
            num_Age.Value = inToon.MAge;
            cb_Class.SelectedIndex = (int)inToon.MClass;
            cb_Race.SelectedIndex = (int)inToon.MRace;
            num_Str.Value = inToon.MStr;
            num_Dex.Value = inToon.MDex;
            num_Con.Value = inToon.MCon;
            num_Int.Value = inToon.MInt;
            num_Wis.Value = inToon.MWis;
            num_Cha.Value = inToon.MCha;
            cb_PetRace.SelectedIndex = (int)inToon.MPetRace;
        }

            public void ChangeFields(Fighter inToon)
        {
            Character tempToon = inToon;
            tb_FirstName.Text = inToon.MFirstName;
            tb_LastName.Text = inToon.MLastName;
            num_Age.Value = inToon.MAge;
            cb_Class.SelectedIndex = (int)inToon.MClass;
            cb_Race.SelectedIndex = (int)inToon.MRace;
            num_Str.Value = inToon.MStr;
            num_Dex.Value = inToon.MDex;
            num_Con.Value = inToon.MCon;
            num_Int.Value = inToon.MInt;
            num_Wis.Value = inToon.MWis;
            num_Cha.Value = inToon.MCha;
            num_Misc.Value = inToon.ExtraFeats;

        }
            public void ChangeFields(Monk inToon)
        {
            Character tempToon = inToon;
            tb_FirstName.Text = inToon.MFirstName;
            tb_LastName.Text = inToon.MLastName;
            num_Age.Value = inToon.MAge;
            cb_Class.SelectedIndex = (int)inToon.MClass;
            cb_Race.SelectedIndex = (int)inToon.MRace;
            num_Str.Value = inToon.MStr;
            num_Dex.Value = inToon.MDex;
            num_Con.Value = inToon.MCon;
            num_Int.Value = inToon.MInt;
            num_Wis.Value = inToon.MWis;
            num_Cha.Value = inToon.MCha;
            num_Misc.Value = inToon.ExtraAttacks;

        }
            public void ChangeFields(Paladin inToon)
        {
            Character tempToon = inToon;
            tb_FirstName.Text = inToon.MFirstName;
            tb_LastName.Text = inToon.MLastName;
            num_Age.Value = inToon.MAge;
            cb_Class.SelectedIndex = (int)inToon.MClass;
            cb_Race.SelectedIndex = (int)inToon.MRace;
            num_Str.Value = inToon.MStr;
            num_Dex.Value = inToon.MDex;
            num_Con.Value = inToon.MCon;
            num_Int.Value = inToon.MInt;
            num_Wis.Value = inToon.MWis;
            num_Cha.Value = inToon.MCha;
            num_Misc.Value = inToon.LayOnHands;
        }
            public void ChangeFields(Rogue inToon)
        {
            Character tempToon = inToon;
            tb_FirstName.Text = inToon.MFirstName;
            tb_LastName.Text = inToon.MLastName;
            num_Age.Value = inToon.MAge;
            cb_Class.SelectedIndex = (int)inToon.MClass;
            cb_Race.SelectedIndex = (int)inToon.MRace;
            num_Str.Value = inToon.MStr;
            num_Dex.Value = inToon.MDex;
            num_Con.Value = inToon.MCon;
            num_Int.Value = inToon.MInt;
            num_Wis.Value = inToon.MWis;
            num_Cha.Value = inToon.MCha;
            num_Misc.Value = inToon.SneakAttack;
        }
            public void ChangeFields(Ranger inToon)
        {
            Character tempToon = inToon;
            tb_FirstName.Text = inToon.MFirstName;
            tb_LastName.Text = inToon.MLastName;
            num_Age.Value = inToon.MAge;
            cb_Class.SelectedIndex = (int)inToon.MClass;
            cb_Race.SelectedIndex = (int)inToon.MRace;
            num_Str.Value = inToon.MStr;
            num_Dex.Value = inToon.MDex;
            num_Con.Value = inToon.MCon;
            num_Int.Value = inToon.MInt;
            num_Wis.Value = inToon.MWis;
            num_Cha.Value = inToon.MCha;
            cb_PetRace.SelectedIndex = (int)inToon.MPetRace;
            cb_PetSize.SelectedIndex = (int)inToon.MPetSize;

        }
            public void ChangeFields(Sorcerer inToon)
        {
            Character tempToon = inToon;
            tb_FirstName.Text = inToon.MFirstName;
            tb_LastName.Text = inToon.MLastName;
            num_Age.Value = inToon.MAge;
            cb_Class.SelectedIndex = (int)inToon.MClass;
            cb_Race.SelectedIndex = (int)inToon.MRace;
            num_Str.Value = inToon.MStr;
            num_Dex.Value = inToon.MDex;
            num_Con.Value = inToon.MCon;
            num_Int.Value = inToon.MInt;
            num_Wis.Value = inToon.MWis;
            num_Cha.Value = inToon.MCha;
            num_Misc.Value = inToon.SpellSlots;
        }
            public void ChangeFields(Wizard inToon)
        {
            Character tempToon = inToon;
            tb_FirstName.Text = inToon.MFirstName;
            tb_LastName.Text = inToon.MLastName;
            num_Age.Value = inToon.MAge;
            cb_Class.SelectedIndex = (int)inToon.MClass;
            cb_Race.SelectedIndex = (int)inToon.MRace;
            num_Str.Value = inToon.MStr;
            num_Dex.Value = inToon.MDex;
            num_Con.Value = inToon.MCon;
            num_Int.Value = inToon.MInt;
            num_Wis.Value = inToon.MWis;
            num_Cha.Value = inToon.MCha;
            num_Misc.Value = inToon.SpellsKnown;
            cb_Familar.SelectedIndex = (int)inToon.MPetRace;
        }



        private void toolstrip_Actions_Remove_Click(object sender, EventArgs e)
        {
            try
            {
                int indexToRemove = lb_Characters.SelectedIndex;
                lb_Characters.Items.RemoveAt(indexToRemove);
                toons.RemoveAt(indexToRemove);
                restartFields();
                
            }
            catch
            {
                //Do nothing
            }
        }

        private void toolstrip_Actions_Update_Click(object sender, EventArgs e)
        {
            //Do the add button, but this time instead of adding to the list, we use the set functions
            //of all the member variables at the toons[lb.selected index]
            if (tb_FirstName.Text != "" && tb_LastName.Text != "")
            {
                if (cb_Race.Text != "Default" && cb_Class.Text != "Default")
                {//error checking done, Actually add the character

                    switch (cb_Race.Text)
                    {
                        case "Dwarf":
                            mRace = Character.Race.Dwarf;
                            break;
                        case "Elf":
                            mRace = Character.Race.Elf;
                            break;
                        case "Gnome":
                            mRace = Character.Race.Gnome;
                            break;
                        case "HalfElf":
                            mRace = Character.Race.HalfElf;
                            break;
                        case "HalfOrc":
                            mRace = Character.Race.HalfOrc;
                            break;
                        case "Halfling":
                            mRace = Character.Race.Halfling;
                            break;
                        case "Human":
                            mRace = Character.Race.Human;
                            break;
                        default:
                            break;
                    }
                    switch (cb_Class.Text)
                    {

                        case "Druid":

                            if (cb_PetRace.Text != "Default")
                            {
                                mClass = Character.Class.Druid;
                                toons[lb_Characters.SelectedIndex] = (new Druid(mFirstName, mLastName, mAge, mStr, mDex, mCon, mInt, mWis, mCha, mRace, mClass, mPetRace));
                                ReplaceIndexWithUpdated();//Replace the selected object with the new spot in the toons ar

                            }
                            else
                            {
                                MessageBox.Show("Please enter a pet race", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                            }

                            break;
                        case "Cleric":




                            mClass = Character.Class.Cleric;
                            toons[lb_Characters.SelectedIndex] = (new Cleric(mFirstName, mLastName, mAge, mStr, mDex, mCon, mInt, mWis, mCha, mRace, mClass, miscNum));
                            ReplaceIndexWithUpdated();//Replace the selected object with the new spot in the toons ar
                            break;
                        case "Fighter":
                            mClass = Character.Class.Fighter;
                            toons[lb_Characters.SelectedIndex] = (new Fighter(mFirstName, mLastName, mAge, mStr, mDex, mCon, mInt, mWis, mCha, mRace, mClass, miscNum));
                            ReplaceIndexWithUpdated();//Replace the selected object with the new spot in the toons ar
                            break;
                        case "Monk":
                            mClass = Character.Class.Monk;
                            toons[lb_Characters.SelectedIndex] = (new Monk(mFirstName, mLastName, mAge, mStr, mDex, mCon, mInt, mWis, mCha, mRace, mClass, miscNum));
                            ReplaceIndexWithUpdated();//Replace the selected object with the new spot in the toons ar
                            break;
                        case "Paladin":
                            mClass = Character.Class.Paladin;
                            toons[lb_Characters.SelectedIndex] = (new Paladin(mFirstName, mLastName, mAge, mStr, mDex, mCon, mInt, mWis, mCha, mRace, mClass, miscNum));
                            ReplaceIndexWithUpdated();//Replace the selected object with the new spot in the toons ar
                            break;
                        case "Ranger":
                            if (cb_PetRace.Text != "Default" && cb_PetSize.Text != "Default")
                            {
                                mClass = Character.Class.Ranger;
                                toons[lb_Characters.SelectedIndex] = (new Ranger(mFirstName, mLastName, mAge, mStr, mDex, mCon, mInt, mWis, mCha, mRace, mClass, mPetRace, mPetSize));
                                ReplaceIndexWithUpdated();//Replace the selected object with the new spot in the toons ar

                            }
                            else
                            {
                                MessageBox.Show("Please enter a pet race and a pet size", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                            }

                            break;
                        case "Rogue":
                            mClass = Character.Class.Rogue;
                            toons[lb_Characters.SelectedIndex] = (new Rogue(mFirstName, mLastName, mAge, mStr, mDex, mCon, mInt, mWis, mCha, mRace, mClass, miscNum));
                            ReplaceIndexWithUpdated();//Replace the selected object with the new spot in the toons ar
                            break;
                        case "Sorcerer":

                            mClass = Character.Class.Sorcerer;
                            toons[lb_Characters.SelectedIndex] = (new Sorcerer(mFirstName, mLastName, mAge, mStr, mDex, mCon, mInt, mWis, mCha, mRace, mClass, miscNum));
                            ReplaceIndexWithUpdated();//Replace the selected object with the new spot in the toons ar
                            break;
                        case "Wizard":
                            if (cb_Familar.Text != "Default")
                            {
                                mClass = Character.Class.Wizard;
                                toons[lb_Characters.SelectedIndex] = (new Wizard(mFirstName, mLastName, mAge, mStr, mDex, mCon, mInt, mWis, mCha, mRace, mClass, miscNum, mFamRace));
                                ReplaceIndexWithUpdated();
                                restartFields();

                            }
                            else
                            {
                                MessageBox.Show("Please enter a familiar race", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                            }

                            break;
                        case "scat man":
                            //ba booda boop scaddada sca doo da boop
                            break;
                        default:
                            break;

                    }




                    restartFields();
                    mFirstName = "";
                    mLastName = "";
                    mAge = 0;
                    mRace = Character.Race.Default;
                    mClass = Character.Class.Default;
                    mStr = 0;
                    mDex = 0;
                    mCon = 0;
                    mInt = 0;
                    mWis = 0;
                    mCha = 0;
                    miscNum = 0;

                    lb_Characters.ClearSelected();

                }
                else
                {
                    MessageBox.Show("Please enter both a race and a class", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }

            }
            else
            {
                MessageBox.Show("Please enter both a first and last name", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

        }

        private void ReplaceIndexWithUpdated()
        {
            int indexToChange = lb_Characters.SelectedIndex;
            lb_Characters.Items.RemoveAt(indexToChange);
            lb_Characters.Items.Insert(indexToChange, toons[indexToChange]);
        }

        private void num_Misc_ValueChanged(object sender, EventArgs e)
        {
            miscNum = (int)num_Misc.Value;
        }

        private void cb_PetRace_SelectedIndexChanged(object sender, EventArgs e)
        {
            mPetRace = (Form1.PetRace)cb_PetRace.SelectedIndex;
            
        }

        private void cb_Familar_SelectedIndexChanged(object sender, EventArgs e)
        {
            mFamRace = (Form1.FamiliarRace)cb_Familar.SelectedIndex;
        }

        private void cb_PetSize_SelectedIndexChanged(object sender, EventArgs e)
        {
            mPetSize = (Form1.PetSize)cb_PetSize.SelectedIndex;
        }

        private void bt_Roll_Click(object sender, EventArgs e)
        {
            Random rand = new Random();
            num_Str.Value = rand.Next(1, 21);
            num_Dex.Value = rand.Next(1, 21);
            num_Con.Value = rand.Next(1, 21);
            num_Int.Value = rand.Next(1, 21);
            num_Wis.Value = rand.Next(1, 21);
            num_Cha.Value = rand.Next(1, 21);

        }
    }
}
