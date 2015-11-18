#pragma once
#define DEBUG true

#ifndef LOCALE
#define LOCALE
struct Locale{
  int n,ne,e,se,s,sw,w,nw;
  Locale():n(0),ne(0),e(0),s(0),sw(0),w(0),nw(0){}};
#endif


class AbstractCell {
	friend class Cell;
    
  	

  public:
	virtual void act()=0;
  	int living_neighbors;
	bool alive;
	AbstractCell(){}
	virtual ~AbstractCell(){}
	virtual void print_cell() = 0;
//  virtual void living(Locale l) = 0;
  virtual void living(Locale l) = 0;
  virtual void heterogeneous_grid_act() = 0;
};
