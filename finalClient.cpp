// Project Client using a generic hash table
// Loading the data file has to happen here because
// generic htable should not know about the file
// format.
// Change everywhere it says **
// Must write / change @@ functions in htable.
// Must improve the user interface!

// ===========================================================================
// HW#: final project
// Name: Marin Mirasol
// Compiler: g++
// File type: client finalclient.cpp 
// ===========================================================================
#include "htable.h" // allows the use of the hash table class
#include <string>   // allows the use of the string class
#include <iostream> // allows inputting and outputting
#include <fstream>  // allows the use of input and output files
#include <vector>   // allows the use of the vector class
using namespace std;

// get functions for getting valid inputs from the user:
string getYear();        // gets valid year of a car
string getBrand();       // gets valid brand of a car
string getModel();       // gets valid model of a car
string getMPG();         // gets valid MPG for a car
string getPrice();       // gets valid price for a car
char getYN();            // gets valid y or n choice from user
// utility functions that will be used in other functions:
bool goodNumber(string); // checks if a number is valid or not
bool goodBrand(string);  // checks if a brand is valid or not
bool goodModel(string);  // checks if a model is valid or not
bool goodPrice(string);  // checks if a price is valid or not
bool isLetter(char);     // checks if a character is a letter of a word
bool isDigit(char);      // checks if a character is a digit of a number

// Purpose of program: to store car data into a hash
// table to manipulate and save the data for future use.

// Algorithm/design: the user will enter an input file name that has info on
// cars. The user will have the option to read the information from that
// file and, if so, the information will be stored into a hash table where
// the user can manipulate the data by choosing any of the other options,
// which include showing the data in the hash table format, searching for
// a car, adding a new car, deleting a car, comparing cars, and saving the
// information from the hash table. The user will keep having these options
// until he or she quits the program. Ideally, if the user added or removed 
// car info from the hash table, he or she needs to save the table info into
// the output file to update the file information for future use. 

