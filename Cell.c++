#include <iostream>
#include "Cell.h"

using namespace std;
Cell::Cell(AbstractCell* _acp): 
		abstractcell_ptr(_acp){
}

Cell::~Cell(){
	delete abstractcell_ptr;
}

int Cell::act(){
<<<<<<< HEAD
//  cout << "in cell act" << endl;
  abstractcell_ptr->heterogeneous_grid_act();
//    abstractcell_ptr->act();
    //if(abstractcell_ptr->);
    
=======
  if(abstractcell_ptr->heterogeneous_grid_act()){
    abstractcell_ptr = new ConwayCell(true);
    return 0;
  } else { return abstractcell_ptr->act();}
>>>>>>> 6e47f4f8a602ac5d6c95b2e7fffc8c8013cd0811
}


void Cell::living(Locale l){
  abstractcell_ptr->living(l);
}


AbstractCell* Cell::operator->() {
//  cout << "in operator" << endl;
  return abstractcell_ptr;
} 
