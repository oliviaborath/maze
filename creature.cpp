#include "creature.h"

// prints the position of the creature 
ostream &operator<<(ostream &Out, const Creature &Creature) {
    Out << "(" << Creature.getRow() << ", " << Creature.getCol() << ")";
    return Out;
}

// constructor take row and column as the parameters
Creature::Creature(int Row, int Col) : Row(Row), Col(Col) {} 

// returns a string in the form of NNEEN
// pre-con: the maze and the creature need to be properly initiated
// post-con: add all the direction that was considered
//           as part of the path to to the string Path
string Creature::solve(Maze &Maze) {
    string Path; 
    Maze.markAsPath(this->getRow(), this->getCol());
    // if the creature is still not at the exit
    // recursively call all the possible direction that
    // the creature can move to
    if(!atExit(Maze)) {
        if(Maze.isClear(this->getRow() - 1, this->getCol())) {
            Path += goNorth(Maze);
        }
    }
    if(!atExit(Maze)) {
        if(Maze.isClear(this->getRow(), this->getCol() + 1)) {
            Path += goEast(Maze);    
        }
    }
    if(!atExit(Maze)) {
        if(Maze.isClear(this->getRow(), this->getCol() - 1)) {
            Path += goWest(Maze);  
        }
    }
    if(!atExit(Maze)) {
        if(Maze.isClear(this->getRow() + 1, this->getCol())) {
            Path += goSouth(Maze); 
        }
    }
    return Path;
}

// checks if the creature is at the exit
// returns true if the creature is at the exit
// pre-con: the maze and the creature need to be properly initiated
// post-con: the column and the row that the creature is at has to
//           match with the exit row and exit column
bool Creature::atExit(const Maze &Maze) const {
    int currentRow = this->getRow();
    int currentCol = this->getCol();
    int mazeExitRow = Maze.getExitRow();
    int mazeExitCol = Maze.getExitColumn();
    return (mazeExitRow == currentRow && mazeExitCol == currentCol);
}

// moves the creature towards north direction and solve the maze through recursion
// returns N if the creature has moved towards north direction
// returns an empty string if otherwise
// pre-con: the maze and the creature need to be properly initiated
// post-con: attempted to go north. Check other paths and
//           call other recursive functions to solve maze
string Creature::goNorth(Maze &Maze) { 
    string path = "";  
    // check if out of bound or not
    // check if north direction is clear. if clear, move north
    if(this->getRow() - 1 >= 0 && Maze.isClear(this->getRow() - 1, this->getCol())) {
            //update the row
            Row--;
            //mark the new square that the creature moved to as a path
            Maze.markAsPath(this->getRow(), this->getCol());
            if(atExit(Maze)) {
                return "N";
            } 
            else {
                path = goEast(Maze);
                if(path != "") {
                    Maze.markAsPath(this->getRow(), this->getCol());      
                    return "N" + path;
                }
                path = goWest(Maze);
                if(path != "") {
                    Maze.markAsPath(this->getRow(), this->getCol());      
                    return "N" + path;
                }
                path = goNorth(Maze);
                if(path != "") {
                    Maze.markAsPath(this->getRow(), this->getCol());      
                    return "N" + path;
                }
                Row++;
                Maze.markAsVisited(this->getRow(), this->getCol());
                return "";
            } 
    }
    else {
        return "";
    }
    return "N";
}

// moves the creature towards west direction and solve the maze through recursion
// returns W if the creature has moved towards west direction
// returns an empty string if otherwise
// pre-con: the maze and the creature need to be properly initiated
// post-con: attempted to go west. Check other paths and
//           call other recursive functions to solve maze
string Creature::goWest(Maze &Maze) {
    string path = "";
    // check if out of bound or not
    // check if west direction is clear. if clear, move west 
    if(this->getCol() - 1 >= 0 && this->getRow() >= 0 &&
        Maze.isClear(this->getRow(), this->getCol() - 1)) {
            //update the column
            Col--;
            //mark the new square that the creature moved to as a path
            Maze.markAsPath(this->getRow(), this->getCol());
            if(atExit(Maze)) {
                return "W";
            }
            else {
                path = goNorth(Maze);
                if(path != "") {
                    Maze.markAsPath(this->getRow(), this->getCol());      
                    return "W" + path;
                }
                path = goSouth(Maze);
                if(path != "") {
                    Maze.markAsPath(this->getRow(), this->getCol());      
                    return "W" + path;
                }
                path = goWest(Maze);
                if(path != "") {
                    Maze.markAsPath(this->getRow(), this->getCol());      
                    return "W" + path;
                }
                Col++;
                Maze.markAsVisited(this->getRow(), this->getCol());
                return "";
            }     
    }
    else {
        return "";
    }
    return "W";
}

// moves the creature towards east direction and solve the maze through recursion
// returns E if the creature has moved towards east direction
// returns an empty string if otherwise
// pre-con: the maze and the creature need to be properly initiated
// post-con: attempted to go east. Check other paths and
//           call other recursive functions to solve maze
string Creature::goEast(Maze &Maze) {
    string path = "";
    // check if out of bound or not
    // check if east direction is clear. if clear, move east
    if((this->getCol() + 1) < Maze.getWidth() &&
        Maze.isClear(this->getRow(), this->getCol() + 1)) {
            // update the column
            Col++;
            // mark the new square that the creature moved to as a path
            Maze.markAsPath(this->getRow(), this->getCol());
            if(atExit(Maze)) {
                return "E";
            } 
            else {
                path = goNorth(Maze);
                if(path != "") {
                    Maze.markAsPath(this->getRow(), this->getCol());      
                    return "E" + path;
                }
                path = goSouth(Maze);
                if(path != "") {
                    Maze.markAsPath(this->getRow(), this->getCol());      
                    return "E" + path;
                }
                path = goEast(Maze);
                if(path != "") {
                    Maze.markAsPath(this->getRow(), this->getCol());      
                    return "E" + path;
                }
                Col--;
                Maze.markAsVisited(this->getRow(), this->getCol());
                return "";
            }           
    }
    else {
        return "";
    }
    return "E";
}

// moves the creature towards south direction and solve the maze through recursion
// returns S if the creature has moved towards south direction
// returns an empty string if otherwise
// pre-con: the maze and the creature need to be properly initiated
// post-con: attempted to go south. Check other paths and
//           call other recursive functions to solve maze
string Creature::goSouth(Maze &Maze) {  
    string path = "";
    // check if out of bound or not 
    // check if south direction is clear. if clear, move south
    if((this->getRow() + 1) < Maze.getHeight() &&
        Maze.isClear(this->getRow() + 1, this->getCol())) {
            // update the row
            Row++;
            // mark the new square that the creature moved to as a path
            Maze.markAsPath(this->getRow(), this->getCol());
            if(atExit(Maze)) {             
                return "S";
            } 
            else {
                path = goWest(Maze);
                if(path != "") {
                    Maze.markAsPath(this->getRow(), this->getCol());      
                    return "S" + path;
                }
                path = goEast(Maze);
                if(path != "") {
                    Maze.markAsPath(this->getRow(), this->getCol());      
                    return "S" + path;
                }
                path = goSouth(Maze);
                if(path != "") {
                    Maze.markAsPath(this->getRow(), this->getCol());      
                    return "S" + path;
                }
                Row--;
                Maze.markAsVisited(this->getRow(), this->getCol());
                return "";
            }             
    }
    else {
        return "";
    }
    return "S";
}

// row component
int Creature::getRow() const { 
    return Row; 
}

// column component
int Creature::getCol() const { 
    return Col; 
}
