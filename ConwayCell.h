#pragma once

#include "AbstractCell.h"

#ifndef LOCALE
#define LOCALE
struct Locale{
    int n,ne,e,se,s,sw,w,nw;
    Locale():n(0),ne(0),e(0),se(0),s(0),sw(0),w(0),nw(0){}
};
#endif

class ConwayCell: public AbstractCell{
  public:
  ConwayCell(bool living = false);
  void act();
  void living(Locale);
  void print_cell(); 
  ConwayCell* operator ->();
};
