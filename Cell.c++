#include "Cell.h"

Cell::Cell(AbstractCell* _acp): 
		abstractcell_ptr(_acp){
}

Cell::~Cell(){
	delete abstractcell_ptr;
}

void Cell::act(){
	abstractcell_ptr->act();
}