/**
 * Assignment 1: priority queue of processes
 * @file pcbtable.cpp
 * @author ??? (TODO: your name)
 * @brief This is the implementation file for the PCBTable class.
 * //You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
 * // Remember to add sufficient comments to your code
 */

#include "pcbtable.h"

/**
 * @brief Construct a new PCBTable object of the given size (number of PCBs)
 *
 * @param size: the capacity of the PCBTable
 */
PCBTable::PCBTable(int size) {
   // TODO: add your code here
   this->PCBTable_ = new PCB*[size];
}

/**
 * @brief Destroy the PCBTable object. Make sure to delete all the PCBs in the table.
 *
 */
PCBTable::~PCBTable() {
   // TODO: add your code here
   // Delete all the PCBs in the table
   delete[] this->PCBTable_;
}

/**
 * @brief Get the PCB at index "idx" of the PCBTable.
 *
 * @param idx: the index of the PCB to get
 * @return PCB*: pointer to the PCB at index "idx"
 */
PCB* PCBTable::getPCB(unsigned int idx) {
    // TODO: add your code here
    return PCBTable_[idx];

    /*LEGACY CODE
    //iterates until PCB at given index is found IMPLIMENT IDX CHECK
    for(int i = 0; i <= idx; i++){
        if(i != idx){
            PCBTable_++;
        }
    }
    return *PCBTable_;
    */
}

/**
 * @brief Add a PCB pointer to the PCBTable at index idx.
 *
 * @param pcb: the PCB to add
 */
void PCBTable::addPCB(PCB *pcb, unsigned int idx) {
    // TODO: add your code here
    // Add a PCB pointer to the PCBTable at index idx.

    //Adds the PCB pointer to its index spot in the array 
    PCBTable_[idx] = pcb;


    /* LEGACY CODE
    for(int i = 0; i <= idx; i++){
        if(i == idx){
            //assigns the pointer to the given spot in the array
            *pcb = PCBTable_[i];
        } else{
            i++;
        }
    }
    */
}
