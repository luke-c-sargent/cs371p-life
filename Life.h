#pragma once

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
  Life(istream& input_stream){
    input_stream >> x;
    input_stream >> y;
    input_stream >> evolutions;
    input_stream >> frequency;
  cout << x << " " << y << " " << evolutions << " " << frequency << endl;
  
  }
  void populate_grid() {
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
  //FRIEND TESTS
	FRIEND_TEST(LifeFixture, Life_Constructor_1);
};
