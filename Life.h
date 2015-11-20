
//#pragma once

#include <vector>
#include <iostream> 
#include <string>
#include "gtest/gtest_prod.h"

#ifndef DEBUG
#define DEBUG false
#endif

using namespace std;

#ifndef LOCALE
#define LOCALE
struct Locale{
    int n,ne,e,se,s,sw,w,nw;
    Locale():n(0),ne(0),e(0),se(0),s(0),sw(0),w(0),nw(0){}
};
#endif
//template <typename CellType>
//class Life_Iterator<CellType>;

template <typename CellType>
class Life;

//class Life_Iterator;
template <typename CellType>
class Life_Iterator : public iterator<input_iterator_tag, int> {   
    int _p; // position
    Life<CellType>* d;
    //Life* d;
public:
    Life_Iterator(int v, Life<CellType>* li) :
                _p (v), d(li)
            {}
    bool operator == (const Life_Iterator& rhs) const {
            return (_p == rhs._p);}
 
    bool operator != (const Life_Iterator& rhs) const {
        return !(*this == rhs);}
 
    const CellType& operator * () const {
        int width = d->grid[0].size();
        cout << width << endl;
        return *(d->grid[_p/width][_p%width]);}

    Life_Iterator& operator ++ () {
        ++_p;
        return *this;}
 
    Life_Iterator operator ++ (int) {
        Life_Iterator x = *this;
        ++*this;
        return x;}
};

class AbstractCell {
	friend class Cell;
    
  public:
	virtual int act()=0;
  int living_neighbors;
	bool alive;
	AbstractCell(){}
	virtual ~AbstractCell(){}
	virtual void print_cell() = 0;
  virtual void living(Locale l) = 0;
  virtual bool heterogeneous_grid_act() = 0;
};

class FredkinCell: public AbstractCell{ 
  public:
  int age;
	FredkinCell(bool living = false);
	int act();
    void print_cell();
    void living(Locale);
    bool heterogeneous_grid_act();
    FredkinCell* operator->();
};

class ConwayCell: public AbstractCell{
  public:
  ConwayCell(bool living = false);
  int act();
  void living(Locale);
  void print_cell();
  bool heterogeneous_grid_act();
  ConwayCell* operator ->();
};

class Cell{
	friend class FredkinCell;
	friend class ConwayCell;

public:	
    void living(Locale);
	AbstractCell* abstractcell_ptr;
	Cell(AbstractCell* = nullptr);
    ~Cell();
    int act();
    AbstractCell* operator -> ();
};

template<typename CellType>
class Life{
	int grid_rows,grid_cols,evolutions,frequency,generation,population;
	vector<CellType> grid;
    istream& input_stream;
  public:
	bool is_hetero;

  //constructor
  Life(int rows, int cols, istream& is=cin) :
    grid(vector<CellType>(rows*cols)),
    input_stream(is)
  {
    grid_rows = rows;
    grid_cols = cols;
    string line;
    
    getline(input_stream, line);
    if(DEBUG){cout << "evos:"<<line<<endl;}
    evolutions=stoi(line);
    getline(input_stream, line);
    if(DEBUG){cout << "freqs:"<<line<<endl;}
    frequency=stoi(line);
    
    cout << rows << "x" << cols << " ***" << endl << endl; 
    //getline(input_stream, line);
    //if(DEBUG){cout << "next:"<<line<<endl;}
    //exit(0);
    
    generation = 0;
    population = 0;
    if(DEBUG){cout<<"L():E:"<<evolutions<<" F:"<<frequency<<endl;}
  }

  void populate_heterogeneous_grid(){
    string line;
    for (int i = 0; i < grid_rows; i++){
      getline(input_stream, line);
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
    //getline(input_stream,line);
    for (int i = 0; i < grid_rows; i++){
      getline(input_stream, line);
      if(DEBUG){cout<<"L-Hom:"<<line<<endl;}
      for (int j = 0; j < grid_cols; j++) {
        if (line[j] == '0' || line[j] == '*'){
          at(i,j).alive = true;
          ++population;
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

Life_Iterator<CellType> begin(){ 
	return Life_Iterator<CellType>(0,this); } 
Life_Iterator<CellType> end(){ 
	return Life_Iterator<CellType>(grid.size()*grid[0].size(),this); } 

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
//              l.n=at(i-grid_cols)->alive; //north = one row up
//                if(_x) // if x is not 0, can go backwards
//                  l.nw=at(i-grid_cols-1)->alive;
                if (cols > 0)
                  l.nw = at(rows-1,cols-1)->alive;
//                else if( _x < ( grid_cols -1) )// if its not a eastmost cell
                if(cols < grid_cols-1)// if its not a eastmost cell
//                    l.ne=at(i-grid_cols+1)->alive;
                    l.ne=at(rows-1, cols+1)->alive;
            }
//            if(_y != grid_rows - 1){ // if its not a bottom row, can check southern values
            if (rows < grid_rows-1){
//                l.s=at(i+grid_cols)->alive; // south = one row down
              l.s = at(rows+1, cols)->alive;
//                if(_x)
            
//                    l.sw=at(i+grid_cols-1)->alive;
              if (cols > 0)
                l.sw = at(rows+1, cols-1)->alive;

//                else if( _x < ( grid_cols -1) )
//                    l.se=at(i+1+grid_cols)->alive;
              if (cols < grid_cols-1)
                l.se = at(rows+1, cols+1)->alive;
            }
/*            
            if(_x)
                l.w=at(i-1)->alive;// west = one back
            if(_x < grid_cols)
                l.e=at(i+1)->alive; // east = one forward
            at(i)->living(l);
            _x=_y=0;// reset values
*/
            if (cols > 0)
              l.w = at(rows, cols-1)->alive;
            if (cols < grid_cols-1)
              l.e = at(rows, cols+1)->alive;
            at(i)->living(l);
//            rows=cols=0;
//}
      }
  }
  
  void process_cells(){
    for(int i=0; i < grid.size(); ++i){//going through the cells,
        //at(i)->act();
        int delta = at(i).act();
        population += delta;
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


