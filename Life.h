#pragma once

#include <vector>
#include <iostream> 
#include <string>
#include "gtest/gtest_prod.h"

using namespace std;

template<typename CellType>
class Life{
	int x,y,evolutions,frequency;
	vector<CellType> grid;
	Life<CellType>(istream&);

	//FRIEND TESTS
	FRIEND_TEST(LifeFixture, Life_Constructor_1);
};