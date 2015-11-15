#include <iostream>
#include <cstring>
#include "Life.h"

using namespace std;

int main() {
  string line;
  int x, y;
  while (getline(cin, line)) {
    if (strcmp(line.c_str(), "Cell") == 0) {
      cin >> x >> y;
      Life<Cell> l(x, y);
      getline(cin, line);
      l.is_hetero = true;
      l.populate_heterogeneous_grid();
      //run simulations
    } 
    else{
      if (strcmp(line.c_str(), "ConwayCell") == 0) {
        cin >> x >> y;
        Life<ConwayCell> l(x, y);
        getline(cin, line);
        l.is_hetero = false;
        l.populate_homogeneous_grid();
        l.print_grid();
        //run simulations
      }
      else if (strcmp(line.c_str(), "FredkinCell") == 0) {
        cin >> x >> y;
        Life<FredkinCell> l(x, y);
        getline(cin, line);
        l.is_hetero = false;
        l.populate_homogeneous_grid();
        l.print_grid();
        //run simulations
      }
    }
  }
  return 0;
}
