using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CharacterEditor_BrennanRodriguez
{
    public class Sorcerer : Character
    {
        int spellSlots;

        public Sorcerer() : base()
        {
            spellSlots = 0;
        }

        public Sorcerer(string inFirst, string inLast, int inAge,
            int inStr, int inDex, int inCon, int inInt, int inWis, int inCha,
            Race inRace, Class inClass, int inSpell) : base(inFirst, inLast, inAge,
             inStr, inDex, inCon, inInt, inWis, inCha,
             inRace, inClass)
        {
            spellSlots = inSpell;
        }

        public int SpellSlots
        {
            get
            {
                return spellSlots;
            }

            set
            {
                spellSlots = value;
            }
        }
    }
}
