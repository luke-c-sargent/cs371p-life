//#pragma once

#include "AbstractCell.h"

class Cell{
	friend class FredkinCell;
	friend class ConwayCell;
//  friend class Life;
  

	void act();
public:	
	AbstractCell* abstractcell_ptr;
	Cell(AbstractCell* = nullptr);
//	Cell(){}//;
  ~Cell();

	//friendship
	
};
