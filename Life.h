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
	int grid_rows,grid_cols,evolutions,frequency;
	vector<CellType> grid;
  
  public:
	bool is_hetero;

  //constructor
  Life(int rows, int cols) :
    grid(vector<CellType>(rows*cols))
  {
    grid_rows = rows;
    grid_cols = cols;
    cin >> evolutions;
    cin >> frequency;
  cout << grid_rows << " " << grid_cols << " " << evolutions << " " << frequency << endl;
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
    for (int i = 0; i < grid_rows; i++){
      getline(cin, line);
//      cout << line << endl;
      for (int j = 0; j < grid_cols; j++) {
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

  void populate_homogeneous_grid(){
    string line;
    for (int i = 0; i < grid_rows; i++){
      getline(cin, line);
      for (int j = 0; j < grid_cols; j++) {
        if (line[j] == '0')
          at(i,j).alive = true;
        else if (line[j] == '*')
          at(i,j).alive = true;
      }
    }
  }

  CellType& at(int rows, int cols) {
    int n = convert(rows, cols);
    return grid[n];
  }

  CellType& at(int n) {
    return grid[n];
  }

  int convert(int rows, int cols) {
    return rows*grid_cols+cols;
  }

  pair<int, int> convert(int i) {
    return make_pair((i/grid_cols), (i-(i/grid_cols)*grid_cols));
  }
 
  void print_grid() {
  cout << endl;
    for (int i = 0; i < grid_rows; i++){
      for (int j = 0; j < grid_cols; j++) {
        at(i,j).print_cell();
      }
      cout << endl;
    }
    cout << endl;
  }
  
  //FRIEND TESTS
	FRIEND_TEST(LifeFixture, Life_Constructor_1);
};
