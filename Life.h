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
  //constructor
	Life(istream& input_stream){
    input_stream >> x;
    input_stream >> y;
    input_stream >> evolutions;
    input_stream >> frequency;
  cout << x << " " << y << " " << evolutions << " " << frequency << endl;
  
  }

  //void populate_heterogeneous_grid(std::istream& input_stream);
  void populate_heterogeneous_grid(){
    string line;
    while (getline(cin, line) && !line.empty()) {
      cout << line << endl;
    }
  }
	//FRIEND TESTS
	FRIEND_TEST(LifeFixture, Life_Constructor_1);
};
