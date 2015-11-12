#pragma once

#include "AbstractCell.h"

template 
class Cell{
	AbstractCell* abstractcell_ptr;

	void act();
	//default cell is fredkin
	Cell(AbstractCell*);
	~Cell();

};