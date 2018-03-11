using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CharacterEditor_BrennanRodriguez
{
   public class Druid : Character
    {
        

        Form1.PetRace mPetRace;
        AnimalCompanion mCompanion;

        public Form1.PetRace MPetRace
        {
            get
            {
                return mPetRace;
            }

            set
            {
                mPetRace = value;
            }
        }

        public Druid() : base()
        {
            mPetRace = Form1.PetRace.Bear;
            mCompanion = new AnimalCompanion(mPetRace);

        }
        public Druid(string inFirst, string inLast, int inAge,
            int inStr, int inDex, int inCon, int inInt, int inWis, int inCha,
            Race inRace, Class inClass, Form1.PetRace inPetRace) : base(inFirst, inLast, inAge,
             inStr, inDex, inCon, inInt, inWis, inCha,
             inRace, inClass)
        {
            mPetRace = inPetRace;
            mCompanion = new AnimalCompanion(mPetRace);

        }

        class AnimalCompanion
        {
            Form1.PetRace mPetRace;

            public AnimalCompanion()
            {
                mPetRace = Form1.PetRace.Bear;
            }
            public AnimalCompanion(Form1.PetRace inRace)
            {
                mPetRace = inRace;
            }
        }

    }
}
