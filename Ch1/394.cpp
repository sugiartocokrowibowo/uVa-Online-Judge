/******************************************************************************

Author: Richard Mitchell
Email: Richardt.mitchell@gmail.com  
Description:  uVa Online Judge 394 - MapMaker
Date Created: 3/23/2015
Last Modified:

******************************************************************************/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Array { 
  public:
    string name;
    int address;
    int size;
    int dimensions;
    vector<int> lower;
    vector<int> upper;
    vector<int> constants;
};


int main(int argc, char* argv[]) {

  int N, R;
  
  cin >> N; 
  cin >> R;          

  Array *a = new Array[N];


  for (int i = 0; i < N; ++i) {
    cin >>  a[i].name;
    cin >>  a[i].address;
    cin >>  a[i].size;
    cin >>  a[i].dimensions;
    a[i].lower.push_back(0);
    a[i].upper.push_back(0);
    for (int j = 1; j <= a[i].dimensions; ++j) { 
      int lowerBound;
      int upperBound;
      cin >> lowerBound; 
      cin >> upperBound; 
      a[i].lower.push_back(lowerBound);
      a[i].upper.push_back(upperBound);
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= a[i].dimensions; ++j) {
      if (j == a[i].dimensions) {
        a[i].constants.push_back(a[i].size);
      } else {  
        a[i].constants.push_back(0);
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    int constant = a[i].dimensions - 1;
    a[i].constants[0] = a[i].address - (a[i].constants[a[i].dimensions] * a[i].lower[a[i].dimensions]);
    for (int j = constant; j > 0; --j) {
      a[i].constants[j] = (a[i].constants[j + 1]) * (a[i].upper[j + 1] - a[i].lower[j + 1] + 1);
      a[i].constants[0] = a[i].constants[0] - (a[i].constants[j] * a[i].lower[j]); 
    }
  }

  for (int i = 0; i < R; ++i) { 
    string theName;
    cin >> theName;
    for (int j = 0; j < N; ++j) {
      int theAddress = 0;
      int theIndex;
      if (theName == a[j].name) {
         cout << theName << '[';
        for (int k = 1; k <= a[j].dimensions; ++k) {  
          cin >> theIndex;  
          cout << theIndex;
          if (k + 1 <= a[j].dimensions) { 
            cout << ", ";
          }
          theAddress += a[j].constants[k] * theIndex;
        }
        theAddress += a[j].constants[0];
        cout << "] = " << theAddress << endl;
      }
    }
  }
  
  delete [] a; 
  return 0;
}
