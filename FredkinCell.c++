#include <iostream>
#include "FredkinCell.h"

using namespace std;

FredkinCell::FredkinCell(bool living): 
	age(0) {
  alive = living; }

void FredkinCell::act(){

}

void FredkinCell::print_cell() {
  if (alive)
    cout << age;
  else
    cout << '-';
}

FredkinCell* FredkinCell::operator->() {
  return this;
}
