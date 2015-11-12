#include "Life.h"

Life::Life(istream& input_stream){
	
	string type;

	//parse input text:
	string line;

	getline(input_stream,line);// Cell type
	type=line;
	//getline(input_stream,line);// rows
	x << input_stream;
	// cols
	y << input_stream;
	// evolution
	evolutions << input_stream;
	// frequency of print
	frequency << input_stream;
}