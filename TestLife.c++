// --------
// includes
// --------
 
#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <cassert>   // assert
#include "gtest/gtest.h"
 
#include "Life.h"
 
using namespace std;
 
//Life--------------------------------------------
//  Constructors
TEST(LifeFixture, Life_Constructor_1){
        istringstream s("3\n4\n*******");
        Life<Cell> l(1,2,s);
        ASSERT_EQ(1,l.grid_rows);
        ASSERT_EQ(2,l.grid_cols);
        ASSERT_EQ(3,l.evolutions);
        ASSERT_EQ(4,l.frequency);
}
TEST(LifeFixture, Life_Constructor_2){
        istringstream s("3\n4\n....");
        Life<ConwayCell> l(2,2,s);
    ASSERT_EQ(0,l.generation);
    ASSERT_EQ(0,l.population);
}
 
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
    l.set_living();
       
    ASSERT_EQ(l.at(4).living_neighbors,8);
}
 
//ConwayCell--------------------------------------
//  Constructor
TEST(LifeFixture, Conway_Constructor_1){
    ConwayCell c = ConwayCell();
    ASSERT_FALSE(c.alive);
}
TEST(LifeFixture, Conway_Constructor_2){
    ConwayCell c = ConwayCell(true);
    ASSERT_TRUE(c.alive);
}
TEST(LifeFixture, Conway_Constructor_3){
    ConwayCell c = ConwayCell(false);
    ASSERT_FALSE(c.alive);
}
TEST(LifeFixture, Conway_Constructor_4){
    ConwayCell c = ConwayCell(true);
    ASSERT_EQ(c.living_neighbors,0);
}
//  living
TEST(LifeFixture, Conway_living_1){
    ConwayCell c = ConwayCell(true);
    Locale l;
    l.n=l.s=l.e=l.w=l.sw=l.se=l.nw=l.ne=1;
    c.living(l);
    ASSERT_EQ(c.living_neighbors,8);
}
TEST(LifeFixture, Conway_living_2){
    ConwayCell c = ConwayCell(true);
    Locale l;
    l.n=l.s=l.e=l.w=l.sw=l.se=l.nw=l.ne=0;
    c.living(l);
    ASSERT_EQ(c.living_neighbors,0);
}
TEST(LifeFixture, Conway_living_3){
ConwayCell c = ConwayCell(true);
    Locale l;
    l.n=l.s=l.e=l.w=1;
    l.sw=l.se=l.nw=l.ne=0;
    c.living(l);
    ASSERT_EQ(c.living_neighbors,4);
}
TEST(LifeFixture, Conway_living_4){
    ConwayCell c = ConwayCell(true);
    Locale l;
    l.n=l.s=l.e=l.w=0;
    l.sw=l.se=l.nw=l.ne=1;
    c.living(l);
    ASSERT_EQ(c.living_neighbors,4);
}
//  heterogeneous_grid_act()
TEST(LifeFixture,Conway_hetero_act_1){
    ConwayCell c = ConwayCell(true);
    ASSERT_FALSE(c.heterogeneous_grid_act());
}
 
