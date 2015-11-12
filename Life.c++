#include <iostream> 

#include "Life.h"

template <typename CellType>
Life<CellType>::Life(istream& input_stream){
	
	string type;

	//parse input text:
	string line;

	getline(input_stream,line);// Cell type
	type=line;

	input_stream >> x;// rows
	input_stream >> y;// cols
	input_stream >> evolutions;// evolution
	input_stream >> frequency;//frequency
}