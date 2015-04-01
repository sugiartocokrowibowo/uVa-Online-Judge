/******************************************************************************

Author: Richard Mitchell
Email: Richardt.mitchell@gmail.com  
Description:  uVa Online Judge 483 - Word Scrammble
Date Created: 3/30/2015
Last Modified:

******************************************************************************/

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;


int main(int argc, char *argv[]) {

  char  ch;
  stack<char> word;

  while (cin.get(ch)) {
    if (!isspace(ch)) {
      word.push(ch);
    } else {
      while (!word.empty()) {
        cout << word.top(); 
        word.pop();
      }
      cout << ch;
    }
  }

  return 0;
}
