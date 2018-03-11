using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CharacterEditor_BrennanRodriguez
{
    public class Fighter : Character
    {
        int extraFeats;
        public Fighter() : base()
        {
            extraFeats = 0;

        }

        public Fighter(string inFirst, string inLast, int inAge,
            int inStr, int inDex, int inCon, int inInt, int inWis, int inCha,
            Race inRace, Class inClass, int inFeats) : base(inFirst, inLast, inAge,
             inStr, inDex, inCon, inInt, inWis, inCha,
             inRace, inClass)
        {
            extraFeats = inFeats;
        }

        public int ExtraFeats
        {
            get
            {
                return extraFeats;
            }

            set
            {
                extraFeats = value;
            }
        }
    }
}
