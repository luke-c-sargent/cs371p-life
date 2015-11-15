#pragma once

#include "AbstractCell.h"

class FredkinCell: public AbstractCell{
  int age;
  public:
	FredkinCell(bool living = false){}
	void act(){}
};
