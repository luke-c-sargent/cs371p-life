#include <iostream>
#include <cstring>
#include "Life.h"

using namespace std;

int main() {
  string line;
  int rows, cols;
  while (getline(cin, line)) {
    if (strcmp(line.c_str(), "Cell") == 0) {
      cin >> rows >> cols;
      cout << "*** Life<Cell> ";
      Life<Cell> l(rows, cols);
      getline(cin, line);
      l.populate_heterogeneous_grid();
      l.evolve(); //run simulations
    } 
    else{
      if (strcmp(line.c_str(), "ConwayCell") == 0) {
        cin >> rows >> cols;
        cout << "*** Life<ConwayCell> ";
        Life<ConwayCell> l(rows, cols);
        getline(cin, line);
        l.populate_homogeneous_grid();
        l.evolve(); //run simulations
      }
      else if (strcmp(line.c_str(), "FredkinCell") == 0) {
        cin >> rows >> cols;
        cout << "*** Life<FredkinCell> ";
        Life<FredkinCell> l(rows, cols);
        getline(cin, line);
        l.populate_homogeneous_grid();
        l.evolve(); //run simulations
      } 
    } 
  }
  return 0;
}
