#pragma once
#include <iostream>
using namespace std;
class AbstractCell {
	friend class Cell;
	virtual void act()=0;

  public:
	  bool alive;
	  AbstractCell(){}
	  virtual ~AbstractCell(){}

    virtual void print_cell()=0;
	
};
