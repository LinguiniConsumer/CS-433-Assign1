#include <iostream>
#include "readyqueue.h"

using namespace std;

//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient comments to your code


/**
 * @brief Constructor for the ReadyQueue class.
 */
 ReadyQueue::ReadyQueue()  {
    cout << "Q made!";
    //TODO: add your code here
    this->PCBQueue_ = new PCB[100];
    this->front_ = this->rear_ = -1;
    this->numElem_ = 0;
 }

/**
 *@brief Destructor
*/
ReadyQueue::~ReadyQueue() {
    //TODO: add your code to release dynamically allocate memory
    delete[] this->PCBQueue_;
}

/**
 * @brief Add a PCB representing a process into the ready queue.
 *
 * @param pcbPtr: the pointer to the PCB to be added
 */
void ReadyQueue::addPCB(PCB *pcbPtr) {
    //TODO: add your code here
    // When adding a PCB to the queue, you must change its state to READY.
    cout << "BALLS!" << endl;

    if(this->numElem_ > this->rear_){
        this->rear_++;
    }
    else if(this->numElem_ == this->rear_){
        this->rear_ = 0;
    }

    //assigns pointer to this new element ??
    PCBQueue_[this->rear_] = *pcbPtr;
    PCBQueue_[this->rear_].setState(ProcState::READY);

}

/**
 * @brief Remove and return the PCB with the highest priority from the queue
 *
 * @return PCB*: the pointer to the PCB with the highest priority
 */
PCB* ReadyQueue::removePCB() {
    //TODO: add your code here
    // When removing a PCB from the queue, you must change its state to RUNNING.
    cout << "BALLS!" << endl;
    if(this->front_ == -1){
        return NULL;
    }

    if(this->front_ == this->rear_){
        this->front_ = this->rear_ = -1;
    } else{
        this->rear_--;
        this->numElem_--;
    }
}

/**
 * @brief Returns the number of elements in the queue.
 *
 * @return int: the number of PCBs in the queue
 */
int ReadyQueue::size() {
    //TODO: add your code here
    return this->numElem_;
}

/**
 * @brief Display the PCBs in the queue.
 */
void ReadyQueue::displayAll() {
    //TODO: add your code here
    cout << "BALLS!" << endl;
}