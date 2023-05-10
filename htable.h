// ============================================================================
// HW#: final project
// Name: Marin Mirasol
// Compiler: g++
// File type: header file htable.h 
// ============================================================================
#include "slist.h" // allows the use of the slist class

const int TSIZE = 43;  // 43 slots is a prime number 

class htable // define the hash table class
{
 private:
  slist table[TSIZE]; // each node of slist is el_t (the hash table of cars)

  //-------------------------------------------------------------------------
  //PURPOSE:                                                                
  // Hash function that calculates the slot of a car element with the keys.
  //PARAMETER:                                                              
  // Provide the year key (yearKey) to hash. 
  // Provide the model key (modelKey) to hash.                              
  //-------------------------------------------------------------------------
  int hash(string, string);  // private hash function as defined in elem.h

 public:
  // Do nothing since there's nothing to initialize in an empty hash table.
  htable(); 
  // Do nothing since the slist destructor is automatically called.
  ~htable();

  //-------------------------------------------------------------------------
  //PURPOSE:                                                          
  // Adds the car element to the table and returns slot#.             
  //PARAMETER:                                                        
  // Provide a car element object (element) to add to the hash table.
  //-------------------------------------------------------------------------
  int add(el_t);  

  //-------------------------------------------------------------------------
  //PURPOSE:                                                                 
  // Finds element using the skey and returns the found element              
  // itself or a blank element  -- there is no cout in here.                 
  //PARAMETER:                                                          
  // Provide the year key (yearKey) to search for a car in the hash table. 
  // Provide the model key (modelKey) to search for a car in the hash table.
  //-------------------------------------------------------------------------
  el_t find(string, string); 

  //-------------------------------------------------------------------------
  //PURPOSE:                                       
  // Displays the entire table with slot#s too.                     
  //PARAMETER:                                                  
  // Provide the output stream object (os) to output with, can be cout or fout.
  //-------------------------------------------------------------------------
  void displayTable(ostream&); 

  //-------------------------------------------------------------------------
  //PURPOSE:                                       
  // Displays every element in the hash table on it's own line.
  //PARAMETER:
  // Provide an output stream object (os) to output with, can be cout or fout.
  //-------------------------------------------------------------------------
  void displayTable2(ostream&);

  //-------------------------------------------------------------------------
  //PURPOSE:                                                                 
  // Deletes a car element from hash table by getting an element from client
  // with just the two keys to search for and find the element to delete.
  //PARAMETER:                                                              
  // Provide a car element (element) to delete from the hash table.
  //-------------------------------------------------------------------------
  int deleteIt(el_t);

}; // end of the hash table class definition
