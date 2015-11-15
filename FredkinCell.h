#pragma once

#include "AbstractCell.h"

using namespace std;
class FredkinCell: public AbstractCell{
  int age;
  public:
	FredkinCell(bool living = false){age=0;}
	void act(){}
  void print_cell(){
    if (alive)
      cout << age;
    else
      cout << '-';
  }
};
