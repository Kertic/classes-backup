using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlackJackProject_BrennanRodriguez
{
    class Program
    {
        static void Main(string[] args)
        {
            
            Console.BackgroundColor = ConsoleColor.White;
            Console.ForegroundColor = ConsoleColor.Black;
            Console.Clear();//Makes the background white

            Deck Deck = new Deck();
            Player PC = new Player();
            Player Dealer = new Player();
            Game newGame = new Game(PC, Dealer, Deck);


            newGame.MainMenu();





            Console.ReadKey();

        }
    }
}
