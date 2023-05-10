//CS311 Yoshii Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes

//EMACS HINT:
//  You can copy from a Word document to emacs (contrl-right click)
//  cntr-K cuts and cntr-Y pastes
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

//=============================================================================
//HW#: final project
//Your name: Marin Mirasol
//Complier:  g++
//File type: implementation llist.cpp
//=============================================================================

using namespace std;
#include<iostream> // allows inputting and outputting
#include"llist.h" // includes the definition of the llist class

//-------------------------------------------------------------------------
//PURPOSE: 
// Constructor must initialize the front and rear to NULL since there 
// are no nodes to point to and count must be 0 since the list is empty.
//-------------------------------------------------------------------------
llist::llist()
{ 
  // show that the constructor is being called
  // cout << "... in llist constructor ..." << endl;
  // initialize front and rear to NULL since there are no nodes to point to
  Front = NULL; Rear = NULL;
  // initialize count to 0 since there are no existing nodes in the list
  Count = 0;
}

//-------------------------------------------------------------------------
//PURPOSE:
// Destructor must destroy the list object by deleting all of its
// contents from the heap since it will stay there until deleted.
//-------------------------------------------------------------------------
llist::~llist()
{ 
  // show that the destructor is being called
  // cout << "... in llist destructor ..." << endl; 
  //while the list is not empty, delete any existing nodes
  while (!isEmpty())
    {
      // create a temporary variable to be a place holder for the parameter
      el_t temp;
      // delete the current front node from the list
      deleteFront(temp);
    }
}

//-------------------------------------------------------------------------
//PURPOSE:
// Checks front, rear and count and returns true if empty, false otherwise.
//-------------------------------------------------------------------------
bool llist::isEmpty() // checks all 3 data members
{ 
  // front, rear are NULL and count is 0 if the list is empty
  if (Front == NULL && Rear == NULL && Count == 0) return true;
  // otherwise, the list is not empty
  else return false;
} 

//-------------------------------------------------------------------------
//PURPOSE:
// Calls isEmpty and if true, displays [ empty ]. Otherwise, displays
// all of the elements horizontally with space between each element.
//PARAMETERS:
// Provide an output stream object (os) to output with, can be cout or fout.
//-------------------------------------------------------------------------
void llist::displayAll(ostream& os) 
{ 
  Node* P = Front; // the local pointer that will move to each node to show
  os << "[ "; // outer bracket border to the left of the elements

  // if the list is empty, there are no elements to show, so show "empty"
  if (isEmpty()) os << "empty ";
  else // otherwise, show all the elements in the list horizontally
    {
      // show each element in the list with a space between each element
      while (P != NULL) { os << P->Elem << " "; P = P->Next; }
    }

  os << "]" << endl; // outer bracket border to the right of the elements
}
  
//-------------------------------------------------------------------------
//PURPOSE:
// Calls isEmpty and if true, it is a special case, where both front and
// rear must point to the node that is added. Otherwise, the node can
// be added to the new rear node, which is after the old rear node.
//PARAMETER:
// Provide an element (NewNum) that will be added to the rear.
//-------------------------------------------------------------------------
void llist::addRear(el_t NewNum) // 2 cases
{
  // CASE 1:
  // if this is the first element is being added, both front and rear must be
  // moved to point to the node added, as it will be the only node in the list
  if (isEmpty()) 
    {
      Rear = new Node; // create the first node to add to the list
      Rear->Elem = NewNum; // store the element into that node
      Rear->Next = NULL; // next should be NULL since this is the rear node
      Front = Rear; // since this is the first node, it should be front as well
      Count++; // increment count since the first node was added to the list
    }
  // CASE 2:
  // otherwise, the element must be added after the current rear node
  else 
    {
      Rear->Next = new Node; // create a new node after the rear using next
      Rear = Rear->Next; // move rear to next since this is the new rear node
      Rear->Elem = NewNum; // store the element into this node
      Rear->Next = NULL; // next should be node since this is the rear node
      Count++; // increment count since a new node was added to the rear
    }
}

//-------------------------------------------------------------------------
//PURPOSE:
// Calls isEmpty and if true, it is a special case, where both front and
// rear must point to the node that is added. Otherwise, the element can 
// be added to the new front node, which is before the old front node.
//PARAMETER:
// Provide an element (NewNum) that will be added to the front.
//-------------------------------------------------------------------------
void llist::addFront(el_t NewNum) // 2 cases
{
  // CASE 1:
  // if this is the first element being added, both front and rear must be 
  // moved to point to the node added, as it will be the only node in the list
  if (isEmpty())
    {
      Front = new Node; // create the first node to add to the list
      Front->Elem = NewNum; // store the element into that node
      Front->Next = NULL; // next should be NULL since this is the rear node
      Rear = Front; // since this is the first node, it should be rear as well
      Count++; // increment count since the first node was added to the list
    }
  // CASE 2:
  // otherwise, the element must be added before the current front node
  else 
    {
      Node* NewFront = new Node; // create the new node to add to the list
      NewFront->Elem = NewNum; // store the element into that node
      NewFront->Next = Front; // the next should be the old front
      Front = NewFront; // now move the front to point to this new node
      Count++; // increment count since a new node was added to the front
    }
}

