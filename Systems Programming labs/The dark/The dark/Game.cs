using System;
using FSPG;
using System.Collections.Generic;
namespace The_dark

{
    public class Game
    {
        static string message = "the_Dark ";
        //Making all the rooms
      static Room currentRoom = new Room();
      static Room menu = new Room(0, message, "Begin", "Credits");
      static Room credits = new Room(-1, "Programming - Brennan Rodriguez\nStory - Tyler Rodriguez Thank you for playing the_Dark. If you or any loved ones have any suicidal thoughts, please seek help. You are loved. Even in the darkest times, there are those who care about you and those who want you to be happy.", "Back" , "Quit");
      static Room Bedroom_1 = new Room(1, "You wake up to a heavy rain, and peer around your room. You see the linens draped over your bed and the carefully decorated walls. You hear a window creak." , "Go over to your bedroom window" ,"Ignore the sound");
      static Room Bedroom_2 = new Room(2, "You see that it's locked but you know that you heard something. As you turn to head back, you hear a ringing sound", "Continue", "Continue");
      static Room Bedroom_3 = new Room(3, "You try to go back to bed, but you are jarred out of your hazey state by an incessant ringing", "Continue", "Continue");
      static Room Hallway_1 = new Room(4, "You realize that it's coming from the hall, which begins to worry you as your adopted daughter's room is in that same hall. You leave your room and enter into the hall.", "Pursue the sound", "Go back to your room");
      static Room Hallway_2 = new Room(5, "You quickly step down the hall, your feet making disruptively loud thuds. You reach her door and it creaks open, revealing a little girl reading at her desk.", "Continue", "Continue");
      static Room Hallway_3 = new Room(6, "You decide to turn around, thinking its probably nothing. As you go to grab your door, you notice its shrouded with an unnatural darkness. It seems to eat up the light, making your door nearly imperceptible", "Pursue the sound", "Attempt to reach through the darkness");
      static Room Hallway_4 = new Room(7, "As your hand pierces the dark veil, your hand is wrapped in a shroud of gripping tendrils. You're unable to move your hand, and you begin to see flashes of blood and wounds, and feel vibrant regret fill your heart. The visions subside and your hand is thrust out of the dark. You feel compelled to run to your daughter, to ensure that she's safe.", "Continue", "Continue");
      static Room Girlroom_1 = new Room(8, "The moment you step into the room, the ringing ceases. You see her hunched over her desk, reading the book you got her for Christmas under a dim lamp's light. Seeing her safe puts you at ease, relaxing you from the stress you've just encountered. You notice her window is open, but oddly you can't feel any temperature even though there is distinct frost around the edges.", "Put a blanket on her", "Close the window");
      static Room Girlroom_2 = new Room(9, "She shudders a little bit, but then the warmth from the blanket relieves her from the cold she didn't even realize she was feeling, being so engrossed in the book.", "Close the window", "Close the window");
      static Room Girlroom_3 = new Room(10, "The window shutting suddenly startles her, and she realizes that she was cold but being so engrossed in her book caused her to not even realize it.", "Put a blanket on her", "Put a blanket on her");
      static Room Girlroom_4 = new Room(11, "Now that the window is closed and she's regaining her heat, she goes to rest her head against your torso. The moment her head makes contact, you find yourself in the hallway again, but the darkness that shrouded your door now shrouds hers.", "Continue", "Continue");
      static Room twoHallway_1 = new Room(12, "You gaze at the door, but you can't seem to remember what's on the other side... You feel a fading warmth, but its as though your memory of that room is locked away. Then a subtle ringing sound you've been hearing begins to get louder, and you can tell it's coming from the basement. " , "Grab at the door" , "Pursue the ringing");
      static Room twoHallway_2 = new Room(13, "Your hand pierces the darkness, and it's wrapped by tendrils with an almost burning feeling. You can't seem to let go of the handle, and you see flashbacks of a girl you know to be your adopted daughter. She looks to be about 16, and you see visions of her crying with your prescription medicine spilled over her floor.", "Continue", "Continue");
      static Room twoHallway_3 = new Room(14, "You begin to walk downstairs, and when you reach the main floor you hear the ringing almost emanate from the basement. You look back and notice that darkness has covered the upstairs, and when you go to look at the basement stairs you notice that you've got a candle in your hand, giving off a dim light.", "Continue", "Continue");
      static Room twoHallway_4 = new Room(15, "The vision ends, and suddenly you're at the top of the stairs to the basement, holding a dimly lit candle. You hear commotion, and wonder if maybe your daughter is down there. Panicked, you scramble down stairs and the ringing noise gets louder.", "Continue", "Continue");
      static Room Basement_1 = new Room(16, "You take your first few steps down the stairs, worried about something you can't quite put your hand on, but only the loud ringing permeates your thoughts. You wonder why your gaps in memory are happening. You might be old, but not that old and it's very odd for someone like you to be so forgetful.", "Continue", "Continue");
      static Room Basement_2 = new Room(17, "You can't see very well, only being able to see about 5 feet in front of you with the candle light. You hear the ringing sound coming from your left, where you know your work bench is. You think the ringing might be a malfunctioning piece of equipment. To your right, you think you can walk over and turn on the lights if you use the candle to guide you.", "Go to your workbench", "Go find the light switch");
      static Room Basement_3  = new Room(18, "You walk over to the workbench, and sit down at it. You try to use your candle, but it seems to get dimmer the closer you put it to the bench. You decide to set it down, but as it touches the wooden surface the light goes out and you feel tendrils gripping at your arms and torso", "Continue", "Continue");
      static Room Basement_4 = new Room(19, "You use a combination of feeling around and the dim candle light to feel your way around, but when you switch the switch on, nothing comes on. You know now that something must be wrong down here, so you go over to the fuse box located behind a panel at your work station.", "Continue", "Continue");
      static Room Basement_5 = new Room(20, "Your arms begin to get sharp, precise wounds and blood streams from them. Then the wounds burn shut, and then more wounds appear and follow suit. You get flashbacks of your wife dying in a car crash, and your daughter blaming herself. Every time the wounds appear, they cut off the pain from seeing her mangled body. You remember doing this to yourself, trying to cover up the pain from grief with the pain from your own body.", "Continue", "Continue");
      static Room threeHallway_1 = new Room(21, "You grab the candle and try to run upstairs, attempting to relight it. But every match seems to be a dud, and you notice the box frosting over. The darkness encloses the basement and it's tendrils begin to stretch out from the basement, and from the upstairs. You try to unlock your front door, but when you look to it, the dark whisps are coming in from cracks.", "Run to the kitchen", "Run to the living room");
      static Room threeHallway_2 = new Room(22, "You run away from the tendrils, but the darkness closes in around every room. You try to get as far away from them, but they grab you by the arms and legs and pull you in.", "...", "...");
      static Room Thedark_1 = new Room(23, "Your arms are not your own. Your legs are not your own. You're standing in your room, a noose tied from your closet. Your legs step onto the stool, and one arm takes the noose and puts it over your head while the other holds the near empty bottle of jack. All you can think of is your wife and how it should've been you driving your daughter that day.", "...", "...");
      static Room Thedark_2 = new Room(24, "Your daughter runs into the room, crying for you to come back, but her voice is distorted and muffled. You stand on the stool, and you can remember everything. You are ending your life, and you've seen everything that lead up to it. Even though you see your daughter, her voice sounds like its coming from behind a door. She isn't looking at you, she's looking at the results of what you've done.", "Stop", "Stop");
      static Room Thedark_3 = new Room(25, "You can't control anything. You want to stop, to be there for her. Your last thought is that you never wanted to hurt her, that it was selfish to do this. You try to move your arm to take the noose off, but your legs kick out the stool instead. You feel the breath cut off, and her voice gets clearer.", "...", "...");
      static Room Thedark_4 = new Room(26, "She's yelling for you to come back, and you see her pounding on your cold corpse. You realize that you aren't in your body, and that you're surrounded by the dark. You begin to call out \"Myra....\" until the darkness fully envelops you. You're violently jerked around in the abyss, scared and unsure of what's happening until you hear a familiar sound", "...", "...");
      static Room Thedark_5 = new Room(27, "You wake up to a heavy rain, and peer around your room. You see the linens draped over your bed and the carefully decorated walls. You hear a window creak...", "Credits", "Quit");
        //Done with all the rooms

