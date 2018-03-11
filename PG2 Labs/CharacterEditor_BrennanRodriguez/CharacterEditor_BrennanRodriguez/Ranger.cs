using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CharacterEditor_BrennanRodriguez
{
    public class Ranger : Character
    {
        Form1.PetRace mPetRace;
        Form1.PetSize mPetSize;
        RangerPet mPet;

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

        public Form1.PetSize MPetSize
        {
            get
            {
                return mPetSize;
            }

            set
            {
                mPetSize = value;
            }
        }

        public Ranger() : base()
        {
             mPetRace = Form1.PetRace.Default;
            mPetSize = Form1.PetSize.Default;
            mPet = new RangerPet();


        }

        public Ranger(string inFirst, string inLast, int inAge,
            int inStr, int inDex, int inCon, int inInt, int inWis, int inCha,
            Race inRace, Class inClass, Form1.PetRace inPetRace, Form1.PetSize inPetSize)
            : base(inFirst, inLast, inAge,
             inStr, inDex, inCon, inInt, inWis, inCha,
             inRace, inClass)
        {
            mPetRace = inPetRace;
            mPetSize = inPetSize;
            mPet = new RangerPet(inPetRace, inPetSize);
        }
        class RangerPet
        {
            Form1.PetRace mPetRace;
            Form1.PetSize mPetSize;

            public RangerPet()
            {
                mPetRace = Form1.PetRace.Bear;
                mPetSize = Form1.PetSize.Small;
            }
            public RangerPet(Form1.PetRace inRace, Form1.PetSize inSize)
            {
                mPetRace = inRace;
                mPetSize = inSize;
            }
        }


    }
}
