//#pragma once
#include <iostream>
#include "AbstractCell.h"

using namespace std;
class FredkinCell: public AbstractCell{
  int age;
  
  public:
	  FredkinCell(bool living = false);
	  void act();
    void print_cell();
};
