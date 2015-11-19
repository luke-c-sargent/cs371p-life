#include <iostream>
#include "ConwayCell.h"

#ifndef DEBUG
#define DEBUG true
#endif

using namespace std;
ConwayCell::ConwayCell(bool living){
    alive = living;
    living_neighbors=0;
}

int ConwayCell::act(){
    int delta=0;
    //rules:
    //1)a dead cell becomes a live cell, if exactly 3 neighbors are alive
    if(!alive){ // if its dead
        if(living_neighbors==3){
            alive=true;
            delta=1;
        }
    } 
    //2)a live cell becomes a dead cell, if less than 2 or more than 3 neighbors are alive
    else { //if it's alive
        if(living_neighbors < 2 || living_neighbors > 3){
            alive=false;
            delta=-1;
        }
    }
    //reset living neighbors value for next pass
    living_neighbors=0;
    return delta;
}

void ConwayCell::print_cell(){
  if (alive)
    cout << '*';
  else
    cout << '.';
}

bool ConwayCell::heterogeneous_grid_act(){
  return false;
}

ConwayCell* ConwayCell::operator->() {
  return this;
}

void ConwayCell::living(Locale l){
    if(DEBUG){cout<<"CC::L:"<<l.n<<l.ne<<l.e<<l.se<<l.s<<l.sw<<l.w<<l.nw<<endl;}
  living_neighbors += (l.n+l.ne+l.e+l.se+l.s+l.sw+l.w+l.nw);
}
