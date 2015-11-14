#pragma once

#include "AbstractCell.h"

class FredkinCell: AbstractCell{
	int age;

	FredkinCell(bool living = false);
	void act();
};
