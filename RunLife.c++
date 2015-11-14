#include <iostream>
#include <cstring>
//#include <sstream>
#include "Life.h"
#include "Cell.h"

using namespace std;

int main() {
  string line;
  while (getline(cin, line)) {
    if (strcmp(line.c_str(), "Cell") == 0) {
      Life<Cell> l(cin);
      getline(cin, line);
      l.populate_heterogeneous_grid();
      //set up grid
      //run simulations
    }
    
    //else
    //do Conway and Fredkin
  }
  
  return 0;
}
