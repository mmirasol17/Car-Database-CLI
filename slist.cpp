// CS311 Yoshii Complete all functions with their comments

//==================================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: Marin Mirasol
//Complier:  g++
//File type: slist.cpp implementation file
//==================================================================

using namespace std;
#include <iostream> // allows inputting and outputting
#include "slist.h" // allows the use of the slist class

// ** Make sure llist constructor and destructors have couts in them

//---------------------------------------------------------------
//PURPOSE:
// The constructor for llist already initializes the data members
// for the list so this constructor does not need anything in it.
//---------------------------------------------------------------
slist::slist()
{ /* cout << "slist constructor:" << endl; */ }

//---------------------------------------------------------------
//PURPOSE:
// Loops by searching from the front and then moving to the next
// nodes until it finds the key that was provided. If the key was
// found, the position will be returned, otherwise return 0.
//PARAMETER:
// Provide an element (key) to search for in the list.
//---------------------------------------------------------------
int slist::search(el_t key)
{
  Node* P = Front; // local pointer that will move when searching

  // go through the list until the correct node is found
  for (int i = 1; i <= Count; i++)
    {
      // if the current node holds the element, return the position
      if (P->Elem == key) return i;
      // move to the next node to continue searching if not found
      P = P->Next;
    }

  return 0; // if the key wasn't found, it does not exist
}

//---------------------------------------------------------------
//PURPOSE:
// Loops by searching from the fornt and then moving to the next
// nodes until it finds the element to search for. If the element
// was found, the element object itself will be returned, otherwise
// a blank element object will be returned if not found.
//PARAMETER:
// Provide an element (X) to search for in the list.
//---------------------------------------------------------------
el_t slist::search2(el_t X)
{ 
  el_t M; // blank
  Node* P = Front; // local pointer that will move when searching

  // X has only the ID part.
  // In the slist look for matching el_t in Elem
  for (int i = 1; i <= Count; i++)
    {
      // Return the el_t obj itself if found
      if (P->Elem == X) return P->Elem;
      // move to the next node to continue searching if not found
      P = P->Next;
    }

  return M; // or if not found return a blank object M 
}

//---------------------------------------------------------------
//PURPOSE:
// If the position provided does not exist in the list, throw
// OutOfRange since there is no position to replace. Otherwise,
// the position exists and the node in that position can have
// its element replaced by the element provided by moving a local
// pointer to the position to replace by calling moveTo, then
// replacing the element of the node the local pointer points to.
//PARAMETER:
// Provide an element (element), which will be used to replace.
// Provide a position (pos) of the node to replace its element.
//---------------------------------------------------------------
void slist::replace(el_t element, int pos)
{
  // if pos is out of bounds, the OutOfRange exception must be 
  // thrown since this position does not exist in the list
  if (pos < 1 || pos > Count) throw OutOfRange();
  // otherwise a position on the list can be replaced
  else
    {
      // local pointer that will move to point to the position
      Node* P = Front;
      // move P to the position of the Node that will be replaced
      moveTo(pos, P);
      // replace the node's element with the element passed
      P->Elem = element;
    }
}

//---------------------------------------------------------------
//PURPOSE:
// Check if the left list and the right list has the same amount
// of elements. If not, the lists are definitely not the same.
// Otherwise, each of the nodes of both lists can be compared
// by using local pointers to start at the front of the list and
// keep move to the next nodes to compare the pairs of elements.
// If the pointers end up finding different elements, the two
// lists are not the same. Otherwise, if the pointers end up
// reaching the end of both lists and both elements are the same,
// this means that both lists are the same.
//PARAMETER:
// Provide a holder (OtherOne) for the other list to compare, 
// which is the list to the right of the operator when called.
// EX: (this)leftList == (OtherOne)rightList
//---------------------------------------------------------------
bool slist::operator==(const slist& OtherOne)
{
  // if not the same length, return false
  if (this->Count != OtherOne.Count) return false;
  // if the same lengths,
  // check each node to see if the elements are the same
  else
    {
      // pointer to move to check this list's element(s)
      Node* P = this->Front;
      // pointer to move to check the other list's element(s)
      Node* Q = OtherOne.Front;

      // go through the entire list of both lists to check each
      // node side-by-side to see if the lists are equivalent
      for (int i = 1; i <= Count; i++)
	{
	  // if the current element of both lists are not the
	  // same, the lists are not equivalent to eachother
	  if (P->Elem != Q->Elem) return false;
	  // if no different element was found yet, move both 
	  // pointers to the next node to check the next element
	  P = P->Next; Q = Q->Next;
	}
      // if there were no different elements found and the 
      // entire array was checked, both lists are equivalent
      return true;

    } // end of else that checks to see if the lists are equal
}
