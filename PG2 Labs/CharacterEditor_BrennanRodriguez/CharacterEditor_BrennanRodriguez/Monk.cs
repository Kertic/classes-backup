using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CharacterEditor_BrennanRodriguez
{
    public class Monk : Character
    {
        int extraAttacks;
        public Monk() : base()
        {
            extraAttacks = 0;

        }

        public Monk(string inFirst, string inLast, int inAge,
            int inStr, int inDex, int inCon, int inInt, int inWis, int inCha,
            Race inRace, Class inClass,int inExtra ) : base(inFirst, inLast, inAge,
             inStr, inDex, inCon, inInt, inWis, inCha,
             inRace, inClass)
        {
            extraAttacks = inExtra;
        }

        public int ExtraAttacks
        {
            get
            {
                return extraAttacks;
            }

            set
            {
                extraAttacks = value;
            }
        }
    }
}
