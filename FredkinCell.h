#pragma once

#include "AbstractCell.h"

class FredkinCell: AbstractCell{
	int age;

	FredkinCell(bool);
	int act();
};