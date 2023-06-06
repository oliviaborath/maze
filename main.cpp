#include <cassert>
#include <iostream>
#include <sstream>

#include "creature.h"
#include "maze.h"
using namespace std;

void test() {
    Maze M("maze.txt");
    Creature C(4, 4);
    stringstream ss;
    ss << C;
    assert(ss.str() == "(4, 4)");
    cout << "Starting Position: " << ss.str() << endl;
    
    cout << "Expected Path:" << endl;
    cout << "EEENNNEEEEEESEESSSEEENNNNN" << endl;
    cout << "Path: " << endl;
    cout << C.solve(M) << endl;

    ss.str("");
    ss << C;
    assert(ss.str() == "(0, 18)" );
    cout << M << endl;
}
void test1() {
    Maze M1("maze1.txt");
    Creature C(4, 6);
    stringstream ss;
    ss << C;
    assert(ss.str() == "(4, 6)");
    cout << "Starting Position: " << C << endl;

    cout << "Expected Path:" << endl;
    cout << "ENNNEEES" << endl;
    cout << "Path: " << endl;
    cout << C.solve(M1) << endl;

    ss.str("");
    ss << C;
    assert(ss.str() == "(2, 10)" );
    cout << M1 << endl;
}
void test2() {
    Maze M2("maze2.txt");
    Creature C(2, 1);
    stringstream ss;
    ss << C;
    assert(ss.str() == "(2, 1)");
    cout << "Starting Position: " << C << endl;

    cout << "Expected Path:" << endl;
    cout << "N" << endl;
    cout << "Path: " << endl;
    cout << C.solve(M2) << endl;
 
    ss.str("");
    ss << C;
    assert(ss.str() == "(1, 1)" );
    cout << M2 << endl;
}
void test3() {
    Maze M3("maze3.txt");
    Creature C(1, 4);
    stringstream ss;
    ss << C;
    assert(ss.str() == "(1, 4)");
    cout << "Starting Position: " << C << endl;

    cout << "Expected Path: " << "" << endl;
    cout << "Path: " << C.solve(M3) << endl;

    ss.str("");
    ss << C;
    assert(!(ss.str() == "(5, 1)" ));
    cout << M3 << endl;
}
int main() {
    test();
    test1();
    test2();
    test3();
    cout << "Done!" << std::endl;
    return 0;
}
