#pragma once

#include "AbstractCell.h"

class ConwayCell: public AbstractCell{
  public:
  ConwayCell(bool living = false);
	void act();
  void print_cell();
};
