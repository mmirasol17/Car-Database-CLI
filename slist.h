// CS311 Yoshii
// HW3P2 Instruction: Inherit everything publicly from llist
// Put only the following in class slist.h 
//    inheriting everything from llist.h
//
// Then create slist.cpp with only the following functions
// Complete all ** parts 
//=================================================================
// HW#: HW3P2 slist
// Name: Marin Mirasol
// File: header file slist.h
//=================================================================

#include "llist.h" // allows inheriting from the llist class

// inherit from llist with access control public
class slist: public llist 
{
 public:
  //PURPOSE:                                                        
  // The constructor for llist already initializes the data members
  // for the list so this constructor does not need anything in it.
  slist();   // constructor. cout "in slist constructor".
             // Make it do nothing else.
             // Experiment and see what happens.
             // Taking this out completely would not work.
             // But note that there is no destructor.
             // PLEASE DO NOT delete the couts in slist and llist
             // constructors and destructors for HW6!!!!!
  
  //PURPOSE:                                                        
  // Loops by searching from the front and then moving to the next  
  // nodes until it finds the key that was provided. If the key was
  // found, the position will be returned, otherwise return 0.      
  //PARAMETER:                                                      
  // Provide an element (key) to search for in the list.
  int search(el_t);
  // search through the list to see if any node contains the key.
  // If so, return its position (>=1). Otherwise, return 0.

  //PURPOSE:
  // Loops by searching from the fornt and then moving to the next
  // nodes until it finds the element to search for. If the element
  // was found, the element object itself will be returned, otherwise
  // a blank element object will be returned if not found. 
  //PARAMETER: 
  // Provide an element (X) to search for in the list.
  el_t search2(el_t);
  
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
  void replace(el_t, int);
  // go to the Ith node (if I is between 1 and Count) and 
  // replace the element there with the new element. 
  // If I was an illegal value, throw OutOfRange 
  
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
  bool operator==(const slist&);
  // checks to see of the two lists look the same
    
}; // end of the class definition
