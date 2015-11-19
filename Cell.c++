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
  //abstractcell_ptr->heterogeneous_grid_act();
/*    
  if(abstractcell_ptr->heterogeneous_grid_act()){
    abstractcell_ptr = new ConwayCell(true);
    return 0;
  } else { return abstractcell_ptr->act();}
*/
  return 0;
}


void Cell::living(Locale l){
  abstractcell_ptr->living(l);
}


AbstractCell* Cell::operator->() {
//  cout << "in operator" << endl;
  return abstractcell_ptr;
} 
