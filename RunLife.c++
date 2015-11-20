#include <iostream>
#include <cstring>
#include "Life.h"

using namespace std;

int main() {
  string line;
  int rows, cols;
  while (getline(cin, line)) {
    if (strcmp(line.c_str(), "Cell") == 0) {
      cout << "*** Life<Cell> ";
      getline(cin, line);
      if(DEBUG){cout<<"rline:"<<line<<endl;}
      rows=stoi(line);
      getline(cin, line);
      if(DEBUG){cout<<"cline:"<<line<<endl;}
      cols=stoi(line);
      if(DEBUG){cout<<"r:"<<rows<<" c:"<<cols<<endl;}
      Life<Cell> l(rows, cols);
      l.is_hetero = true;
      l.populate_heterogeneous_grid();
      getline(cin, line);
      l.print_grid();
      l.evolve(); //run simulations
    } 
    else{
      if (strcmp(line.c_str(), "ConwayCell") == 0) {
        cout << "*** Life<ConwayCell> ";
        getline(cin, line);
        if(DEBUG){cout<<"rline:"<<line<<endl;}
        rows=stoi(line);
        getline(cin, line);
        if(DEBUG){cout<<"cline:"<<line<<endl;}
        cols=stoi(line);
        
        if(DEBUG){cout<<"r:"<<rows<<" c:"<<cols<<endl;}
        
        Life<ConwayCell> l(rows, cols);
        
        l.is_hetero = false;
        l.populate_homogeneous_grid();
        getline(cin, line);
        l.print_grid();
        l.evolve(); //run simulations
      }
      else if (strcmp(line.c_str(), "FredkinCell") == 0) {
        cout << "*** Life<FredkinCell> ";
        getline(cin, line);
        if(DEBUG){cout<<"rline:"<<line<<endl;}
        rows=stoi(line);
        getline(cin, line);
        if(DEBUG){cout<<"cline:"<<line<<endl;}
        cols=stoi(line);
        
        Life<FredkinCell> l(rows, cols);
        
        l.is_hetero = false;
        l.populate_homogeneous_grid();
        getline(cin, line);
        l.print_grid();
        l.evolve(); //run simulations
      } 
    } 
  }
  return 0;
}
