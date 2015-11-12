#pragma once

#include <vector>
#include <iostream>
#include <string>

using namespace std;

template<typename CellType>
class Life{
	int rows,columns,evolutions,frequency;
	vector<CellType> grid;
	Life(istream&);
};