#pragma once

#include "Life.h"
#include "FredkinCell"

class AbstractCell {
	//Cell cell; cell type?
	Life* life_ptr;

	bool alive;

	AbstractCell():life_ptr(nullptr),alive(false){}
	~AbstractCell(){}

	virtual void act()=0;
};