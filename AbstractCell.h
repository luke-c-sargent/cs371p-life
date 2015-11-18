#pragma once
#define DEBUG true
class AbstractCell {
	friend class Cell;
    
	virtual void act()=0;
  	

  public:
  	int living_neighbors;
	bool alive;
	AbstractCell(){}
	virtual ~AbstractCell(){}
	virtual void print_cell() = 0;
};