using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlackJackProject_BrennanRodriguez
{
    class Player
    {
        List<Card> mHand = new List<Card>();
        int mPoints;
        public Player()
        {
            mPoints = 0;
        }

        public void AddToHand(Card inCard)
        {
            Console.ForegroundColor = ConsoleColor.Black;
            Console.Write("You drew a: ");
            inCard.PrintCard();
            mHand.Add(inCard);
            mPoints = this.CalculateHand();
        }

        public void DealerAddToHand(Card inCard)
        {
            Console.Write("The dealer drew a: ");
            inCard.PrintCard();
            mHand.Add(inCard);
            mPoints = this.CalculateHand();
        }

        public void HiddenAddToHand(Card inCard)
        {
            Console.WriteLine("The dealer drew a hidden card");
            mHand.Add(inCard);
            mPoints = this.CalculateHand();
        }

        public void DiscardHand()
        {
            for (int i = 0; i < mHand.Count; i++)//Clears hand
                mHand.Remove(mHand[i]);

            mPoints = 0;//Removes points


            
        }

        public void PrintHand()
        {
            for (int i = 0; i < mHand.Count; i++)
            {
                mHand[i].PrintCard();

            }
        }

        public void SortHand()
        {
            Card tempCard = new Card();
            for (int i = 0; i < mHand.Count; i++)//Sorted using a bubble sort
            {
                for (int j = 0; j < mHand.Count - 1; j++)
                {
                    if (mHand[j].GetValue() > mHand[j + 1].GetValue())
                    {
                        tempCard = mHand[j];
                        mHand[j] = mHand[j + 1];
                        mHand[j + 1] = tempCard;
                    }

                }
                

                    

                
                


            }
        }

        public int CalculateHand()
        {
            this.SortHand();
            int value = 0;
            for (int i = 0; i < mHand.Count; i++)
            {

                if ((int)mHand[i].GetValue() == 12)//If its a Jack
                {
                    value += 10;
                }
                else if ((int)mHand[i].GetValue() == 13)//If its a King
                {
                    value += 10;
                }
                else if ((int)mHand[i].GetValue() == 14)//If its a Queen
                {
                    value += 10;
                }
                else if(!((int)mHand[i].GetValue() == 11))//If its not an of those or not an ace
                {
                    value += (int)mHand[i].GetValue();
                }

                if ((int)mHand[i].GetValue() == 11)//If its an ace.
                {                                   //Added the ace check to the end to calculate if we should go with 1 or 11
                    if (value >= 11) //If the value is greater or equal to 11, we only add 1. That way we never go up beyond 21 off an ace.
                    {
                        value += 1;
                    }
                    else//If its less than 11, we can add all 11 points safely.
                    {
                        value += 11;
                    }

                }

            }
            return value;
        }

        public int GetHandSize()
        {
            return mHand.Count;
        }
    }
}