//-------------------------------------------------------------------------
//PURPOSE:
// Calls isEmpty and if true, an underflow exception must be thrown, since
// there are no nodes that can be deleted. Otherwise, an element can be
// given back and deleted from the front. If there is only one node, both
// front and rear will point back to NULL since the last node will be 
// deleted, otherwise, a node can be deleted from the front normally.
//PARAMETER:
// Provide a holder (OldNum) for the element of the node deleted (pass by ref).
//-------------------------------------------------------------------------
void llist::deleteFront(el_t& OldNum) // 3 cases
{
  // CASE 1: 
  // if the list is empty, no nodes can be deleted, so throw Underflow
  if (isEmpty()) throw Underflow();
  else // otherwise, a node can be deleted
    {
      // CASE 2:
      // if there is only one node left, the only node should be deleted, and
      // since the list will become empty, front and rear must point to NULL
      if (Count == 1 && Front->Next == NULL && Rear->Next == NULL)
	{
	  OldNum = Front->Elem; // get the element of the node being deleted
	  delete Front; // delete the node that front points to

	  // front and rear should now point to NULL since no nodes exist
	  Front = NULL; Rear = NULL;
	  Count--; // decrement since the last node was deleted
	}
      // CASE 3:
      // otherwise, the current front node must be deleted
      else 
	{
	  OldNum = Front->Elem; // get the element of the node being deleted
	  Node* NewFront = Front->Next; // record the soon to be new front  
	  delete Front; // delete the node that front points to
	  Front = NewFront; // move front to point to the new front
	  Count--; // decrement since the old front node was deleted
	}

    } // end of else statement where a node can be deleted
}

//-------------------------------------------------------------------------
//PURPOSE:
// Calls isEmpty and if true, an underflow exception must be thrown, since
// there are no nodes that can be deleted. Otherwise, an element can be 
// given back and deleted from the rear. If there is only one node, both
// front and rear will point back to NULL since the last node will be 
// deleted, otherwise, a node can be deleted from the rear normally.
//PARAMETER:
// Provide a holder (OldNum) for the element of the node deleted (pass by ref).
//-------------------------------------------------------------------------
void llist::deleteRear(el_t& OldNum) // 3 cases
{
  // CASE 1:
  // if the list is empty, no nodes can be deleted, so throw Underflow
  if (isEmpty()) throw Underflow();
  else // otherwise, a node can be deleted 
    {
      // CASE 2:
      // if there is only one node left, the only node should be deleted, and 
      // since the list will become empty, rear and front must point to NULL
      if (Count == 1 && Front->Next == NULL && Rear->Next == NULL)
	{
	  OldNum = Rear->Elem; // get the element of the node being deleted
	  delete Rear; // delete the node that rear points to

	  // rear and front should now point to NULL since no nodes exist
	  Rear = NULL; Front = NULL;
	  Count--; // decrement since the last node was deleted
	}
      // CASE 3:
      // otherwise, the current rear node must be deleted
      else 
	{
	  OldNum = Rear->Elem; // get the element of the node being deleted
	  Node* NewRear = Front; // will move to point to the new rear

	  // keep moving pointer until it points to the second to last node
	  while (NewRear->Next != Rear) NewRear = NewRear->Next;

	  delete Rear; // delete the node that rear points to
	  Rear = NewRear; // now make the rear point to the new rear
	  Rear->Next = NULL; // it's next
	  Count--; // decrement since the old rear node was deleted
	}

    } // end of else statement where a node can be deleted
}

/* harder ones follow */

//-------------------------------------------------------------------------
//PURPOSE: 
// Utility Function to move a local pointer to the Jth node.
//PARAMETER:
// Provide a position (J) to move the pointer to.
// Provide a holder (temp) for the pointer that is moved (pass by ref).
//-------------------------------------------------------------------------
void llist::moveTo(int J, Node*& temp)
{ 
  // moves temp J-1 times to go to the Jth node
  for (int K = 1; K <= J - 1; K++) temp = temp->Next;
}

