using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CharacterEditor_BrennanRodriguez
{
   public class Character
    {
        string mFirstName;
        string mLastName;
        int mAge;
        Race mRace;
        Class mClass;
        int mStr;
        int mDex;
        int mCon;
        int mInt;
        int mWis;
        int mCha;



        public enum Race
        {
            Default,
            Dwarf,
            Elf,
            Gnome,
            HalfElf,
            HalfOrc,
            Halfling,
            Human
        }
       public enum Class
        {
            Default,
            Cleric,
            Druid,
            Fighter,
            Monk,
            Paladin,
            Ranger,
            Rogue,
            Sorcerer,
            Wizard

        }

        public Character()
        {
            mFirstName = "Default First";
            mLastName = "Default last";
            mAge = -1;
            mRace = Race.Dwarf;
            mClass = Class.Cleric;
            mStr = 0;
            mDex = 0;
            mCon = 0;
            mInt = 0;
            mWis = 0;
            mCha = 0;

        }
        public Character(string inFirst, string inLast, int inAge, 
            int inStr, int inDex, int inCon, int inInt, int inWis, int inCha,
            Race inRace, Class inClass)
        {
            mFirstName = inFirst;
            mLastName = inLast;
            mAge = inAge;
            mRace = inRace;
            mClass = inClass;
            mStr = inStr;
            mDex = inDex;
            mCon = inCon;
            mInt = inInt;
            mWis = inWis;
            mCha = inCha;
        }

        public override string ToString()
        {
            return mFirstName + " " + mLastName;
        }

        //Get or set values
        public string MFirstName
        {
            get
            {
                return mFirstName;
            }

            set
            {
                mFirstName = value;
            }
        }

        public string MLastName
        {
            get
            {
                return mLastName;
            }

            set
            {
                mLastName = value;
            }
        }

        public int MAge
        {
            get
            {
                return mAge;
            }

            set
            {
                mAge = value;
            }
        }

        public Race MRace
        {
            get
            {
                return mRace;
            }

            set
            {
                mRace = value;
            }
        }

        public Class MClass
        {
            get
            {
                return mClass;
            }

            set
            {
                mClass = value;
            }
        }

        public int MStr
        {
            get
            {
                return mStr;
            }

            set
            {
                mStr = value;
            }
        }

        public int MDex
        {
            get
            {
                return mDex;
            }

            set
            {
                mDex = value;
            }
        }

        public int MCon
        {
            get
            {
                return mCon;
            }

            set
            {
                mCon = value;
            }
        }

        public int MInt
        {
            get
            {
                return mInt;
            }

            set
            {
                mInt = value;
            }
        }

        public int MWis
        {
            get
            {
                return mWis;
            }

            set
            {
                mWis = value;
            }
        }

        public int MCha
        {
            get
            {
                return mCha;
            }

            set
            {
                mCha = value;
            }
        }



    }
}
