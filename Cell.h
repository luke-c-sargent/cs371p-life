//#pragma once
#include "AbstractCell.h"

class Cell{
	friend class FredkinCell;
	friend class ConwayCell;

	void act();
public:	
	AbstractCell* abstractcell_ptr;
	Cell(AbstractCell* = nullptr);
  ~Cell();
  
  AbstractCell* operator -> ();

  /*
  void print_cell(){
    abstractcell_ptr->print_cell();
  }*/
};

