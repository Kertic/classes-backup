using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace The_dark
{
    class Program
    {
        static void Main(string[] args)
        {


            Game theDark = new Game();
            theDark.Init();
            theDark.Render();
            while (!theDark.GetGameState())
            {
                theDark.Input();
                theDark.Update();
                theDark.Render();
            }


        }
    }
}
