#pragma once

#include <vector>
#include <iostream>

using namespace std;

template<typename CellType>
class Life{
	
	vector<CellType> grid;

	Life(istream&);
};