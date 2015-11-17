#include <iostream>
#include "ConwayCell.h"

using namespace std;
ConwayCell::ConwayCell(bool living){
    alive = living;
  }

void ConwayCell::act(){
}

void ConwayCell::print_cell(){
  if (alive)
    cout << '*';
  else
    cout << '.';
}

ConwayCell* ConwayCell::operator->() {
  return this;
}
