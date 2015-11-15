//#pragma once
#include <iostream>
#include "AbstractCell.h"

using namespace std;
class FredkinCell: public AbstractCell{
  int age;
  public:
	FredkinCell(bool living = false):
    age(0) {alive = living;}
	void act(){}
  void print_cell(){
    if (alive)
      cout << age;
    else
      cout << '-';
  }
};
