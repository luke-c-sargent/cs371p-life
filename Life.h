
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

/** 
  Locale is used to save the number of live neighbors for the cells
*/
struct Locale{
    int n,ne,e,se,s,sw,w,nw;
    Locale():n(0),ne(0),e(0),se(0),s(0),sw(0),w(0),nw(0){}
};
#endif

/**
  Forward declaration of Life class
*/
template <typename CellType>
class Life;

/**
  Life_Iterator for class life. Iterates through Life's grid.
*/
template <typename CellType>
class Life_Iterator : public iterator<input_iterator_tag, int> {   
    int _p; // position
    Life<CellType>* d;
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

/**
  AbstractCell is the abstract parent class of ConwayCell and FredkinCell.
*/
class AbstractCell {
	friend class Cell;
    
  public:
  int living_neighbors;
	bool alive;
  
  /**
    Constructor
  */
	AbstractCell(){}
  /**
    Destructor
  */
	virtual ~AbstractCell(){}
  /**
    act() is overridden by FredkinCell and ConwayCell.
  */
  virtual int act()=0;

  /**
    print_cell() is overridden by FredkinCell and ConwayCell.
  */
	virtual void print_cell() = 0;
  /**
    living() is overridden by FredkinCell and ConwayCell.
  */
  virtual void living(Locale l) = 0;
  /**
    heterogeneous_grid_act() is overridden by FredkinCell and ConwayCell.
  */
  virtual bool heterogeneous_grid_act() = 0;
};

/**
  FredkinCell is a child class of AbstractCell.
*/
class FredkinCell: public AbstractCell{ 
  public:

    int age;
  	FredkinCell(bool living = false);
	  
    /** 
      act() changes the state of the FredkinCell - changes it to alive or dead,
      or increases its age
    */
    int act();
    /** 
      prints the value of a single cell
    */
    void print_cell();
    /** 
      counts the number of living neighbors
    */
    void living(Locale);
    /** 
      determines whether the FredkinCell should become a ConwayCell
    */
    bool heterogeneous_grid_act();

    FredkinCell* operator->();
};
/*
  ConwayCell is a child class of AbstractCell.
*/
class ConwayCell: public AbstractCell{
  public:
  ConwayCell(bool living = false);
   /** 
      act() changes the state of the ConwayCell - changes it to alive or dead,
      or stays the same.
    */
  int act();
  /** 
      counts the number of living neighbors
  */
  void living(Locale);
  /** 
      prints the value of a single cell
  */
  void print_cell();
  /** 
    calls act
  */
  bool heterogeneous_grid_act();
  ConwayCell* operator ->();
};

/* 
  Cell is a handle class, used when the Life grid has a hetergeneous
  mix of FredkinCell and ConwayCells.
*/
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

/* 
  Life class - a template class
  Life can be of type Cell, FredkinCell, or ConwayCell.
*/
template<typename CellType>
class Life{
  public:
	int grid_rows,grid_cols,evolutions,frequency,generation,population;
	vector<CellType> grid;
    istream& input_stream;
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
    evolutions=stoi(line);
    getline(input_stream, line);
    frequency=stoi(line);
   
    generation = 0;
    population = 0;
  }
  
  /**
    Used to set up the initial state of a Cell grid
  */
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

  /** 
    Used to set up the initial state of a FredkinCell or ConwayCell grid
  */
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

  /**
    input parameters rows,cols
  */
  CellType& at(int rows, int cols) {
    int n = convert(rows, cols);
    return grid[n];
  }

  /**
    single input parameter at()
  */
  CellType& at(int n) {
    return grid[n];
  }

  /** 
    for use with the iterator
  */
  Life_Iterator<CellType> begin() { 
	  return Life_Iterator<CellType>(0,this); 
  }

  /** 
    for use with the iterator
  */
  Life_Iterator<CellType> end(){ 
	  return Life_Iterator<CellType>(grid.size()*grid[0].size(),this); 
  } 

  int convert(int rows, int cols) {
    return rows*grid_cols+cols;
  }

  pair<int, int> convert(int i) {
    return make_pair((i/grid_cols), (i-(i/grid_cols)*grid_cols));
  }
 
  /** 
    prints the entire grid
  */
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
  
  /** 
    executions frequency number of evolutions
  */
  void step(){
    for (int i = 0; i < frequency; ++i){
      set_living();
      process_cells();
      ++generation;
      }
  }
  /** 
    counts the number of living neighbors
  */
  void set_living(){
    int cols, rows;
    cols=rows=0;
    if(DEBUG){cout<<"SET LIVING:"<<endl;}
    for(int i=0; i < grid.size(); ++i){//going through the cells,
            pair<int,int> pair = convert(i);
            rows = pair.first;
            cols = pair.second;
            if(DEBUG){cout<<"--["<<rows<<", "<<cols<<"]";}
            Locale l; //get local info
            if (rows > 0) {
                l.n=at(rows-1,cols)->alive;
                if (cols > 0)
                  l.nw = at(rows-1,cols-1)->alive;
                if(cols < grid_cols-1)// if its not a eastmost cell
                    l.ne=at(rows-1, cols+1)->alive;
            }
            if (rows < grid_rows-1){
              l.s = at(rows+1, cols)->alive;
              if (cols > 0)
                l.sw = at(rows+1, cols-1)->alive;
              if (cols < grid_cols-1)
                l.se = at(rows+1, cols+1)->alive;
            }
            if (cols > 0)
              l.w = at(rows, cols-1)->alive;
            if (cols < grid_cols-1)
              l.e = at(rows, cols+1)->alive;
            at(i)->living(l);
      }
  }
  
  void process_cells(){
    for(int i=0; i < grid.size(); ++i){//going through the cells,
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


