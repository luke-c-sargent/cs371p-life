#pragma once

class AbstractCell {
	friend class Cell;
	virtual void act()=0;
  virtual void print_cell() = 0;

  public:
	  bool alive;
	  AbstractCell(){}
	  virtual ~AbstractCell(){}

	
};
