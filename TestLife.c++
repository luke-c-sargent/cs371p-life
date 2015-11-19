// --------------------------------
// projects/darwin/TestDarwin.c++
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <cassert>   // assert
#include "gtest/gtest.h"

#include "Life.h"
#include "Cell.h"

using namespace std;

//Life--------------------------------------------
//  Constructors
/*TEST(LifeFixture, Life_Constructor_1){
	istringstream s("Cell\n1\n2\n3\n4\n*******");
	Life<Cell> l(s);
	ASSERT_EQ(1,l.x);
	ASSERT_EQ(2,l.y);
	ASSERT_EQ(3,l.evolutions);
	ASSERT_EQ(4,l.frequency);
}*/
TEST(LifeFixture, Life_set_living_1){
    istringstream s("1\n1\n...\n...\n...\n");
    Life<ConwayCell> l(3,3,s);
    l.populate_homogeneous_grid();
    l.set_living();
    bool all_correct=true;
    
    for(int i=0; i < 9; i ++){
        auto c = l.at(i);
        if(c.living_neighbors){
            all_correct=false;
            break;}}
            
    ASSERT_TRUE(all_correct);
}

TEST(LifeFixture, Life_set_living_2){
    istringstream s("1\n1\n***\n*.*\n***\n");
    Life<ConwayCell> l(3,3,s);
    l.populate_homogeneous_grid();
    l.print_grid();
    l.set_living();
        
    ASSERT_EQ(l.at(4).living_neighbors,8);
}

//ConwayCell--------------------------------------
//  Constructors
TEST(LifeFixture, Conway_Constructor_1){
    ConwayCell c = ConwayCell();
    ASSERT_FALSE(c.alive);
}

TEST(LifeFixture, Conway_Constructor_2){
    ConwayCell c = ConwayCell(true);
    ASSERT_TRUE(c.alive);
}