int main()
{
  htable T;  // generic hash table

  // All declarations happen outside switch
  string yr;        // the year of a car element object
  string brnd;      // the brand of a car element object
  string mdl;       // the model of a car element object
  string ctyMPG;    // the city MPG of a car element object
  string hwyMPG;    // the highway MPG of a car element object
  string strtPrice; // the starting price of a car element object
  el_t E;           // blank element

  // File info declared outside switch
  string fname = "carData.txt"; // holds filename
  int ans = 0;                  // user choice from menu
  char cont;                    // if user wants to cont or not

  // read from file with fin and open the input file entered
  ifstream fin (fname.c_str(), ios::in); 
  // while there are still years of car elements, keep reading
  while (fin >> yr)
    { 
      // read the rest of the info of that car
      fin >> brnd >> mdl >> ctyMPG >> hwyMPG >> strtPrice;  
      // add the information into the hash table 
      T.add(el_t(yr, brnd, mdl, ctyMPG, hwyMPG, strtPrice));
    } 
  cout << "loaded data..." << endl; // show that info was read
  fin.close();  // close input file since it's done being read

  // Keep showing menu to allow choices until user decides to exit
  while (ans != 8)
    {
      // show the user all of the options he or she can choose
      cout << "MENU---------------------------------- :"<<endl;
      // cout << "1. Load data from a file" << endl;
      cout << "1. See all data of the cars" << endl;
      cout << "2. Search for car using model and year" << endl;
      cout << "3. Add a new car" << endl;
      cout << "4. Delete a car" << endl;
      cout << "5. Compare cars" << endl;
      cout << "6. Update the price of a car" << endl;
      cout << "7. Save data to a file" << endl;
      cout << "8. Exit" << endl;
      cout << "==> ";
      cin >> ans; // get the choice from the user

      // check the choice to do the correct operations for the choice
      switch (ans)
	{
	  //------------------- DISPLAY CAR DATA --------------------------
	case 1: // this choice will show all car data stored in the table
	  // show the car info stored in the hash table
	  T.displayTable(cout); 
          break;
	  //------------------- SEARCH FOR A CAR --------------------------
	case 2: // this choice will search for a car
	  // ask for both of the keys that will be used to search for a car
	  cout << "Enter year of the car to search for: "; yr = getYear();
	  cout << "Enter model of the car to search for: "; mdl = getModel();
	  // search for the car element in the hash table
	  E = T.find(yr, mdl);
	  // blank, so element was not found
	  if (E == el_t()) cout << "Not found" << endl;
	  // otherwise, element was found
          else cout << "Found " << E << endl;
	  break;
	  //------------------- ADD A CAR ---------------------------------
	case 3: // this choice will add an entered car to the hash table
	  // get all of the information of a car to add
	  cout << "Enter the year of the car: "; yr = getYear();
          cout << "Enter the brand: "; brnd = getBrand();
	  cout << "Enter the model: "; mdl = getModel(); 
	  cout << "Enter the city MPG: "; ctyMPG = getMPG();
	  cout << "Enter the highway MPG: "; hwyMPG = getMPG();
	  cout << "Enter the starting price: "; strtPrice = getPrice();
	  cout << "In Slot: "; // show the slot it will be stored in
	  cout << T.add(el_t(yr, brnd, mdl, ctyMPG, hwyMPG, strtPrice));
          cout << "  added." << endl; // let user know it was added
	  break;
	  //------------------- DELETE A CAR ------------------------------
	case 4: // this choice will delete a car from the hash table
          cout << "Enter the year of the car to delete: "; yr = getYear();
	  cout << "Enter the model of the car to delete: "; mdl = getModel();
          cout << "In Slot: "; // show the slot it will be stored in
	  cout << T.deleteIt(el_t(yr, "", mdl, "", "", "")); 
          cout << "  deleted." << endl; 
          // what happens if the item was not found?
	  // -1 is shown to the user to indicate that the car wasn't found
	  break;
	  //------------------- COMPARE CARS ------------------------------
	case 5: // this choice will compare any amount of existing cars
	  {
	    // declare vector here since it will be erased after user is done
	    // comparing, as the destructor is called once it is out of scope
	    vector<el_t> carsToCompare; // holds the cars to compare
	    // keep having user enter cars to compare until he or she stops
	    do
	      {
		// get both of the keys of a car to compare
		cout << "Enter year of a car to compare: "; yr = getYear();
		cout << "Enter model of a car to compare: "; mdl = getModel();
		// search for the car to compare in the hash table
		E = T.find(yr, mdl);
		// if the car is blank, it does not exist, so let user know
		if (E == el_t()) cout << "  Car not found" << endl;
		// otherwise, the car can be added to list of cars to compare
		else carsToCompare.push_back(E);
		// ask user if he or she wants to keep adding cars to compare
		cout << "  - Enter y to keep adding cars"; 
		cout << "to compare or n to stop ==> ";
		// get y to continue or n to stop from the user
		cont = getYN();
	      }while (cont != 'n'); // end of loop that gets cars to compare
	    // show the user how many cars are being compared
	    cout << "Comparing " << carsToCompare.size() << " cars";
	    cout << "------------------------------- :" << endl;
	    // after getting cars to compare, show them for user to compare
	    for (int i = 0; i < carsToCompare.size(); i++)
	      cout << carsToCompare[i] << endl;
	  } 
	  break;
	  //------------------- UPDATE PRICE OF CAR -----------------------
	case 6: // this choice will update the price of a car
	  // get both of the keys of a car to update it's price
	  cout << "Enter year of the car to update: "; yr = getYear();
	  cout << "Enter model of the car to update: "; mdl = getModel();
	  // search for the car in the hash table
	  E = T.find(yr, mdl);
	  // if the car is blank, it does not exist, so let user know
	  if(E == el_t()) cout << "  Car not found" << endl;
	  // otherwise, the car can have it's price updated
	  else
	    {
	      // get the price to update the car to
	      cout << "  - Enter the price to update the car to: ";
	      strtPrice = getPrice();
	      // delete the old information of the car from the hash table
	      T.deleteIt(E);
	      // update the price of that car
	      E.updatePrice(strtPrice);
	      // add the new information of the car
	      T.add(E);
	      // show the updated information to the user
	      cout << E << endl;
	    }
	  break;
	  //------------------- SAVE CAR DATA IN FILE ---------------------
	case 7: // this choice will save the car info into an output file
	  {
	    // make the new file with the saved information
	    ofstream fout (fname.c_str(), ios::out);    
	    // output in same way as input file, so use other display function
	    T.displayTable2(fout);
	    // show that the data was saved in the file and close it
	    cout << "Sent data to carData.txt" << endl; fout.close(); 
	  } // end of case where user saves info into output file
	  break;
	  //---------------------------------------------------------------
        default: // nothing is done if 1-7 was not entered
	  cout << "No action" << endl;
	  break;
	}
    } // end of loop that user chooses what to do with car data
} // end of the program

//----------------------------------------------------------------------------
//PURPOSE:
// Gets a valid year input from the user.
//----------------------------------------------------------------------------
string getYear()
{
  // get the year of the car from the user
  string year; cin >> year;
  // while the year is not 4 digits and/or is not a valid number, keep asking
  while (year.size() != 4 || !goodNumber(year))
    { cout << "\tInvalid year, enter again: "; cin >> year; }
  // once a valid year is entered, return it
  return year;
}

//----------------------------------------------------------------------------
//PURPOSE: 
// Gets a valid brand input from the user.
//----------------------------------------------------------------------------
string getBrand()
{
  // get the car brand name from the user
  string brand; cin >> brand;
  // while the brand is not valid, keep asking the user for a valid brand
  while (!goodBrand(brand))
    { cout << "\tInvalid brand, enter again: "; cin >> brand; }
  // once a valid brand is entered, return it
  return brand;
}

