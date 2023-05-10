// CS311 Yoshii - Hash Table - complete all ** parts.
// Note: this class does not know the parts of element except for key
// so that it would work even if each element in the hash table changed
//---------------------------------------------------------------------

// ============================================================================
// HW#: final project
// Name: Marin Mirasol
// Compiler: g++
// File type: implementation htable.cpp
// ============================================================================
using namespace std;
#include <iostream> // allows inputting and outputting
#include "htable.h" // allows the implementation of the htable class

//----------------------------------------------------------------------------
// Do nothing since there's nothing to initialize in an empty hash table.
//----------------------------------------------------------------------------
htable::htable()
{ /* nothing to initialize, all slots will be used in output */ }

//----------------------------------------------------------------------------
// Do nothing since the slist destructor is automatically called.
//----------------------------------------------------------------------------
htable::~htable()
{ /* slist destructor called when list is out of scope */ }

//----------------------------------------------------------------------------
//PURPOSE:
// Hash function that calculates the slot of a car element with the keys.
//PARAMETER:
// Provide the year key (yearKey) to hash.
// Provide the model key (modelKey) to hash.
//----------------------------------------------------------------------------
int htable::hash(string yearKey, string modelKey)
{ 
  int yearSum = 0;  // sum from year key to calculate slot
  int modelSum = 0; // sum from model key to calculate slot
  int i;            // the index of the characters in the strings
  int mult;         // will be used in calculation to create unique a sum

  // fold the year into two different halves to add to together
  int firstHalf = 0; int secondHalf = 0;
  // extract the first half of the year
  for (i = 0, mult = 10; i < yearKey.size() / 2; i++, mult /= 10) 
    firstHalf += mult * (int)(yearKey[i] - '0');
  // extract the second half of the year
  for (i = yearKey.size() / 2, mult = 10; i < yearKey.size(); i++, mult /= 10) 
    secondHalf += mult * (int)(yearKey[i] - '0');
  // sum the two halves of the year
  yearSum = firstHalf + secondHalf;
  
  // calculate the model sum by treating a = 1, b = 2,..., treating
  // A = 1, B = 1,..., treating 0 = 0, 1 = 1,..., and treating - = 1
  // and summing all characters of the model  
  for (i = 0; i < modelKey.size(); i++)
    {
      // a model can have capital letters, so add it to the sum
      if (modelKey[i] >= 'A' && modelKey[i] <= 'Z')
	modelSum += (int)(modelKey[i] - 'A' + 1);
      // a model can have lowercase letters, so add it to the sum
      else if (modelKey[i] >= 'a' && modelKey[i] <= 'z')
	modelSum += (int)(modelKey[i] - 'a' + 1);
      // a model can have numbers, so add it to the sum
      else if (modelKey[i] >= '0' && modelKey[i] <= '9')
	modelSum += (int)(modelKey[i] - '0');  
      // a model can have dashes, so add it to the sum
      else if (modelKey[i] == '-')
	modelSum += (int)(modelKey[i] - '-' + 1);

    } // end of for loop that calculates the model sum

  // calculate slot by summing model and year sums and mod by the prime size
  return (yearSum + modelSum) % TSIZE;
}

//----------------------------------------------------------------------------
//PURPOSE:
// Adds the car element to the table and returns slot#.
//PARAMETER:
// Provide a car element object (element) to add to the hash table.
//----------------------------------------------------------------------------
int htable::add(el_t element)
{
  // hash with the two keys for the car, which are the model and year
  int slot = hash(element.getYearKey(), element.getModelKey());  
  // note that this means adding the element to a slist in the slot (addRear)
  table[slot].addRear(element);
  // return the slot number that the element was stored in the hash table
  return slot;
}

//----------------------------------------------------------------------------
//PURPOSE:
// Finds element using the skey and returns the found element
// itself or a blank element  -- there is no cout in here.
//PARAMETER:
// Provide the model key (modelKey) to search for a car in the hash table.
// Provide the year key (yearKey) to search for a car in the hash table.
//----------------------------------------------------------------------------
el_t htable::find(string yearKey, string modelKey)
{ 
  int slot = hash(yearKey, modelKey); // hash with skey
  el_t selement; // this is the element to look for in slist

  // initialize selement with just the skey
  selement.setkeys(yearKey, modelKey); 
  // call slist's search2 with selement which returns the found element 
  selement = table[slot].search2(selement);
  // return the found element from here (it could be blank)
  return selement;
}

//----------------------------------------------------------------------------
//PURPOSE:
// Displays the entire table with slot#s too.
//PARAMETER:
// Provide an output stream object (os) to output with, can be cout or fout.
//----------------------------------------------------------------------------
void htable::displayTable(ostream& os)
{
  // go through every slot in the hash table
  for (int i = 0; i < TSIZE; i++)
    { 
      // show the current hash table slot
      cout << i << ":";
      // show the whole list of collided car objects (call slist's displayAll)
      table[i].displayAll(os);
    }
}

//----------------------------------------------------------------------------
//PURPOSE:
// Displays every element in the hash table on it's own line for saved data.
//PARAMETER:
// Provide an output stream object (os) to output with, can be cout or fout.
//----------------------------------------------------------------------------
void htable::displayTable2(ostream& os)
{
  // go through every slott in the hash table
  for (int i = 0; i < TSIZE; i++)
    {
      slist l = table[i]; // get the list of collided elements in the slot
      cout << i << ":";   // show the hash table to show info before saving
      l.displayAll(cout); // show the list of collided elements

      while (!l.isEmpty()) // if list is not empty, keep extracting from it
	{
	  el_t E;             // will hold an element from the list
	  l.deleteFront(E);   // get each element from the list
	  os << E << endl;    // show each element on its own line
	} 
    } // end of for loop that goes through each hash table slot
}

//----------------------------------------------------------------------------
//PURPOSE:
// Deletes a car element from hash table by getting an element from client
// with just the two keys to search for and find the element to delete.
//PARAMETER:
// Provide a car element (element) to delete from the hash table.
//----------------------------------------------------------------------------
int htable::deleteIt(el_t element)
{
  // hash with the keys to find where the element should be in the hash table
  int slot = hash(element.getYearKey(), element.getModelKey()); 
  // find the position of the car element to delete in the slist
  int delPos = table[slot].search(element);
  // if found in slist delPos is not 0, so delete and return it's hash pos
  if (delPos != 0) { table[slot].deleteIth(delPos, element); return slot; }
  // otherwise, return -1 to indicate that it was not deleted since not found
  else return -1;
}

