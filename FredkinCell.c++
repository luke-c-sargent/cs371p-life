#include <iostream>
#include "FredkinCell.h"

using namespace std;

FredkinCell::FredkinCell(bool living): 
	age(0) {
  alive = living; }

void FredkinCell::act(){
    //rules:
    //1)a dead cell becomes a live cell, if 1 or 3 neighbors are alive
    if(!alive){
        if(living_neighbors==1 || living_neighbors==3)
            alive=true;
    //2)a live cell becomes a dead cell, if 0, 2, or 4 neighbors are alive
    }else{
        if(living_neighbors%2 == 0 && living_neighbors < 5){ // if its even and < 5
            alive=false;
            age=0;
        }else{
            ++age;}
    }
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