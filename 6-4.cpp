/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Rami Amm
 */
#include "std_lib_facilities.h"	
#include <vector>
#include <string>
void pause();
void getNumbers();
void printNumbers();
using namespace std;
vector <int> digits;
char er = 'n'; //for error checking

int main()
{
 //get the numbers and convert them to an int from string
 getNumbers();

 //print the numbers out
 printNumbers();


 //ask for letter to quit the program
 pause();

 return 0;
}


void getNumbers()
{
 er = 'n';
 cout << "Please enter a number with up to 4 digits: ";
 string x;
 cin >> x; 

 //error checking
 for (int i = 0; i < x.size(); ++i)
 {
  for (char n = 'a'; n < 'z'; ++n)
  {
   while (x[i] == n)
   {
    er = 'y';
    cout << "That is not a number. Sorry.\n";
    return;
   }  
  }

  int num = x[i] - '0'; //converts letter to int
  digits.push_back(num); //pushes back into int vector
 }
}

void printNumbers()
{
 //continue to get input while er is equal to y
 while (er == 'y')
  getNumbers();

 for (int i = 0; i < digits.size(); ++i)
  cout << digits[i];

 cout << " is ";

 if (digits.size() == 4)
 {
  if (digits[0] == 1)
   cout << digits[0] << " thousand and ";
  else
   cout << digits[0] << " thousands and ";

  if (digits[1] == 1)
   cout << digits[1] << " hundred and ";
  else
   cout << digits[1] << " hundreds and ";

  if (digits[2] == 1)
   cout << digits[2] << " ten and ";
  else
   cout << digits[2] << " tens and ";

  cout << digits[3] << " ones.\n";
 }


 if (digits.size() == 3)
 {
  if (digits[0] == 1)
   cout << digits[0] << " hundred and ";
  else
   cout << digits[0] << " hundreds and ";

  if (digits[1] == 1)
   cout << digits[1] << " ten and ";
  else
   cout << digits[1] << " tens and ";

  cout << digits[2] << " ones.\n";
 }


 if (digits.size() == 2)
 {
  if (digits[0] == 1)
   cout << digits[0] << " ten and ";
  else
   cout << digits[0] << " tens and ";
  cout << digits[1] << " ones.\n";
 }

 if (digits.size() == 1)
 {
  cout << digits[0] << " ones.\n";
 }

}

void pause()
{
 cout << "\n\nPlease enter a letter: ";
 char key;
 cin >> key;
}