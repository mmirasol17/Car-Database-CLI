// CS311 Yoshii - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
// --------------------------------------------------

// =====================================================================
// HW#: final project 
// Name: Marin Mirasol               
// Compiler: g++                                          
// File type: header file htable.h     
// =====================================================================
#include <iostream> // allows the use of the input, output stream
#include <string>   // allows the use of the string class
using namespace std;

class el_t // define the el_t class for a car element
{
 private:  // these will change depending on the client needs
  string year;       // the year of the car elem (ex: 2020)
  string brand;      // the brand of the car elem (ex: Toyota)
  string model;      // the model of the car elem (ex: Corolla)
  string cityMPG;    // the city MPG of the car elem (ex: 31)
  string highwayMPG; // the highway MPG of the car elem (ex: 40)
  string startPrice; // the starting price of the car elem (ex: $19600)

 public:
  // Default constructor to create a blank el_t object
  el_t();  
  // Initializing constructor create an initialized el_t object
  el_t(string, string, string, string, string, string); 
  
  //============= user can only access the keys and price ==============
  //--------------------------------------------------------
  //PUPROSE:                                                 
  // Returns year, which is another key for the car element.
  //--------------------------------------------------------
  string getYearKey();
  //--------------------------------------------------------
  //PUPROSE:
  // Returns model, which is one key for the car element.
  //--------------------------------------------------------
  string getModelKey(); 
  //--------------------------------------------------------
  //PURPOSE:                                                     
  // Will set the element's key to the key that is passed.             
  //PARAMETER:                                            
  // Provide the year key to set the element's object to.          
  // Provide the model key to set the element's object to.    
  //---------------------------------------------------------
  void setkeys(string, string);
  //--------------------------------------------------------
  //PURPOSE:
  // Will update the element's price with what is passed.
  //PARAMETER:
  // Provide the new price to set the element to.
  //--------------------------------------------------------
  void updatePrice(string); 
  //====================================================================

  //---------------------------------------------------------------
  //PURPOSE:                                                            
  // Overload == for search based on both key parts only.               
  //PARAMETER:                                                          
  // Provide another element (OtherOne) to compare to.                  
  //---------------------------------------------------------------
  bool operator==(el_t); // overload == for search

  //---------------------------------------------------------------
  //PURPOSE:                      
  // Overload != to check if an element is not the same as another.
  //PARAMETER:
  // Provide another element (OtherOne) to compare to. 
  //---------------------------------------------------------------
  bool operator!=(el_t); // overload != for search

  //--------------------------------------------------------------------
  //PURPOSE:                                                    
  // Overload cout to display the car element's information.    
  //PARAMETER:                                                   
  // Provide an output stream object (os) to output with, cout or fout.
  // Provide an element object (E) to display it's key and name.   
  //--------------------------------------------------------------------
  friend ostream& operator<<(ostream&, const el_t&); 
  
}; // end of the el_t class definition


