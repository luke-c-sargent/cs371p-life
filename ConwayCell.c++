#include <iostream>
#include "ConwayCell.h"

using namespace std;
ConwayCell::ConwayCell(bool living){
    alive = living;
}

void ConwayCell::act(){
    //rules:
    //1)a dead cell becomes a live cell, if exactly 3 neighbors are alive
    if(!alive){ // if its dead
        if(living_neighbors==3)
            alive=true;
    } 
    //2)a live cell becomes a dead cell, if less than 2 or more than 3 neighbors are alive
    else { //if it's alive
        if(living_neighbors < 2 || living_neighbors > 3)
            alive=false;
    }
    //reset living neighbors value for next pass
    living_neighbors=0;
}

void ConwayCell::print_cell(){
  if (alive)
    cout << '*';
  else
    cout << '.';
}

void ConwayCell::heterogeneous_grid_act(){
  act();
}

ConwayCell* ConwayCell::operator->() {
  return this;
}

void ConwayCell::living(Locale l){
  living_neighbors += (l.n+l.ne+l.e+l.se+l.s+l.sw+l.w+l.nw);
}
