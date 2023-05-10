// CS311 Yoshii - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
//----------------------------------------------------

// ===================================================================
// HW#: final project
// Name: Marin Mirasol
// Compiler: g++
// File type: implementation elem.cpp
// ===================================================================
#include "elem.h" // allows the implementation of the el_t class

//--------------------------------------------------------------------
//PURPOSE:
// Default constructor that intializes a blank car element.
//--------------------------------------------------------------------
el_t::el_t()
{
  year = "";       // gives blank year
  brand = "";      // gives blank brand
  model = "";      // gives blank model
  cityMPG = "";    // gives blank city MPG
  highwayMPG = ""; // gives blank highway MPG
  startPrice = ""; // gives blank starting price
}
//--------------------------------------------------------------------
//PURPOSE:
// Initializing constructor to create an el_t car object. 
//PARAMETER:
// Provide a brand (b) for the car element.
// Provide a model (m) for the car element.
// Provide the year (y) for the car element.
// Provide the city MPG (c) for the car element.
// Provide the starting price (s) for the car element.
//--------------------------------------------------------------------
el_t::el_t(string y, string b, string m, string c, string h,string s)
{
  year = y;       // give the car element the year passed
  brand = b;      // give the car element the brand passed
  model = m;      // give the car element the model passed
  cityMPG = c;    // give the car element the city MPG passed
  highwayMPG = h; // give the car element the highway MPG passed
  startPrice = s; // give the car element the starting price passed
}

//===================== ACCESS FUNCTIONS =============================
//--------------------------------------------------------
//PUPROSE:
// Returns year, which is another key for the car element.
//--------------------------------------------------------
string el_t::getYearKey()
{ return year; }
//--------------------------------------------------------
//PUPROSE:
// Returns model, which is one key for the car element.
//--------------------------------------------------------
string el_t::getModelKey()
{ return model; }
//--------------------------------------------------------
//PURPOSE:
// Will set the element's key to the key that is passed.
//PARAMETER:
// Provide the year key to set the element's object to.
// Provide the model key to set the element's object to.
//--------------------------------------------------------
void el_t::setkeys(string yearKey, string modelKey)
{
  year = yearKey;   // give the car element the year key passed
  model = modelKey; // give the car element the model key passed
}
//--------------------------------------------------------
//PURPOSE:
// Will update the element's price with what is passed.
//PARAMETER:
// Provide the new price to set the element to.
//--------------------------------------------------------
void el_t::updatePrice(string newPrice)
{ startPrice = newPrice; }
//====================================================================

//--------------------------------------------------------------------
//PURPOSE:  
// Overload == for search based on both key parts only.
//PARAMETER:
// Provide another element (OtherOne) to compare to.
//--------------------------------------------------------------------
bool el_t::operator==(el_t OtherOne)
{
  // if elements share same keys, return true since they are equal
  if (model == OtherOne.model && year == OtherOne.year) return true; 
  // otherwise, return false since the keys are not the same 
  else return false;
}

//--------------------------------------------------------------------
//PURPOSE:
// Overload != to check if an element is not the same as another.
//PARAMETER:
// Provide another element (OtherOne) to compare to.
//--------------------------------------------------------------------
bool el_t::operator!=(el_t OtherOne)
{
  // if elements don't share same keys, return true since not equal
  if (model != OtherOne.model && year != OtherOne.year) return true; 
  // otherwise, return false since the keys are not the same
  else return false;
}

//--------------------------------------------------------------------
//PURPOSE:
// Overload cout to display the car element's information.
//PARAMETER:
// Provide an output stream object (os) to output with, cout or fout.
// Provide an element object (E) to display it's key and name. 
//--------------------------------------------------------------------
ostream& operator<<(ostream& os, const el_t& E)  
{  
  // show all of the information of this car element object
  os << E.year << " " << E.brand << " " << E.model << " ";
  os << E.cityMPG << " " << E.highwayMPG << " " << E.startPrice;
  return os; // return output object for cascading outputs
}  
