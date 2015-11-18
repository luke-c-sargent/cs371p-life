#include "Cell.h"

Cell::Cell(AbstractCell* _acp): 
		abstractcell_ptr(_acp){
}

Cell::~Cell(){
	delete abstractcell_ptr;
}

void Cell::act(){
    abstractcell_ptr->act();
    //if(abstractcell_ptr->);
    
}

AbstractCell* Cell::operator->() {
  return abstractcell_ptr;
} 
