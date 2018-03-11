using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CharacterEditor_BrennanRodriguez
{
    public class Rogue : Character
    {
        int sneakAttack;

        public Rogue() : base()
        {
            sneakAttack = 0;
        }
        public Rogue(string inFirst, string inLast, int inAge,
            int inStr, int inDex, int inCon, int inInt, int inWis, int inCha,
            Race inRace, Class inClass, int inSneak) : base(inFirst, inLast, inAge,
             inStr, inDex, inCon, inInt, inWis, inCha,
             inRace, inClass)
        {
            sneakAttack = inSneak;
        }

        public int SneakAttack
        {
            get
            {
                return sneakAttack;
            }

            set
            {
                sneakAttack = value;
            }
        }
    }
}
