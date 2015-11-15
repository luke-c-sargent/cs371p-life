#pragma once

//#include "Life.h"

class AbstractCell {
	friend class Cell;
	bool alive;
	virtual void act()=0;
public:
	AbstractCell(){}
	virtual ~AbstractCell(){}

	
};
