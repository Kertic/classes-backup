using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab7_BrennanRodriguez
{
	class LinkedList<Type>
	{
		// Nested Node class
		// Nodes need data (the same type as the generic type our class stores, and a next node variable.
        class Node
        {
           public Type data;
           public Node next;

        }
        Node head;
        int count;
			// The data itself
			// Whoever comes after... the next entry in the list.


		// Need a head of the list, and a counter for how many nodes we've got.

		public LinkedList()
		{
            head = null;
            count = 0;
			// Head should be initalized to null
			// Any count should be zero.
		}

		public void AddHead(Type _data)
		{
            Node newNode = new Node();
            newNode.data = _data;// Create a new node, initialize it with the data



            newNode.next = head;// The new node points to the head as its next node

            head = newNode;// The head becomes the new node
            count++;

        }

		public Type RemoveHead()//The word document doesnt specify this function, and the lab tech made a guess as to what to return. He said return the removed value.
		{
            Type toReturn = default(Type);
            if (head != null)// If the head is not null... (can't remove an empty node)
            {
                toReturn = head.data;
                head = head.next;// Head should now point at the current head's next node.

            }
            return toReturn;
    
		}

		public int Remove(Type _value)
		{
			// Begin at the beginning.
			Node node = head;	
			Node previous = null;
            int numberRemoved = 0;
            // Create a next and previous node, to help loop through all the items in our list

            

            // As long as we have a valid node
            while (node != null)// As long as the current node isn't null...
            {



                if (node.data.Equals(_value) == true)// Check if the data in the current node is equal to what is being passed in.
                {
                    if (previous == null)// If so, check for a previous node value of null... If that's the case, we're at the head of the list.
                    {
                        RemoveHead();// Remove nodes the same way as RemoveHead() -- update head to head's next
                    }
                    else// Else, set the previous node's next to the current node's next (to skip over the current node in future iterations)
                    {
                        previous.next = node.next;

                    }
                    numberRemoved++;


                }
                if (!(node.data.Equals(_value) == true))// If the data is not equal (i.e. this is not the node we're looking for)
                {
                    previous = node;// Set the previous node previous to the current node...
                    // The next node visited will use this one as the previous

                }



                node = node.next;// Go to the next node to repeat the process
            }
            return numberRemoved;
		}

		public bool InsertAt(int index, Type _data)
		{
            if (index < 0 || index > count)// Check for out of bounds of our list (less than zero, or more than we have nodes)
            {
                return false;
            }

            Node newNode = new Node();
            newNode.data = _data;// Create a new node, initialize with incoming data

            if (head == null)// If the head is null, add the new node as the head and that's it
            {
                head = newNode;
                return true;
            }

            // Start at the beginning...
           Node currentNode = head;
            // Proceed through a number of nodes equal to the index - 1 (we need to stop BEFORE the index to add)
            for (int i = 0; i < index -1; i++)
            {
                currentNode = currentNode.next;

            }

            newNode.next = currentNode.next;// Our new node's next should be the current node's next

            currentNode.next = newNode;// The current node's next should be our new node.
            return true;
		}

        public bool RemoveAt(int index)
        {
            if (index < 0 || index > count)// Check for out of bounds of our list (less than zero, or more than we have nodes)
            {
                return false;
            }

            if (index == 0)
            {
                if (head != null)
                {
                    RemoveHead();
                    return true;

                }
                else
                {
                    return false;
                }
                
            }
            // Start at the beginning...
            Node currentNode = head;
            // Proceed through a number of nodes equal to the index (we need to stop BEFORE the index to add)
            for (int i = 0; i < index -1 ; i++)
            {
                currentNode = currentNode.next;

            }
            if (currentNode.next == null) // if we're trying to remove one thats not there
            {
                return false;

            }
            if (currentNode.next == null)
            {
                return false;
            }
            currentNode.next = currentNode.next.next;//set the (node at the index)'s next to 1 after its current next(or its next's next)


            return true;
        }



        // Print all values to the screen.
        public void Print()
		{
            // Begin at the beginning.
            Node reader = head;
                while (reader != null)// As long as we have a valid node
                {
                Console.WriteLine(reader.data);// Do something with it.
                reader = reader.next;// Update our reference... move on to the next guy

            }
            

				

				

		}
	}
}
