#include <iostream> 
#include <cstring>

#include "Life.h"

using namespace std;


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

FredkinCell::FredkinCell(bool living): 
	age(0){
  alive = living; 
  living_neighbors=0;}

int FredkinCell::act(){
    //rules:
    //1)a dead cell becomes a live cell, if 1 or 3 neighbors are alive
    int delta=0;
    if(!alive){
        if(living_neighbors==1 || living_neighbors==3){
            alive=true;
            delta = 1;
        }
    //2)a live cell becomes a dead cell, if 0, 2, or 4 neighbors are alive
    }else{
        if(living_neighbors%2 == 0 && living_neighbors < 5){ // if its even and < 5
            alive=false;
            delta = -1;
        }else
         {
            ++age;}
    }
    //reset living neighbors value for next pass
    living_neighbors=0;
    return delta;
}
void FredkinCell::living(Locale l){
  living_neighbors += (l.n + l.e + l.s + l.w);
}

void FredkinCell::print_cell() {
  if (alive){
    if(age<10)
        cout << age;
    else
        cout << "+";
  }
  else
    cout << '-';
}

bool FredkinCell::heterogeneous_grid_act(){
  // we have to return false if the cell would die, and true if the cell
  //would live and is to turn 2.
  return (age == 1 && !((living_neighbors%2 == 0) && (living_neighbors < 5)) && alive);
}

FredkinCell* FredkinCell::operator->() {
  return this;
}

Cell::Cell(AbstractCell* _acp): 
		abstractcell_ptr(_acp){
}

Cell::~Cell(){
	delete abstractcell_ptr;
}

int Cell::act(){
  if(abstractcell_ptr->heterogeneous_grid_act()){
    delete abstractcell_ptr;
    abstractcell_ptr = new ConwayCell(true);
    return 0;
  } else { return abstractcell_ptr->act();}

  return 0;
}


void Cell::living(Locale l){
  abstractcell_ptr->living(l);
}


AbstractCell* Cell::operator->() {
  return abstractcell_ptr;
} 