     //   //Room debug
     //   int roomcounter = 0;
     //   Room[] roomar = { Bedroom_1, Bedroom_2, Bedroom_3, Hallway_1, Hallway_2, Hallway_3 ,Hallway_4 ,Girlroom_1 ,Girlroom_2, Girlroom_3, Girlroom_4 ,twoHallway_1, twoHallway_2, twoHallway_3 ,twoHallway_4, Basement_1 ,Basement_2 ,Basement_3 ,Basement_4, Basement_5, threeHallway_1, threeHallway_2, Thedark_1, Thedark_2, Thedark_3, Thedark_4, Thedark_5 };
     //       //End of room debug
        int input = 0;
        bool gameover = false;
        string centerMessage = message;
        string[] options = new string[2];
        
        public void Init()
        {
        //   //Debug stuff
        //   currentRoom = roomar[0];
        //   
        //
        //   //End of debug stuff ==REMOVE AFTER DEBUGGING==
            Console.SetWindowSize(100, 32);
            Utility.EOLWrap(false);
            currentRoom = menu;



        }

        public void Input()
        {
            
            bool readgood = false;
            do
            {
                Tools.ClearLine(Console.WindowHeight / 5 + 19);
                Console.SetCursorPosition((Console.WindowWidth / 2), Console.WindowHeight / 5 + 19);
                input = Utility.ReadInt();
                if (Utility.IsReadGood())
                {
                    if (input == 1 || input == 2)
                    {
                        readgood = true;
                    }
                }
            } while (!readgood);

        }
        public void Update()
        {
       //   //Debug stuff
       //   if (roomcounter < roomar.Length)
       //   {
       //       
       //       currentRoom = roomar[roomcounter];
       //       roomcounter++;
       //   }

            //End of debug stuff ==REMOVE AFTER DEBUGGING==
         if(currentRoom.GetId() == -1)
         {
             if (input == 1)
             {
                 currentRoom = menu;
                 input = 0;
             }
             if (input == 2)
             {
                 Environment.Exit(0);
             }
         }
         if (currentRoom.GetId() == 0)
         {
             if (input == 1)
             {
                 currentRoom = Bedroom_1;
                 input = 0;
             }
             if(input == 2)
             {
                 currentRoom = credits;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 1)
         {
             if (input == 1)
             {
                 currentRoom = Bedroom_2;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = Bedroom_3;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 2)
         {
             if (input == 1)
             {
                 currentRoom = Hallway_1;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = Hallway_1;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 3)
         {
             if (input == 1)
             {
                 currentRoom = Hallway_1;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = Hallway_1;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 4)
         {
             if (input == 1)
             {
                 currentRoom = Hallway_2;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = Hallway_3;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 5)
         {
             if (input == 1)
             {
                 currentRoom = Girlroom_1;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = Girlroom_1;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 6)
         {
             if (input == 1)
             {
                 currentRoom = Girlroom_1;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = Hallway_4;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 7)
         {
             if (input == 1)
             {
                 currentRoom = Girlroom_1;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = Girlroom_1;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 8)
         {
             if (input == 1)
             {
                 currentRoom = Girlroom_2;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = Girlroom_3;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 9)
         {
             if (input == 1)
             {
                 currentRoom = Girlroom_4;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = Girlroom_4;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 10)
         {
             if (input == 1)
             {
                 currentRoom = Girlroom_4;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = Girlroom_4;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 11)
         {
             if (input == 1)
             {
                 currentRoom = twoHallway_1;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = twoHallway_1;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 12)
         {
             if (input == 1)
             {
                 currentRoom = twoHallway_2;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = twoHallway_3;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 13)
         {
             if (input == 1)
             {
                 currentRoom = twoHallway_4;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = twoHallway_4;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 14)
         {
             if (input == 1)
             {
                 currentRoom = Basement_1;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = Basement_1;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 15)
         {
             if (input == 1)
             {
                 currentRoom = Basement_1;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = Basement_1;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 16)
         {
             if (input == 1)
             {
                 currentRoom = Basement_2;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = Basement_2;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 17)
         {
             if (input == 1)
             {
                 currentRoom = Basement_3;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = Basement_4;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 18)
         {
             if (input == 1)
             {
                 currentRoom = Basement_5;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = Basement_5;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 19)
         {
             if (input == 1)
             {
                 currentRoom = Basement_3;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = Basement_3;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 20)
         {
             if (input == 1)
             {
                 currentRoom = threeHallway_1;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = threeHallway_1;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 21)
         {
             if (input == 1)
             {
                 currentRoom = threeHallway_2;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = threeHallway_2;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 22)
         {
             if (input == 1)
             {
                 currentRoom = Thedark_1;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = Thedark_1;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 23)
         {
             if (input == 1)
             {
                 currentRoom = Thedark_2;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = Thedark_2;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 24)
         {
             if (input == 1)
             {
                 currentRoom = Thedark_3;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = Thedark_3;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 25)
         {
             if (input == 1)
             {
                 currentRoom = Thedark_4;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = Thedark_4;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 26)
         {
             if (input == 1)
             {
                 currentRoom = Thedark_5;
                 input = 0;
             }
             if (input == 2)
             {
                 currentRoom = Thedark_5;
                 input = 0;
             }
         }
         if (currentRoom.GetId() == 27)
         {
             if (input == 1)
             {
                 currentRoom = credits;
                 input = 0;
             }
             if (input == 2)
             {
                 Environment.Exit(0);
             }
         }

        }

        public void Render()
        {
            Console.Clear();
            centerMessage = currentRoom.GetMessage();
            options = currentRoom.GetOptions();
            Console.SetCursorPosition(0 , (Console.WindowHeight / 5));
            Tools.ScrollType(centerMessage,50);
            Console.SetCursorPosition((Console.WindowWidth / 2) - 10, Console.WindowHeight / 5 + 15);
            Tools.ScrollType("Type 1 or 2 and press enter", 15);
            Console.SetCursorPosition((Console.WindowWidth / 2) - 10, Console.WindowHeight / 5 + 16);
            Tools.ScrollType("1. " + options[0], 50);
            Console.SetCursorPosition((Console.WindowWidth / 2) - 10, Console.WindowHeight / 5 + 17);
            Tools.ScrollType("2. " + options[1], 50);

        }
        public bool GetGameState()
        {
            return gameover;
        }

        
    }
}