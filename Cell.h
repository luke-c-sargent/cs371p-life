#pragma once

#include "AbstractCell.h"

class Cell{
	AbstractCell* abstractcell_ptr;

	void act();
	Cell(AbstractCell*);
	~Cell();

};