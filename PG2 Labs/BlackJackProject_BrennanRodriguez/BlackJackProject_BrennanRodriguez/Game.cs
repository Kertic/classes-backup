using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlackJackProject_BrennanRodriguez
{
    class Game
    {
        int mChoice;
        Player mPlayer;
        Player mDealer;
        Deck mDeck;
        bool playerStay;
        bool dealerStay;

        public Game(Player inPlayer, Player inDealer, Deck inDeck)
        {
            mChoice = 0;
            mPlayer = inPlayer;
            mDealer = inDealer;
            mDeck = inDeck;
            playerStay = false;
            dealerStay = false;
        }

        public void MainMenu()
        {
            Console.Clear();
            Console.ForegroundColor = ConsoleColor.DarkCyan;
            Console.WriteLine("Welcome to Blackjack");
            Console.WriteLine("Please choose 1 or 2");
            Console.WriteLine("1. Start a round\n2. Quit");
            bool chose = false;
            while (!chose)//Validate choice
            {
                try
                {
                    string input = Console.ReadLine();
                    mChoice = int.Parse(input);
                    if (mChoice == 1)
                    {
                        this.StartRound();
                        chose = true;
                    }
                    else if(mChoice == 2)
                    {
                        Environment.Exit(0);
                    }
                    else
                    {
                        throw new Exception();
                    }

                }
                catch
                {

                    Console.WriteLine("Please enter a valid choice");
                }
            }


        }

        public void StartRound()
        {
            mDeck.Shuffle();
            mPlayer.AddToHand(mDeck.Draw());
            mPlayer.AddToHand(mDeck.Draw());
            Console.WriteLine("Your total is " + mPlayer.CalculateHand());
            mDealer.HiddenAddToHand(mDeck.Draw());
            mDealer.DealerAddToHand(mDeck.Draw());
            if (mPlayer.CalculateHand() > 20 || mDealer.CalculateHand() > 20)
            {
                this.GameEnd();
            }

            
            this.Choose();

           
        }

        public void Choose()//Meant for choosing hit or stay during a round
        {
            Console.WriteLine("Press 1 for hit or 2 for stay");
            bool chose = false;
            while (!chose)//Validate choice
            {
                try
                {

                    string input = Console.ReadLine();
                    mChoice = int.Parse(input);
                    if (mChoice == 1)
                    {
                        this.Hit();
                        chose = true;
                    }
                    else if (mChoice == 2)
                    {
                        this.Stay();
                        chose = true;
                    }
                    else
                    {
                        throw new Exception();
                    }

                }
                catch
                {

                    Console.WriteLine("Please enter a valid choice");
                }
            }

        }

        public void Hit()
        {
            mPlayer.AddToHand(mDeck.Draw());
            Console.WriteLine("Your total is " + mPlayer.CalculateHand());
            this.DealerChoice();
            if (mPlayer.CalculateHand() >= 21)//If you bust or hit 21
            {
                this.GameEnd();
            }
            else
            {
                this.Choose();
            }
            
        }

        public void Bust()
        {

            Console.WriteLine("You busted!");
            Console.WriteLine("Press any key to continue...");
            mPlayer = new Player();
            mDealer = new Player();
            mDeck = new Deck();
            mDeck.Shuffle();
            Console.ReadKey();
            this.MainMenu();
        }

        public void Stay()
        {
            playerStay = true;
            while (mDealer.CalculateHand() < 17)
            {
                this.DealerChoice();

            }
            this.DoesGameEnd();

        }

        public void DealerChoice()
        {
            if (mDealer.CalculateHand() < 17) 
            {
                mDealer.DealerAddToHand(mDeck.Draw());
            }

            if (mDealer.CalculateHand() >= 17)
            {
                dealerStay = true;
                if (playerStay == true)
                {
                    this.DoesGameEnd();

                }
                
            }
        }

        public void DoesGameEnd()
        {
            if (playerStay == true && dealerStay ==  true)
            {
                this.GameEnd();
            }
            else
            {
                this.Choose();
            }
        }
        public void GameEnd()
        {
            //  bool playerBust = false;
            //  bool dealerBust = false;
            int playerScore = mPlayer.CalculateHand();
            int dealerScore = mDealer.CalculateHand();

            if (mDealer.CalculateHand() > 21)//if the dealer busts
            {
                if (mPlayer.CalculateHand() > 21)//If the player busts
                {
                   
                    this.DealerWin();

                }
                else //If the player didnt bust
                {
                    this.PlayerWin();
                }

            }
            if (mPlayer.CalculateHand() > 21)//If the player busts
            {

                this.DealerWin();

            }
            if (playerScore == dealerScore)//If the score is tied
            {
                this.DealerWin();
            }
            if(playerScore > dealerScore)//If the player is beating the dealer
            {
                this.PlayerWin();
            }
            if (dealerScore > playerScore)//If the dealer is beating the player
            {
                this.DealerWin();
            }




        }

        public void PlayerWin()
        {
            Console.WriteLine("You Win!");
            Console.WriteLine("The Dealer had: ");
            mDealer.PrintHand();
            Console.WriteLine("Press any key to continue...");
            mPlayer = new Player();
            mDealer = new Player();
            mDeck = new Deck();
            mDeck.Shuffle();
            Console.ReadKey();
            this.MainMenu();
        }

        public void DealerWin()
        {
            Console.WriteLine("The Dealer won.");
            Console.WriteLine("The Dealer had: ");
            mDealer.PrintHand();
            Console.WriteLine("Press any key to continue...");
            mPlayer = new Player();
            mDealer = new Player();
            mDeck = new Deck();
            mDeck.Shuffle();
            Console.ReadKey();
            this.MainMenu();

        }




    }
}
