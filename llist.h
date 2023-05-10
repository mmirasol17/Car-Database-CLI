//CS311 Yoshii
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// ==========================================================================
// HW#: final project
// Your name: Marin Mirasol
// Compiler:  g++ 
// File type: header file llist.h
//===========================================================================

#include "elem.h" // allows the use of the el_t class

// alias el_t : element type definition
// typedef char el_t; (do not need anymore since using el_t class)

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};

//-----------------------------------------------------------------------------

class llist // define the llist class
{
    
 protected: // allows members to be accessed in inherited classes
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  //PURPOSE:            
  // Utility Function to move a local pointer to the Jth node. 
  //PARAMETER:                           
  // Provide a position (J) to move the pointer to.
  // Provide a holder (temp) for the pointer that is moved (pass by ref).
  void moveTo(int, Node*&);
  
 public:
  // Exception handling classes 
  class Underflow{};   // thrown when deleting when no nodes exist
  class OutOfRange{};  // thrown when the specified Node is out of range

  //PURPOSE:                                          
  // Constructor must initialize the front and rear to NULL since there
  // are no nodes to point to and count must be 0 since the list is empty. 
  llist (); // constructor to create a list object
  //PURPOSE:                             
  // Destructor must destroy the list object by deleting all of its   
  // contents from the heap since it will stay there until deleted.
  ~llist(); // destructor to destroy all nodes
  
  //PURPOSE:                                    
  // Checks front, rear and count and returns true if empty, false otherwise.
  bool isEmpty();
    
  //PURPOSE:                                      
  // Calls isEmpty and if true, displays [ empty ]. Otherwise, displays
  // all of the elements horizontally with space between each element.   
  void displayAll(ostream&);

  //PURPOSE:                          
  // Calls isEmpty and if true, it is a special case, where both front and
  // rear must point to the node that is added. Otherwise, the element can
  // be added to the new front node, which is before the old front node.
  //PARAMETER:           
  // Provide an element (NewNum) that will be added to the front.
  void addFront(el_t);
    
  //PURPOSE:                             
  // Calls isEmpty and if true, it is a special case, where both front and 
  // rear must point to the node that is added. Otherwise, the element can 
  // be added to the new rear node, which is after the old rear node. 
  //PARAMETER:                    
  // Provide an element (NewNum) that will be added to the rear.
  void addRear(el_t);

  //PURPOSE:
  // Calls isEmpty and if true, an underflow exception must be thrown, since
  // there are no nodes that can be deleted. Otherwise, an element can be
  // given back and deleted from the front. If there is only one node, both
  // front and rear will point back to NULL since the last node will be 
  // deleted, otherwise, a node can be deleted from the front normally. 
  //PARAMETER:                   
  // Provide a holder (OldNum) for the element of the node deleted (pass by ref).
  void deleteFront(el_t&);
    
  //PURPOSE:
  // Calls isEmpty and if true, an underflow exception must be thrown, since
  // there are no nodes that can be deleted. Otherwise, an element can be
  // given back and deleted from the rear. If there is only one node, both
  // front and rear will point back to NULL since the last node will be 
  // deleted, otherwise, a node can be deleted from the rear normally.
  //PARAMETER:
  // Provide a holder (OldNum) for the element of the node deleted (pass by ref).
  void deleteRear(el_t&);
    
  //PURPOSE:
  // Use moveTo to move local pointers, which will become the nodes that
  // surround the Ith node. These nodes will be manipulated so that the
  // Ith node is deleted. However, if I is the first or last position of
  // the list, deleteFront or deleteRear will be called. Otherwise, a node
  // will be deleted regularly in between.
  //PARAMETER:
  // Provide a position (I) to delete from the node.
  // Provide a holder (OldNum) for the element removed (pass by ref).
  void deleteIth(int, el_t&);  // calls moveTo

  //PURPOSE:
  // Use moveTo to move the local pointers that will surround the Ith node
  // after it is inserted. These nodes will be manipulated so that the Ith
  // node will be inserted between these nodes. However, if I is the first
  // or last position of the list, addFront or addRear will be called.
  // Otherwise, a node will be added regularly in between the pointers.
  //PARAMETER:
  // Provide a position (I) to insert a node into.
  // Provide an element (newNum) to be the element of the node to insert.
  void insertIth(int, el_t);   // calls moveTo

  //PURPOSE:
  // Copy constructor to allow pass by value and return by value of a llist.
  //PARAMETER:
  // Provide a holder (Original) for the original list to copy (pass by ref).
  llist(const llist&);
  
  //PURPOSE:
  // Delete the nodes from the this list because we are going to copy the
  // contents from a different list into this list.
  //PARAMETER:
  // Provide a holder (OtherOne) for the other list to be copied (pass by ref).
  llist& operator=(const llist&); 

}; // end of the class definition
