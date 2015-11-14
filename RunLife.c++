#include <iostream>
#include <cstring>
//#include <sstream>
#include "Life.h"
#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"

using namespace std;

int main() {
  string line;

  while (getline(cin, line)) {
    if (strcmp(line.c_str(), "Cell") == 0) {
      Life<Cell> l(cin);
      getline(cin, line);
      l.is_hetero = true;
      l.populate_grid();
    }
    
    else{
      if (strcmp(line.c_str(), "ConwayCell") == 0) {
        Life<ConwayCell> l(cin);
        getline(cin, line);
        l.is_hetero = false;
        l.populate_grid();
      }
      else if (strcmp(line.c_str(), "FredkinCell") == 0) {
        Life<ConwayCell> l(cin);
        getline(cin, line);
        l.is_hetero = false;
        l.populate_grid();
      }
    }
  
      //set up grid
      //run simulations
  }
  
  return 0;
}
