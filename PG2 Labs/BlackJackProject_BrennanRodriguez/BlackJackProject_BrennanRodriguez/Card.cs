using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlackJackProject_BrennanRodriguez
{
    class Card
    {
       public enum values
        {
            
            Ace = 11,
            Two = 2,
            Three = 3,
            Four = 4,
            Five = 5,
            Six = 6,
            Seven = 7,
            Eight = 8,
            Nine = 9,
            Ten = 10,
            Jack = 12,
            Queen = 14,
            King = 13,
            Def = 0

        };
       public enum suits
        {
            Def = 0,
            Spades = 1,
            Clubs = 2,
            Hearts = 3,
            Diamonds = 4
        };
        values mvalue;
        suits msuit;
        public Card()
        {
            mvalue = values.Def;
            msuit = suits.Def;

        }
        public Card(values val, suits suit)
        {
            mvalue = val;
            msuit = suit;
        }

        public values GetValue()
        {
            return mvalue;
        }
        public suits GetSuit()
        {
            return msuit;
        }

        public string GetSuitString()
        {
            if (this.GetSuit() == Card.suits.Hearts)
            {
                return "Hearts";

            }
            if (this.GetSuit() == Card.suits.Diamonds)
            {
                return "Diamonds";

            }
            if (this.GetSuit() == Card.suits.Spades)
            {
                return "Spades";

            }
            if (this.GetSuit() == Card.suits.Clubs)
            {
                return "Clubs";

            }
            else
            {
                return "Invalid";
            }

        }

        public string GetValueString()
        {
            if (this.GetValue() == Card.values.Ace)
            {
                return "Ace";
                          
            }
            if (this.GetValue() == Card.values.Two)
            {
                return "Two";
            }
            if (this.GetValue() == Card.values.Three)
            {
                return "Three";
            }
            if (this.GetValue() == Card.values.Four)
            {
                return "Four";
            }
            if (this.GetValue() == Card.values.Five)
            {
                return "Five";
            }
            if (this.GetValue() == Card.values.Six)
            {
                return "Six";
            }
            if (this.GetValue() == Card.values.Seven)
            {
                return "Seven";
            }
            if (this.GetValue() == Card.values.Eight)
            {
                return "Eight";
            }
            if (this.GetValue() == Card.values.Nine)
            {
                return "Nine";
            }
            if (this.GetValue() == Card.values.Ten)
            {
                return "Ten";
            }
            if (this.GetValue() == Card.values.Jack)
            {
                return "Jack";
            }
            if (this.GetValue() == Card.values.King)
            {
                return "King";
            }
            if (this.GetValue() == Card.values.Queen)
            {
                return "Queen";
            }
            else
            {
                return "Invalid value";
            }
        }

        public void SetValue(values val)
        {
            mvalue = val;
        }

        public void SetSuit(suits suit)
        {
            msuit = suit;
        }

        public void PrintCard()
        {
              if (this.GetSuit() == Card.suits.Hearts || this.GetSuit() == Card.suits.Diamonds)
              {
                  Console.ForegroundColor = ConsoleColor.Red;
                  Console.Write(this.GetValue() + " of " + this.GetSuit() + "\n");
                  Console.ForegroundColor = ConsoleColor.Black;
              }
              else
              {
            
                  Console.Write(this.GetValue() + " of " + this.GetSuit() + "\n");
              }
        //    if (this.GetSuit() == Card.suits.Hearts)
        //    {
        //        Console.BackgroundColor = ConsoleColor.Gray;
        //        Console.WriteLine("■■■■■■■■");
        //        Console.WriteLine("■■■■■■■■");
        //        Console.WriteLine("■■■■■■■■");
        //        Console.WriteLine("■■■■■■■■");
        //        Console.WriteLine("■■■■■■■■");
        //        Console.SetCursorPosition((Console.CursorLeft - GetSuitString().Length / 2), Console.CursorTop - 1);
        //        Console.ForegroundColor = ConsoleColor.Red;
        //        Console.Write(GetSuitString());
        //        Console.SetCursorPosition((Console.CursorLeft + GetSuitString().Length / 2), Console.CursorTop - 1);
        //        Console.Write(GetValueString());
        //        Console.BackgroundColor = ConsoleColor.White;
        //        Console.ForegroundColor = ConsoleColor.Black;
        //    }
        //    if (this.GetSuit() == Card.suits.Diamonds)
        //    {
        //        Console.BackgroundColor = ConsoleColor.Gray;
        //        Console.WriteLine("■■■■■■■■");
        //        Console.WriteLine("■■■■■■■■");
        //        Console.WriteLine("■■■■■■■■");
        //        Console.WriteLine("■■■■■■■■");
        //        Console.WriteLine("■■■■■■■■");
        //        Console.SetCursorPosition((Console.CursorLeft - GetSuitString().Length / 2), Console.CursorTop - 1);
        //        Console.ForegroundColor = ConsoleColor.Red;
        //        Console.Write(GetSuitString());
        //        Console.SetCursorPosition((Console.CursorLeft + GetSuitString().Length / 2), Console.CursorTop - 1);
        //        Console.Write(GetValueString());
        //        Console.BackgroundColor = ConsoleColor.White;
        //        Console.ForegroundColor = ConsoleColor.Black;
        //    }
        //    if (this.GetSuit() == Card.suits.Spades)
        //    {
        //        Console.BackgroundColor = ConsoleColor.Gray;
        //        Console.WriteLine("■■■■■■■■");
        //        Console.WriteLine("■■■■■■■■");
        //        Console.WriteLine("■■■■■■■■");
        //        Console.WriteLine("■■■■■■■■");
        //        Console.WriteLine("■■■■■■■■");
        //        Console.SetCursorPosition((Console.CursorLeft - GetSuitString().Length / 2), Console.CursorTop - 1);
        //        Console.ForegroundColor = ConsoleColor.Black;
        //        Console.Write(GetSuitString());
        //        Console.SetCursorPosition((Console.CursorLeft + GetSuitString().Length / 2), Console.CursorTop - 1);
        //        Console.Write(GetValueString());
        //        Console.BackgroundColor = ConsoleColor.White;
        //        Console.ForegroundColor = ConsoleColor.Black;
        //    }
        //    if (this.GetSuit() == Card.suits.Clubs)
        //    {
        //        Console.BackgroundColor = ConsoleColor.Gray;
        //        Console.WriteLine("■■■■■■■■");
        //        Console.WriteLine("■■■■■■■■");
        //        Console.WriteLine("■■■■■■■■");
        //        Console.WriteLine("■■■■■■■■");
        //        Console.WriteLine("■■■■■■■■");
        //        Console.SetCursorPosition((Console.CursorLeft - GetSuitString().Length / 2), Console.CursorTop - 1);
        //        Console.ForegroundColor = ConsoleColor.Black;
        //        Console.Write(GetSuitString());
        //        Console.SetCursorPosition((Console.CursorLeft + GetSuitString().Length / 2), Console.CursorTop - 1);
        //        Console.Write(GetValueString());
        //        Console.BackgroundColor = ConsoleColor.White;
        //        Console.ForegroundColor = ConsoleColor.Black;
        //    }



        }
    }
}
