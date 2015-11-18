#include "Cell.h"

Cell::Cell(AbstractCell* _acp): 
		abstractcell_ptr(_acp){
}

Cell::~Cell(){
	delete abstractcell_ptr;
}

void Cell::act(){
  abstractcell_ptr->heterogeneous_grid_act();
//    abstractcell_ptr->act();
    //if(abstractcell_ptr->);
    
}


/*
void Cell::living(Locale l){
  abstractcell_ptr->living(l);
}
*/

AbstractCell* Cell::operator->() {
  return abstractcell_ptr;
} 
