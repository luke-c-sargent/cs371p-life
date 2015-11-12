#include "Cell.h"

Cell::Cell(AbstractCell* _acp): 
		abstractcell_ptr(_acp){

}

Cell::~Cell(){
	delete acp;
}

void Cell::act(){
	acp->act();
}