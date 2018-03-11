using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CharacterEditor_BrennanRodriguez
{
    public class Paladin : Character
    {
        int layOnHands;
        public Paladin() : base()
        {
            layOnHands = 0;
        }
        public Paladin(string inFirst, string inLast, int inAge,
            int inStr, int inDex, int inCon, int inInt, int inWis, int inCha,
            Race inRace, Class inClass, int inHands ) : base(inFirst, inLast, inAge,
             inStr, inDex, inCon, inInt, inWis, inCha,
             inRace, inClass)
        {
            layOnHands = inHands;
        }

        public int LayOnHands
        {
            get
            {
                return layOnHands;
            }

            set
            {
                layOnHands = value;
            }
        }
    }
}
