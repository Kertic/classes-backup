using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace The_dark
{
    class Room
    {
        int mId;
        string mMessage;
        string[] mOptions = new string[2];



        public Room()
        {
            mId = -1;
            mMessage = "Default Message";
            mOptions[0] = "Default option 1";
            mOptions[1] = "Default option 2";
        }

        public Room(int id, string message, string op1, string op2)
        {
            mId = id;
            mMessage = message;
            mOptions[0] = op1;
            mOptions[1] = op2;
        }


        public int GetId()
        {
            return mId;
        }

        public string GetMessage()
        {
            return mMessage;
        }

        public string[] GetOptions()
        {
            return mOptions;
        }

        public void SetId(int id)
        {
            mId = id;
        }

        public void SetMessage(string message)
        {
            mMessage = message;
        }

        public void SetOptions(string[] options)
        {
            mOptions = options;
        }

    }
}
