#include "pcb.h"
#include "pcbtable.h"
#include <iostream>

using namespace std;

/* COMMAND FOR TERMINAL

g++ main.cpp
./a.out

*/ 

int main(){
    cout << "hello woqqrld!" << endl;

    PCB joe;

    //PCBTable table;
    //PCB* pointy;

    joe.display();

    joe.setPriority(3);
    //joe.setState(prNEW);
    joe.display();


    //table.addPCB(pointy,0);

    return 0;
}