//-------------------------------------------------------------------------
//PURPOSE:
// Use moveTo to move local pointers, which will become the nodes that
// surround the Ith node. These nodes will be manipulated so that the
// Ith node is deleted. However, if I is the first or last position of
// the list, deleteFront or deleteRear will be called. Otherwise, a node
// will be deleted regularly in between.
//PARAMETER:
// Provide a position (I) to delete from the node.
// Provide a holder (OldNum) for the element removed (pass by ref).
//-------------------------------------------------------------------------
void llist::deleteIth(int I, el_t& OldNum) 
{
  // CASE 1:
  // if I is out of bounds, then an OutOfRange exception must be 
  // thrown since this position does not exist in the list
  if (I > Count || I < 1) throw OutOfRange();
  // otherwise, the element of the position can be deleted
  else
    {
      // CASE 2:
      // if I = 1, this is basically deleting from the front of the list
      if (I == 1) deleteFront(OldNum);
      // CASE 3:
      // if I = Count, this is basically deleting from the rear of the list
      else if (I == Count) deleteRear(OldNum); 
      // CASE 4:
      // otherwise, the element is deleted from a middle position in the list
      else
	{
	  // make the pointers start at the starting point front before moving
	  Node* P = Front; Node* Q = Front;
	  // move P before the node being deleted, move Q after the node
	  moveTo(I - 1, P); moveTo(I + 1, Q);
	  // local pointer that points to the node that will be deleted
	  Node* DeleteNode = P->Next;
	  // get the element of the node that will be deleted
	  OldNum = DeleteNode->Elem;
	  // delete the Ith, which is the node between P and Q
	  delete P->Next; 
	  // move P's next to point to the Q node to replace the deleted node
	  P->Next = Q;
	  // since a node was deleted, decrement count
	  Count--;
	}
    }
}

//-------------------------------------------------------------------------
//PURPOSE:
// Use moveTo to move the local pointers that will surround the Ith node
// after it is inserted. These nodes will be manipulated so that the Ith
// node will be inserted between these nodes. However, if I is the first
// or last position of the list, addFront or addRear will be called.
// Otherwise, a node will be added regularly in between the pointers.
//PARAMETER:
// Provide a position (I) to insert a node into.
// Provide an element (newNum) to be the element of the node to insert.
//-------------------------------------------------------------------------
void llist::insertIth(int I, el_t newNum) 
{
  // CASE 1:
  // if I is out of bounds, then an OutOfRange exception must be 
  // thrown since this position does not exist in the list
  if (I > Count + 1 || I < 1) throw OutOfRange();
  // otherwise, the node of the position can be added
  else
    {
      // CASE 2:
      // if I = 1, this is basically adding to the front of the list
      if (I == 1) addFront(newNum);
      // CASE 3:
      // if I = Count + 1, this is basically adding to the rear of the list
      else if (I == Count + 1) addRear(newNum);
      // CASE 4:
      // otherwise, the element is added to a middle position in the list
      else
	{
	  // make the pointers start at the starting point front before moving
	  Node* P = Front; Node* Q = Front;
	  // move P before the spot to insert the new node, 
	  // but move Q to the current node that occupies I
	  moveTo(I - 1, P); moveTo(I, Q);
	  // create the new node that will be inserted
	  Node* InsertNode = new Node;
	  // store the element into this node
	  InsertNode->Elem = newNum;
	  // make P's next now point to this inserted node since it's before
	  P->Next = InsertNode;
	  // now make the inserted node's next point to Q since Q is after
	  InsertNode->Next = Q;
	  // since a node was inserted, increment count
	  Count++;
	}
    }
}

//-------------------------------------------------------------------------
//PURPOSE:
// Copy constructor to allow pass by value and return by value of a llist.
//PARAMETER:
// Provide a holder (Original) for the original list to copy (pass by ref).
//-------------------------------------------------------------------------
llist::llist(const llist& Original) // use my code
{
  // show that the copy constructor is called when llist is passed by value
  // cout << "... in llist copy constructor ..." << endl;

  // this->'s data members need to be initialized here first
  Front = NULL; Rear = NULL; Count = 0;
  // this-> object has to be built up by allocating new cells
  // and copying the values from Original into each cell as we 
  // did with operator= above. 
  
  // To do this, copy here the (**) lines in Operator Overloading
  // of = but note that it is Original and not OtherOne.
  
  Node* P;  // local pointer for OtherOne
  P = Original.Front;
  
  // a loop which repeats until you reach the end of OtherOne. 
  while (P != NULL)  
    {
      this->addRear(P->Elem); //P’s element is added to this->
      P = P->Next; // Go to the next node in OtherOne   
    } 

  // Nothing to return because this is a constructor.
}

//-------------------------------------------------------------------------
//PURPOSE:
// Delete the nodes from the this list because we are going to copy the
// contents from a different list into this list.
//PARAMETER:
// Provide a holder (OtherOne) for the other list to be copied (pass by ref).
//-------------------------------------------------------------------------
llist& llist::operator=(const llist& OtherOne) // use my code
{
  el_t x; // local variable placeholder for the deleteRear function call

  // First make sure this-> and OtherOne are not the same object.
  // To do this, compare the pointers to the objects .
  if (&OtherOne != this)  // if not the same
    {
      // this-> object has to be emptied first.
      while (!this->isEmpty()) this->deleteRear(x);  
      
      // this-> object has to be built up by allocating 
      // new cells with OtherOne elements (**)

      Node* P;  // local pointer for OtherOne
      P = OtherOne.Front;
      
      // a loop which repeats until you reach the end of OtherOne. 
      while (P != NULL)  
        {
	  this->addRear(P->Elem); //P’s element is added to this->
	  P = P->Next; // Go to the next node in OtherOne   
	} 
      
    } // end of if that deletes the old list and copies the other to this
  
  // return the result unconditionally. Note
  // that the result is returned by reference.            
  return *this;    
}
