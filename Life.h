//#pragma once

#include <vector>
#include <iostream> 
#include <string>
#include "gtest/gtest_prod.h"

#include "Cell.h"
#include "FredkinCell.h"
#include "ConwayCell.h"

#define DEBUG true

using namespace std;

#ifndef LOCALE
#define LOCALE
struct Locale{
    int n,ne,e,se,s,sw,w,nw;
    Locale():n(0),ne(0),e(0),se(0),s(0),sw(0),w(0),nw(0){}
};
#endif
template<typename CellType>
class Life{
	int grid_rows,grid_cols,evolutions,frequency,generation,population;
	vector<CellType> grid;
    istream& input_stream;
  public:
	bool is_hetero;

  //constructor
  Life(int rows, int cols, istream& is=cin) :
    //grid(vector<CellType>(rows*cols)),
    input_stream(is)
  {
    grid.reserve(rows*cols);
    grid_rows = rows;
    grid_cols = cols;
    input_stream >> evolutions;
    input_stream >> frequency;
<<<<<<< HEAD
    generation = 0;
    population = 0;
=======
    if(DEBUG)
        cout << grid_rows << " " << grid_cols << " " << evolutions << " " << frequency << endl;
>>>>>>> 6e47f4f8a602ac5d6c95b2e7fffc8c8013cd0811
  }

  void populate_heterogeneous_grid(){
    string line;
    for (int i = 0; i < grid_rows; i++){
      getline(input_stream, line);
      if(DEBUG){cout<<"line gotten from hetero grid:\n   "<<line<<endl;}
      for (int j = 0; j < grid_cols; j++) {
        char ch = line[j];
        switch (ch) {
          case ('.'):
            at(i,j).abstractcell_ptr = new ConwayCell(false);
            break;
          case('*'):
            at(i,j).abstractcell_ptr = new ConwayCell(true);
            ++population;
            break;
          case('-'):
            at(i,j).abstractcell_ptr = new FredkinCell(false);
            break;
          case('0'):
            at(i,j).abstractcell_ptr = new FredkinCell(true);
            ++population;
            break;
        }
      }
    }
  }

  void populate_homogeneous_grid(){
    string line;
    for (int i = 0; i < grid_rows; i++){
      getline(input_stream, line);
      if(DEBUG){cout<<"line gotten from homogenous grid:\n   "<<line<<endl;}
      for (int j = 0; j < grid_cols; j++) {
        if (line[j] == '0' || line[j] == '*'){
          at(i,j).alive = true;
<<<<<<< HEAD
          ++population;
=======
>>>>>>> 6e47f4f8a602ac5d6c95b2e7fffc8c8013cd0811
        }
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
    cout << "Generation = " << generation << ", Population = " << population << "." << endl;
    for (int i = 0; i < grid_rows; i++){
      for (int j = 0; j < grid_cols; j++) {
        at(i,j)->print_cell();
      }
      cout << endl;
    }
    cout << endl;
  }
  
  void step(){ //int steps=1){
    for (int i = 0; i < frequency; ++i){
      set_living();
      process_cells();
      ++generation;
      }
  }

  void set_living(){
    int cols, rows;
    cols=rows=0;
    if(DEBUG){cout<<"SET LIVING:"<<endl;}
    for(int i=0; i < grid.size(); ++i){//going through the cells,
        //if(at(i)->alive){
        
            //_x=grid.size()%grid_cols; // get coords
            //_y=grid.size()/grid_cols;
            pair<int,int> pair = convert(i);
            rows = pair.first;
            cols = pair.second;
            if(DEBUG){cout<<"--["<<rows<<", "<<cols<<"]";}
            Locale l; //get local info
 //         
            if (rows > 0) {
                l.n=at(rows-1,cols)->alive;
                if(DEBUG){cout<<"n:"<<l.n<<"-";}

                if (cols > 0){
                  l.nw = at(rows-1,cols-1)->alive;
                  if(DEBUG){cout<<"nw:"<<l.nw<<"-";}
                }
                if(cols < grid_cols-1){// if its not a eastmost cell
                    l.ne=at(rows-1, cols+1)->alive;
                    if(DEBUG){cout<<"ne:"<<l.ne<<"-";}
                }
            }
            
            if (rows < grid_rows-1){
              l.s = at(rows+1, cols)->alive;
              if(DEBUG){cout<<"s:"<<l.s<<"-";}
              if (cols > 0){
                l.sw = at(rows+1, cols-1)->alive;
                if(DEBUG){cout<<"sw:"<<l.sw<<"-";}
                
              }

              if (cols < grid_cols-1){
                l.se = at(rows+1, cols+1)->alive;
                if(DEBUG){cout<<"se:"<<l.se<<"-";}
                }
            }
/*            
            if(_x)
                l.w=at(i-1)->alive;// west = one back
            if(_x < grid_cols)
                l.e=at(i+1)->alive; // east = one forward
            at(i)->living(l);
            _x=_y=0;// reset values
*/
            if (cols > 0){
              l.w = at(rows, cols-1)->alive;
              if(DEBUG){cout<<"w:"<<l.w<<"-";}
              }
            if (cols < grid_cols-1){
              l.e = at(rows, cols+1)->alive;
              if(DEBUG){cout<<"e:"<<l.e<<"\n";}
              }
            at(i)->living(l);
//            rows=cols=0;
//}
      }
  }
  
  void process_cells(){
    for(int i=0; i < grid.size(); ++i){//going through the cells,
        //at(i)->act();
        at(i).act();
    }
  }

  void evolve() {
    while (generation < evolutions) {
      step();
      print_grid();
    }  
  }

  //FRIEND TESTS
	FRIEND_TEST(LifeFixture, Life_Constructor_1);
};
