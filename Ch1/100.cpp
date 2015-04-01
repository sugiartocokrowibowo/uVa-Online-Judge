/******************************************************************************

Author: Richard Mitchell
Email: Richardt.mitchell@gmail.com  
Description:  uVa Online Judge 100 - The 3n + 1 problem
Date Created: 3/15/2015
Last Modified:

******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int cycleLength(int n) {
  int count = 1;
  while (n != 1) {
    if (n % 2 != 0) {
      n = 3*n + 1;
    } else {
      n = n/2;
    }
    count++;
  }
  return count;
}



int main(int argc, char *argv[]) {
  int aOriginal, bOriginal;
  int a, b;
  int max, temp;

  while (cin >> aOriginal >> bOriginal) {
    
    a = aOriginal;
    b = bOriginal;

    if (a > b) {
      temp = a;
      a = b;
      b = temp;
    }

    max = cycleLength(a);

    for (int i = a + 1; i <= b; ++i) {
      temp = cycleLength(i);
      if (temp > max) {
        max = temp;
      }
    }

    cout << aOriginal << " " << bOriginal << " " << max << endl;
  }

  return 0;
}
