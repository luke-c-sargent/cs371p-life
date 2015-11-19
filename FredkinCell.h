#pragma once
#include "AbstractCell.h"

#ifndef LOCALE
#define LOCALE
struct Locale{
    int n,ne,e,se,s,sw,w,nw;
    Locale():n(0),ne(0),e(0),se(0),s(0),sw(0),w(0),nw(0){}
};
#endif

class FredkinCell: public AbstractCell{
  int age;
  
  public:
<<<<<<< HEAD
	  FredkinCell(bool living = false);
	  int act();
=======
	FredkinCell(bool living = false);
	int act();
>>>>>>> 6e47f4f8a602ac5d6c95b2e7fffc8c8013cd0811
    void print_cell();
    void living(Locale);
    bool heterogeneous_grid_act();
    FredkinCell* operator->();
};
