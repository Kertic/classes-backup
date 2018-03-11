using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlackJackProject_BrennanRodriguez
{
    class Deck
    {
        List<Card> mDeck = new List<Card>();

        public Deck()
        {

            //Fills the deck with default cards
            for (int i = 0; i < 52; i++)
            {
                mDeck.Add(new Card());
            }
            //Builds the deck in order
            for (int suit = 0; suit < 4; suit++)
            {
                for (int value = 0; value < 13; value++)
                {
                    //Set the suit
                    if (suit == 0) {
                        mDeck[value + (13 * suit)].SetSuit(Card.suits.Diamonds);
                    }
                    if (suit == 1)
                    {
                        mDeck[value + (13 * suit)].SetSuit(Card.suits.Clubs);
                    }
                    if (suit == 2)
                    {
                        mDeck[value + (13 * suit)].SetSuit(Card.suits.Hearts);
                    }
                    if (suit == 3)
                    {
                        mDeck[value + (13 * suit)].SetSuit(Card.suits.Spades);
                    }

                    //Set the value

                if (value == 0)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.Ace);
                    }
                    if (value == 1)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.Two);
                    }
                    if (value == 2)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.Three);
                    }
                    if (value == 3)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.Four);
                    }
                    if (value == 4)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.Five);
                    }
                    if (value == 5)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.Six);
                    }
                    if (value == 6)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.Seven);
                    }
                    if (value == 7)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.Eight);
                    }
                    if (value == 8)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.Nine);
                    }
                    if (value == 9)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.Ten);
                    }
                    if (value == 10)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.Jack);
                    }
                    if (value == 11)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.King);
                    }
                    if (value == 12)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.Queen);
                    }
                }
            }
        }
        
        public void Print()
        {
            for (int i = 0; i < mDeck.Count; i++)
            {
                if (mDeck[i].GetSuit() == Card.suits.Hearts || mDeck[i].GetSuit() == Card.suits.Diamonds)
                {
                   
                    Console.ForegroundColor = ConsoleColor.Red;
                    
                    Console.Write(mDeck[i].GetValue() + " of " + mDeck[i].GetSuit() + "\n");
                } else
                {
                    Console.ForegroundColor = ConsoleColor.Black;
                    Console.Write(mDeck[i].GetValue() + " of " + mDeck[i].GetSuit() + "\n");
                }
                
                
            }
            
        }
        public void Print(int pos)
        {
            if (mDeck[pos].GetSuit() == Card.suits.Hearts || mDeck[pos].GetSuit() == Card.suits.Diamonds)
            {
                Console.ForegroundColor = ConsoleColor.Red;
                Console.Write(mDeck[pos].GetValue() + " of " + mDeck[pos].GetSuit() + "\n");
                Console.ForegroundColor = ConsoleColor.Black;
            }
            else
            {
                
                Console.Write(mDeck[pos].GetValue() + " of " + mDeck[pos].GetSuit() + "\n");
            }
        }
        public void Shuffle()
        {
            Random rand = new Random();
            List<Card> tempDeck = new List<Card>();
            for (int i = 0; i < 52; i++)
            {
                tempDeck.Add(new Card());
            }
            for (int i = 0; i < mDeck.Count; i++)//Goes through each card of mdeck
            {
                while (true)
                {
                   int spot =  rand.Next(0, 52);//spot is the spot in tempdeck we will be placing mdeck's current card
                    if (tempDeck[spot].GetSuit() == Card.suits.Def && tempDeck[spot].GetValue() == Card.values.Def)//If the card is a default card (aka "blank") 
                    {
                        tempDeck[spot] = mDeck[i];//Put mdeck's card into that spot
                        break;
                    }
                }
                
            }
            mDeck = tempDeck;

        }

        public Card Draw()
        {
            Card returnCard = mDeck[0];
            mDeck.Remove(mDeck[0]);
            return returnCard;
            

        }

        public void ResetDeck()//Fills deck and shuffles
        {
            //Empty the deck
            for (int i = 0; i < mDeck.Count; i++)
            {
                mDeck.Remove(mDeck[i]);
            }
            //Fills the deck with default cards
            for (int i = 0; i < 52; i++)
            {
                mDeck.Add(new Card());
            }
            //Builds the deck in order
            for (int suit = 0; suit < 4; suit++)
            {
                for (int value = 0; value < 13; value++)
                {
                    //Set the suit
                    if (suit == 0)
                    {
                        mDeck[value + (13 * suit)].SetSuit(Card.suits.Diamonds);
                    }
                    if (suit == 1)
                    {
                        mDeck[value + (13 * suit)].SetSuit(Card.suits.Clubs);
                    }
                    if (suit == 2)
                    {
                        mDeck[value + (13 * suit)].SetSuit(Card.suits.Hearts);
                    }
                    if (suit == 3)
                    {
                        mDeck[value + (13 * suit)].SetSuit(Card.suits.Spades);
                    }

                    //Set the value

                    if (value == 0)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.Ace);
                    }
                    if (value == 1)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.Two);
                    }
                    if (value == 2)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.Three);
                    }
                    if (value == 3)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.Four);
                    }
                    if (value == 4)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.Five);
                    }
                    if (value == 5)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.Six);
                    }
                    if (value == 6)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.Seven);
                    }
                    if (value == 7)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.Eight);
                    }
                    if (value == 8)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.Nine);
                    }
                    if (value == 9)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.Ten);
                    }
                    if (value == 10)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.Jack);
                    }
                    if (value == 11)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.King);
                    }
                    if (value == 12)
                    {
                        mDeck[value + (13 * suit)].SetValue(Card.values.Queen);
                    }
                }
            }
            this.Shuffle();
        }//Not needed, we can just make deck = new deck();//Also not working at the moment
    }
}
