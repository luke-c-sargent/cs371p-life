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
  int x, y;

  while (getline(cin, line)) {
    if (strcmp(line.c_str(), "Cell") == 0) {
      cin >> x;
      cin >> y;
      Life<Cell> l(x, y);
      getline(cin, line);
      l.is_hetero = true;
      l.populate_grid();
    } 
    else{
      if (strcmp(line.c_str(), "ConwayCell") == 0) {
        cin >> x;
        cin >> y;
        Life<ConwayCell> l(x, y);
        getline(cin, line);
        l.is_hetero = false;
        l.populate_grid();
      }
      else if (strcmp(line.c_str(), "FredkinCell") == 0) {
        cin >> x;
        cin >> y;
        Life<ConwayCell> l(x, y);
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
