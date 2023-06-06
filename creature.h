
#ifndef ASS3_CREATURE_H
#define ASS3_CREATURE_H

#include "maze.h"
#include <ostream>

#include <iostream>
using namespace std;


class Creature {
public:
  
  // prints the position of the creature 
  friend ostream &operator<<(ostream &Out, const Creature &Creature);

private:
  int Row;
  int Col;
  
public:
 // constructor take row and column as the parameters
  Creature(int Row, int Col);
 
 // returns a string in the form of NNEEN
 // pre-con: the maze and the creature need to be properly initiated
 // post-con: add all the direction that was considered
 //           as part of the path to to the string Path
  string solve(Maze &Maze);

 // checks if the creature is at the exit
 // returns true if the creature is at the exit
 // pre-con: the maze and the creature need to be properly initiated
 // post-con: the column and the row that the creature is at has to
 //           match with the exit row and exit column
  bool atExit(const Maze &Maze) const;

  // moves the creature towards north direction and solve the maze through recursion
  // returns N if the creature has moved towards north direction
  // returns an empty string if otherwise
  // pre-con: the maze and the creature need to be properly initiated
  // post-con: attempted to go north. Check other paths and
  //           call other recursive functions to solve maze
  string goNorth(Maze &Maze);

  // moves the creature towards west direction and solve the maze through recursion
  // returns W if the creature has moved towards west direction
  // returns an empty string if otherwise
  // pre-con: the maze and the creature need to be properly initiated
  // post-con: attempted to go west. Check other paths and
  //           call other recursive functions to solve maze
  string goWest(Maze &Maze);

  // moves the creature towards east direction and solve the maze through recursion
  // returns E if the creature has moved towards east direction
  // returns an empty string if otherwise
  // pre-con: the maze and the creature need to be properly initiated
  // post-con: attempted to go east. Check other paths and
  //           call other recursive functions to solve maze
  string goEast(Maze &Maze);

  // moves the creature towards south direction and solve the maze through recursion
  // returns S if the creature has moved towards south direction
  // returns an empty string if otherwise
  // pre-con: the maze and the creature need to be properly initiated
  // post-con: attempted to go south. Check other paths and
  //           call other recursive functions to solve maze
  string goSouth(Maze &Maze);

  // row component
  int getRow() const;

  // column component
  int getCol() const;
};

#endif //ASS3_CREATURE_H
