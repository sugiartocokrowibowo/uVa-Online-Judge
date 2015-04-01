/******************************************************************************

Author: Richard Mitchell
Email: Richardt.mitchell@gmail.com  
Description:  uVa Online Judge 272 - TEX Quotes
Date Created: 3/2/2015
Last Modified:

******************************************************************************/

#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
  char ch;
  bool endQuote = false;

  while (cin.get(ch)) {
    if (ch == '"') {
      if (endQuote) {
        cout << "''";
      } else {
        cout << "``";
      }
      endQuote = !endQuote;
    } else {
      cout << ch;
    }
  }

  return 0;
}
