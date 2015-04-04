/******************************************************************************

Author: Richard Mitchell
Email: Richardt.mitchell@gmail.com  
Description: 661 - Blowing Fuses 
Date Created: 4/3/15
Last Modified:

******************************************************************************/

#include <iostream>
#include <map>

using namespace std;

struct Device {
    int amps;
    bool powerOn;
};
    
int main(int argc, char *argv[]) {

  int n, m, c;
  map<int, Device*> hTable;
  int sequenceNumber = 1;

  while (cin >> n >> m >> c) {

    if ((c == 0) && (n == m) && (n == c)) { 
      continue;
    } else {
      for (int i = 1; i <= n; ++i) { 
        Device* d = new Device;
        cin >> d->amps;
        d->powerOn = false;
        hTable[i] = d;
      }

      int totalAmps = 0;
      int maxAmps = 0;
      bool blownFuse = false;
      for (int j = 0; j < m; ++j) {
        int deviceNumber;
        cin >> deviceNumber;
        hTable[deviceNumber]->powerOn = !hTable[deviceNumber]->powerOn;
        if (hTable[deviceNumber]->powerOn) {
          totalAmps += hTable[deviceNumber]->amps;
          if (totalAmps > maxAmps) {
            maxAmps = totalAmps;
          }
          if (totalAmps > c) {
            blownFuse = true;
          }
        } else if (!hTable[deviceNumber]->powerOn) {
            totalAmps -= hTable[deviceNumber]->amps;
          }
        }

        for (int k = 1; k <= n; ++k) {
          delete hTable[k];
        }

        if (blownFuse) {
          cout << "Sequence " << sequenceNumber << endl;
          cout << "Fuse was blown." << endl;
        } else {
          cout << "Sequence " << sequenceNumber << endl;
          cout << "Fuse was not blown." << endl;
          cout << "Maximal powerOn consumption was " << maxAmps << " amperes.\n";
        }
      }
    cout << endl;
    sequenceNumber++;
  }
  return 0;
}
