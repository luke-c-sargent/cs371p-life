#pragma once

#include "AbstractCell.h"

class ConwayCell: AbstractCell{
	ConwayCell(bool living = false);
	void act();
};