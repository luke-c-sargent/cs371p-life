#include <iostream>
#include <cstring>
#include "Life.h"

using namespace std;

int main() {
  string line;
  int rows, cols;
  while (getline(cin, line)) {
//    cout << "line:" << line << endl;
    if (strcmp(line.c_str(), "Cell") == 0) {
      cin >> rows;
      cin >> cols;
      Life<Cell> l(rows, cols);
      getline(cin, line);
      l.is_hetero = true;
      l.populate_heterogeneous_grid();
      l.print_grid();
      l.run_simulations();
      //run simulations
    } 
    else{
      if (strcmp(line.c_str(), "ConwayCell") == 0) {

        cin >> rows; 
        cin >> cols;
        Life<ConwayCell> l(rows, cols);
        getline(cin, line);
        l.is_hetero = false;
        l.populate_homogeneous_grid();
        l.print_grid();
        l.run_simulations();
        //run simulations

      }
      else if (strcmp(line.c_str(), "FredkinCell") == 0) {
        cin >> rows >> cols;
        Life<FredkinCell> l(rows, cols);
        getline(cin, line);
        l.is_hetero = false;
        l.populate_homogeneous_grid();
        l.print_grid();
        l.run_simulations();
        //run simulations
      } 
    } 
  }
  return 0;
}
