//#pragma once

#include <vector>
#include <iostream> 
#include <string>
#include "gtest/gtest_prod.h"

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

  void populate_grid() {
    populate_dead_cell_moat();
    if (is_hetero)
      populate_heterogeneous_grid();
    else
      populate_homogeneous_grid();
  }

  void populate_heterogeneous_grid(){
    string line;
    while (getline(cin, line) && !line.empty()) {
      cout << line << endl;
    }
  }
	
  void populate_homogeneous_grid(){
    string line;
    while (getline(cin, line) && !line.empty()) {
      cout << line << endl;
    }
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
  
  //FRIEND TESTS
	FRIEND_TEST(LifeFixture, Life_Constructor_1);
};
