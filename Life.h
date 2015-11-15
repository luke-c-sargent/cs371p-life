//#pragma once

#include <vector>
#include <iostream> 
#include <string>
#include "gtest/gtest_prod.h"
#include "Cell.h"
#include "FredkinCell.h"
#include "ConwayCell.h"

using namespace std;

template<typename CellType>
class Life{
	int x,y,evolutions,frequency;
	vector<CellType> grid;
  
  public:
	bool is_hetero;

  //constructor
  Life(int _x, int _y) :
    grid(vector<CellType>(_x*_y))
  {
    x = _x;
    y = _y;
    cin >> evolutions;
    cin >> frequency;
  cout << x << " " << y << " " << evolutions << " " << frequency << endl;
  }

/*
  void populate_grid() {
    if (is_hetero)
      populate_heterogeneous_grid();
    else
      populate_homogeneous_grid();
  }
*/

  void populate_heterogeneous_grid(){
    string line;
//    while (getline(cin, line) && !line.empty()) {
    for (int i = 0; i < x; i++){
      getline(cin, line);
      cout << line << endl;
      for (int j = 0; j < y; j++) {
        Cell cell = at(i, j);
        char ch = line[j];
        switch (ch) {
          case ('.'):
            cell.abstractcell_ptr = new ConwayCell(false);
            break;
          case('*'):
            cell.abstractcell_ptr = new ConwayCell(true);
            break;
          case('-'):
            cell.abstractcell_ptr = new FredkinCell(false);
            break;
          case('0'):
            cell.abstractcell_ptr = new FredkinCell(true);
            break;
        }
      }
    }
  }
	
  void populate_conway_grid(){
    string line;
    for (int i = 0; i < x; i++){
      getline(cin, line);
      cout << line << endl;
      for (int j = 0; j < y; j++) {
        ConwayCell cell = at(i, j);
        if (line[j] == '*')
          cell.alive = true;
      }
    }
  }

  void populate_fredkin_grid(){
    string line;
    for (int i = 0; i < x; i++){
      getline(cin, line);
      //cout << "reference" << endl;
      //cout << line << endl;
      for (int j = 0; j < y; j++) {
        //FredkinCell cell = at(i,j);
        if (line[j] == '0')
          at(i,j).alive = true;
        //cell.print_cell();
        //cout << line[j];
      }
    }
    //print_grid();
  }

  CellType& at(int _x, int _y) {
    int n = convert(_x, y, _y);
    return grid[n];
  }

  CellType& at(int n) {
    return grid[n];
  }

  int convert(int x, int y1, int y2) {
    return x*y1+y2;
  }

  pair<int, int> convert(int i) {
    return make_pair((i/y), (i-(i/y)*y));
  }
 
  void print_grid() {
  cout << endl;
    for (int i = 0; i < x; i++){
      for (int j = 0; j < y; j++) {
        at(i,j).print_cell();
      }
      cout << endl;
    }
    cout << endl;
  }
  
  //FRIEND TESTS
	FRIEND_TEST(LifeFixture, Life_Constructor_1);
};