//----------------------------------------------------------------------------
//PURPOSE:
// Gets a valid model input from the user.
//----------------------------------------------------------------------------
string getModel()
{
  // get the car model name from the user
  string model; cin >> model;
  // while the brand is not valid, keep asking the user for a valid model 
  while (!goodModel(model))
    { cout << "\tInvalid model, enter again: "; cin >> model; }
  // once a valid model is entered, return it
  return model;
}

//----------------------------------------------------------------------------
//PURPOSE:
// Gets a valid MPG input from the user
//----------------------------------------------------------------------------
string getMPG()
{
  // get the MPG of the car from the user
  string MPG; cin >> MPG; 
  // while the MPG is not a valid number, keep asking for a valid MPG
  while (!goodNumber(MPG))
    { cout << "\tInvalid MPG, enter again: "; cin >> MPG; }
  // once a valid MPG is entered, return it
  return MPG;
}

//----------------------------------------------------------------------------
//PURPOSE:
// Gets a valid price input from the user.
//----------------------------------------------------------------------------
string getPrice()
{
  // get the price of the car from the user
  string price; cin >> price;
  // while the price entered is not valid, keep asking for a valid price
  while (!goodPrice(price))
    { cout << "\tInvalid price, enter again: "; cin >> price; }
  // once a valid price is entered, return it
  return price;
}

//----------------------------------------------------------------------------
//PURPOSE:
// Gets a valid yes (y) or no (n) input from the user
//----------------------------------------------------------------------------
char getYN()
{
  // get y or n from user (yes or no)
  char YN; cin >> YN;
  // if it is not a y or n, then it is invalid, so keep asking for a choice
  while (YN != 'y' && YN != 'n')
    { cout << "\tInvalid choice, enter y or n: "; cin >> YN; }
  // once a valid choice is entered, return it
  return YN;
}

//=========================== UTILITY FUNCTIONS ==============================

//----------------------------------------------------------------------------
//PURPOSE:
// Checks if a number is valid or not, based on its characters.
//PARAMETER:
// Provide a number (number) to check if it's valid or not.
//----------------------------------------------------------------------------
bool goodNumber(string number)
{
  // if a character from the string is not a number, it is not valid
  for (int i = 0; i < number.size(); i++)
    { if (!isDigit(number[i])) return false; }
  // if checked and no errors were found, the number is a valid number
  return true;
}

//----------------------------------------------------------------------------
//PURPOSE:
// Checks if brand is valid or not, based on its characters.
//PARAMETER:
// Provide a brand (brand) to check if it's valid or not.
//----------------------------------------------------------------------------
bool goodBrand(string brand)
{
  // if a character is not a letter, then the brand is invalid
  for (int i = 0; i < brand.size(); i++)
    { if (!isLetter(brand[i])) return false; }
  // if checked and no errors were found, the brand is a valid brand name
  return true;
}

//----------------------------------------------------------------------------
//PURPOSE:
// Checks if model is valid or not, based on its characters.
//PARAMETER:
// Provide a model (model) to check if it's valid or not.
//----------------------------------------------------------------------------
bool goodModel(string model)
{
  // check all characters to make sure the model is valid
  for (int i = 0; i < model.size(); i++)
    {
      // to be a valid model, the model must consist of letters, numbers, 
      // and/or dashes, and if a different character is found return false
      if(!isLetter(model[i]) && !isDigit(model[i]) && model[i] != '-') 
	return false; 
    }
  // if checked and no errors were found, the model is a valid model name
  return true;
}

//----------------------------------------------------------------------------
//PURPOSE:
// Checks if a price is valid or not, based on its characters.
//PARAMETER:
// Provide a price (price) to check if it's valid or not.
//----------------------------------------------------------------------------
bool goodPrice(string price)
{
  // if the price does not start with a dollar sign, it is not valid
  if (price[0] != '$') return false;
  // if the rest of the characters are not numbers, it is not valid
  for (int i = 1; i < price.size(); i++)
    { if (!isDigit(price[i])) return false; }
  // if checked and no errors were found, the price is valid
  return true;
}

//----------------------------------------------------------------------------
//PURPOSE:
// Checks if a character is a letter or not for a word.
//PARAMETER:
// Provide a character (c) to check if it's a letter or not in a word.
//----------------------------------------------------------------------------
bool isLetter(char c)
{
  // if the character is a letter for a word, return true
  if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) return true;
  // otherwise, it is not a letter for a word, so return false
  else return false;
}

//----------------------------------------------------------------------------
//PURPOSE:
// Checks if a character is a digit or not for a number.
//PARAMTER:
// Provide a character (c) to check if it's a digit or not in a number.
//----------------------------------------------------------------------------
bool isDigit(char c)
{
  // if the character is a digit for a number, return true
  if (c >= '0' && c <= '9') return true;
  // otherwise, it is not a digit for a number, so return false
  else return false;
}



