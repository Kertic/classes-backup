using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CharacterEditor_BrennanRodriguez
{
   public class Cleric : Character
    {
        int turnUndeadUsed;

        public Cleric() : base()
        {
            turnUndeadUsed = 0;
        }
        public Cleric(string inFirst, string inLast, int inAge,
            int inStr, int inDex, int inCon, int inInt, int inWis, int inCha,
            Race inRace, Class inClass, int inTurn) : base( inFirst,  inLast,  inAge,
             inStr,  inDex,  inCon,  inInt,  inWis,  inCha,
             inRace,  inClass)
        {
            turnUndeadUsed = inTurn;

        }

        public int TurnUndeadUsed
        {
            get
            {
                return turnUndeadUsed;
            }

            set
            {
                turnUndeadUsed = value;
            }
        }
    }
}
