using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CharacterEditor_BrennanRodriguez
{
    public class Wizard : Character
    {
        int spellsKnown;


        Form1.FamiliarRace mPetRace;

        public int SpellsKnown
        {
            get
            {
                return spellsKnown;
            }

            set
            {
                spellsKnown = value;
            }
        }

        public Form1.FamiliarRace MPetRace
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

        public Wizard() : base()
        {
            spellsKnown = 0;
        }

        public Wizard(string inFirst, string inLast, int inAge,
            int inStr, int inDex, int inCon, int inInt, int inWis, int inCha,
            Race inRace, Class inClass, int inSpells, Form1.FamiliarRace inPetRace) : base(inFirst, inLast, inAge,
             inStr, inDex, inCon, inInt, inWis, inCha,
             inRace, inClass)
        {
            spellsKnown = inSpells;
            mPetRace = inPetRace;
        }

        class WizardFamiliar
        {
            Form1.FamiliarRace mPetRace;

            public WizardFamiliar()
            {
                mPetRace = Form1.FamiliarRace.Bat;
            }
            public WizardFamiliar(Form1.FamiliarRace inRace)
            {
                mPetRace = inRace;
            }
        }

    }
}