TEST(LifeFixture,Conway_hetero_act_2){
    ConwayCell c = ConwayCell(false);
    ASSERT_FALSE(c.heterogeneous_grid_act());
}
//  act()
TEST(LifeFixture,Conway_act_1){
    ConwayCell c = ConwayCell(false);
    c.living_neighbors=3;
    ASSERT_EQ(c.act(),1);
    ASSERT_TRUE(c.alive);
}
TEST(LifeFixture,Conway_act_2){
    ConwayCell c = ConwayCell(false);
    c.living_neighbors=2;
    ASSERT_EQ(c.act(),0);
    ASSERT_FALSE(c.alive);
}
TEST(LifeFixture,Conway_act_3){
    ConwayCell c = ConwayCell(true);
    c.living_neighbors=2;
    ASSERT_EQ(c.act(),0);
    ASSERT_TRUE(c.alive);
}
TEST(LifeFixture,Conway_act_4){
    ConwayCell c = ConwayCell(true);
    c.living_neighbors=4;
    ASSERT_EQ(c.act(),-1);
    ASSERT_FALSE(c.alive);
}
TEST(LifeFixture,Conway_act_5){
    ConwayCell c = ConwayCell(true);
    c.living_neighbors=1;
    ASSERT_EQ(c.act(),-1);
    ASSERT_FALSE(c.alive);
}
//FredkinCell--------------------------------------
//  Constructor
TEST(LifeFixture, FredkinCell_Constructor_1){
    FredkinCell f = FredkinCell();
    ASSERT_FALSE(f.alive);
}
TEST(LifeFixture, FredkinCell_Constructor_2){
    FredkinCell f = FredkinCell(true);
    ASSERT_TRUE(f.alive);
}
TEST(LifeFixture, FredkinCell_Constructor_3){
    FredkinCell f = FredkinCell(false);
    ASSERT_FALSE(f.alive);
}
TEST(LifeFixture, FredkinCell_Constructor_4){
    FredkinCell f = FredkinCell(false);
    ASSERT_EQ(f.living_neighbors,0);
}
//  living
TEST(LifeFixture, FredkinCell_living_1){
    FredkinCell c = FredkinCell(true);
    Locale l;
    l.n=l.s=l.e=l.w=l.sw=l.se=l.nw=l.ne=1;
    c.living(l);
    ASSERT_EQ(c.living_neighbors,4);
}
TEST(LifeFixture, FredkinCell_living_2){
    FredkinCell c = FredkinCell(true);
    Locale l;
    l.n=l.s=l.e=l.w=l.sw=l.se=l.nw=l.ne=0;
    c.living(l);
    ASSERT_EQ(c.living_neighbors,0);
}
TEST(LifeFixture, FredkinCell_living_3){
    FredkinCell c = FredkinCell(true);
    Locale l;
    l.n=l.s=l.e=l.w=1;
    l.sw=l.se=l.nw=l.ne=0;
    c.living(l);
    ASSERT_EQ(c.living_neighbors,4);
}
TEST(LifeFixture, FredkinCell_living_4){
    FredkinCell c = FredkinCell(true);
    Locale l;
    l.n=l.s=l.e=l.w=0;
    l.sw=l.se=l.nw=l.ne=1;
    c.living(l);
    ASSERT_EQ(c.living_neighbors,0);
}
//  heterogenous_grid_act()
TEST(LifeFixture, FredkinCell_hetero_act_1){
    FredkinCell c = FredkinCell(true);//age 0
    ASSERT_FALSE(c.heterogeneous_grid_act());
}
TEST(LifeFixture, FredkinCell_hetero_act_2){
    FredkinCell c = FredkinCell(true);
    c.age=1;
    ASSERT_FALSE(c.heterogeneous_grid_act());
}
TEST(LifeFixture, FredkinCell_hetero_act_3){
    FredkinCell c = FredkinCell(true);
    c.age=1;
    c.living_neighbors=1;
    ASSERT_TRUE(c.heterogeneous_grid_act());
}
TEST(LifeFixture, FredkinCell_hetero_act_4){
    FredkinCell c = FredkinCell(false);
    c.age=1;
    c.living_neighbors=1;
    ASSERT_FALSE(c.heterogeneous_grid_act());
}
//  act()
TEST(LifeFixture,FredkinCell_act_1){
    FredkinCell c = FredkinCell(false);
    c.living_neighbors=1;
    ASSERT_EQ(c.act(),1);
    ASSERT_TRUE(c.alive);
}
TEST(LifeFixture,FredkinCell_act_2){
    FredkinCell c = FredkinCell(false);
    c.living_neighbors=2;
    ASSERT_EQ(c.act(),0);
    ASSERT_FALSE(c.alive);
}
TEST(LifeFixture,FredkinCell_act_3){
    FredkinCell c = FredkinCell(false);
    c.living_neighbors=3;
    ASSERT_EQ(c.act(),1);
    ASSERT_TRUE(c.alive);
}
TEST(LifeFixture,FredkinCell_act_4){
    FredkinCell c = FredkinCell(true);
    c.living_neighbors=4;
    ASSERT_EQ(c.act(),-1);
    ASSERT_FALSE(c.alive);
}
TEST(LifeFixture,FredkinCell_act_5){
    FredkinCell c = FredkinCell(true);
    c.living_neighbors=1;
    ASSERT_EQ(c.act(),0);
    ASSERT_TRUE(c.alive);
    ASSERT_EQ(c.age,1);
}
//Cell---------------------------------
//  constructor
TEST(LifeFixture,Cell_constructor_1){
    Cell c(new ConwayCell(true));
    ASSERT_EQ(-1,c.act());
}
TEST(LifeFixture,Cell_constructor_2){
    Cell c(new FredkinCell(true));
    ASSERT_EQ(-1,c.act());
}
TEST(LifeFixture,Cell_constructor_3){
    Cell c(new FredkinCell(false));
    ASSERT_EQ(0,c.act());
}
//  living
TEST(LifeFixture, Cell_living_1){
    Cell c(new FredkinCell(false));
    Locale l;
    l.n=l.s=l.e=l.w=l.sw=l.se=l.nw=l.ne=1;
    c.living(l);
    ASSERT_EQ(c->living_neighbors,4);
}
TEST(LifeFixture, Cell_living_2){
    Cell c(new FredkinCell(false));
    Locale l;
    l.n=l.s=l.e=l.w=l.sw=l.se=l.nw=l.ne=0;
    c.living(l);
    ASSERT_EQ(c->living_neighbors,0);
}
TEST(LifeFixture, Cell_living_3){
    Cell c(new FredkinCell(false));
    Locale l;
    l.n=l.s=l.e=l.w=1;
    l.sw=l.se=l.nw=l.ne=0;
    c.living(l);
    ASSERT_EQ(c->living_neighbors,4);
}
TEST(LifeFixture, Cell_living_4){
    Cell c(new FredkinCell(false));
    Locale l;
    l.n=l.s=l.e=l.w=0;
    l.sw=l.se=l.nw=l.ne=1;
    c.living(l);
    ASSERT_EQ(c->living_neighbors,0);
}
TEST(LifeFixture, Cell_living_5){
    Cell c(new ConwayCell(false));
    Locale l;
    l.n=l.s=l.e=l.w=l.sw=l.se=l.nw=l.ne=1;
    c.living(l);
    ASSERT_EQ(c->living_neighbors,8);
}
TEST(LifeFixture, Cell_living_6){
    Cell c(new ConwayCell(false));
    Locale l;
    l.n=l.s=l.e=l.w=l.sw=l.se=l.nw=l.ne=0;
    c.living(l);
    ASSERT_EQ(c->living_neighbors,0);
}
TEST(LifeFixture, Cell_living_7){
    Cell c(new ConwayCell(false));
    Locale l;
    l.n=l.s=l.e=l.w=1;
    l.sw=l.se=l.nw=l.ne=0;
    c.living(l);
    ASSERT_EQ(c->living_neighbors,4);
}
TEST(LifeFixture, Cell_living_8){
    Cell c(new ConwayCell(false));
    Locale l;
    l.n=l.s=l.e=l.w=0;
    l.sw=l.se=l.nw=l.ne=1;
    c.living(l);
    ASSERT_EQ(c->living_neighbors,4);
}
