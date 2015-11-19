#pragma once

#include "AbstractCell.h"

/*
#ifndef LOCALE
#define LOCALE

struct Locale{
    int n,ne,e,se,s,sw,w,nw;
    Locale():n(0),ne(0),e(0),se(0),s(0),sw(0),w(0),nw(0){}
}; 
#endif
*/

class Cell{
	friend class FredkinCell;
	friend class ConwayCell;

public:	
//    void living(Locale);
	AbstractCell* abstractcell_ptr;
	Cell(AbstractCell* = nullptr);
    ~Cell();
    int act();
    AbstractCell* operator -> ();
};

