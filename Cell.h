//#pragma once

#include "AbstractCell.h"

class Cell{
	friend class FredkinCell;
	friend class ConwayCell;

	AbstractCell* abstractcell_ptr;

	void act();
public:	
	Cell(AbstractCell* = nullptr);
//	Cell(){}//;
  ~Cell();

	//friendship
	
};
