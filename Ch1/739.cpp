/******************************************************************************

Author: Richard Mitchell
Description: uVa Online Judge 739  
Date Created: 4/8/15 
Last Modified:

******************************************************************************/

#include <iostream>
#include <map>
#include <string>

using namespace std;


int main(int argc, char *argv[]) 
{
  map<char, string> sxCode;

  sxCode['B'] = "1";
  sxCode['P'] = "1";
  sxCode['F'] = "1";
  sxCode['V'] = "1";
  sxCode['C'] = "2";
  sxCode['S'] = "2";
  sxCode['K'] = "2";
  sxCode['G'] = "2";
  sxCode['J'] = "2";
  sxCode['Q'] = "2";
  sxCode['X'] = "2";
  sxCode['Z'] = "2";
  sxCode['D'] = "3";
  sxCode['T'] = "3";
  sxCode['L'] = "4";
  sxCode['M'] = "5";
  sxCode['N'] = "5";
  sxCode['R'] = "6";

  string end = "SOUNDEX CODE";
  string name;
  string sxStr = "";

  cout << "         NAME                     SOUNDEX CODE" << endl;

  while (cin >> name) {
    for (int i = 0; i < name.length(); ++i) {
      if (i == 0) { 
        sxStr.append(1, name[i]);
      } else if ((sxCode.count(name[i])) && (sxCode[name[i]] != sxCode[name[i - 1]])) {
        sxStr.append(sxCode[name[i]]);
      }
      if (sxStr.length() == 4) {
        break;
      }
    }

    while (sxStr.length() < 4) {
      sxStr.append(1, '0');
    }

    string spacing = "         ";
    cout << spacing;
    cout << name;

    int j = spacing.length() + name.length();
    // how much space between name, and the soundex code
    while (j < 34) {
      cout << " ";
      ++j;
    }

    cout << sxStr << endl;

    sxStr = "";
  }

  string ending = "                   END OF OUTPUT";

  cout << ending << endl;

  return 0;
}
