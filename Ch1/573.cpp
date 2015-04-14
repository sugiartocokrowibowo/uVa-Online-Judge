/******************************************************************************

Author: Richard Mitchell
Description: 573 - The Snail  
Date Created: 4/1/15
Last Modified:

******************************************************************************/

#include <iostream>

using namespace std;


int main(int argc, char *argv[]) {

  double H, U, D, F;

  while (cin >> H) {
    if (H == 0) {
      continue;
    } else {
      cin >> U >> D >> F;

      double wellHeight = H;
      double movedUp = U;
      double movedDown = D;
      double fatigue = F/100;
      double currentHeight = 0;
      double energy = movedUp * fatigue;
      int day = 0;

      while (true) {
        day++;
        if (day > 1) {
          movedUp -= energy;
        }
        if (movedUp < 0) {
          movedUp = 0;
        }
        currentHeight += movedUp;
        if (currentHeight > wellHeight) {
          cout << "success on day " << day << endl;
          break;
        }
        currentHeight -= movedDown;
        if (currentHeight < 0) {
          cout << "failure on day " << day << endl;
          break;
        }
      }
    }
  }
  return 0;
}
