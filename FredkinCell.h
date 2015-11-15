#pragma once

#include "AbstractCell.h"

class FredkinCell: AbstractCell{
  int age;
  public:
	FredkinCell(bool living = false);//{}
	void act();
};
