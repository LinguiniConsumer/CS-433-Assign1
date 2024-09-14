#include <iostream>
#include "readyqueue.h"

using namespace std;

//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient comments to your code


/**
 * @brief Constructor for the ReadyQueue class.
 */
 ReadyQueue::ReadyQueue()  {
    //TODO: add your code here
    this->PCBQueue_ = new PCB*[100];
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
    // resize the Heap array if neccessary and insert the value into the heap.
    // percolate the Heap to rearange after the value is inserted

    //To large, resizes
    if (numElem_ == cap_) {
        cap_ = cap_ * 2 + 1;
    }

  //Empty
  else if (this->numElem_ == 0) {
    //inserts value into first position
    PCBQueue_[0] = pcbPtr;
    numElem_++;
    return; 
  }

  //all other cases: simply uses percolate up to insert value in proper place
  else{
    //sets new element after the last element
    PCBQueue_[numElem_] = pcbPtr;
    percolateUp(numElem_);
    numElem_++;
  }


    /*LEGACY CODE
    if(this->numElem_ > this->rear_){
        this->rear_++;
    }
    else if(this->numElem_ == this->rear_){
        this->rear_ = 0;
    }

    //assigns pointer to this new element ??
    PCBQueue_[this->rear_] = *pcbPtr;
    PCBQueue_[this->rear_].setState(ProcState::READY);
    */
}

/**
 * @brief Remove and return the PCB with the highest priority from the queue
 *
 * @return PCB*: the pointer to the PCB with the highest priority
 */
PCB* ReadyQueue::removePCB() {
    //TODO: add your code here
    // When removing a PCB from the queue, you must change its state to RUNNING.
    return PCBQueue_[0];

    /*
    cout << "S!" << endl;
    if(this->front_ == -1){
        return NULL;
    }

    if(this->front_ == this->rear_){
        this->front_ = this->rear_ = -1;
    } else{
        this->rear_--;
        this->numElem_--;
    }
    */
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
    cout << "B!" << endl;
}



//==================NEW FUNCTIONS===================

  // Helper functions.
    /**
     * @brief Returns the left child of the node at index
     */
int  ReadyQueue::leftChild(int index)
    {
        return 2 * index + 1;
    }
    /**
     * @brief Returns the right child of the node at index
     */
    int  ReadyQueue::rightChild(int index)
    {
        return 2 * index + 2;
    };

void ReadyQueue::percolateDown(int index) {
    //check the values at index in the heap and decide whether they need to be swapped.
    // Run recursively until the current node is bigger than its children

  //sets local variables left,right to the index of the left and right child
  int left = leftChild(index);
  int right = rightChild(index);

  //local varaible denoting the node which after searching will be bigger than its children
  int biggest = index;

  //checks first if the left index is within range
  //checks for biggest value on leftChild
  if(numElem_ > left && PCBQueue_[index] < PCBQueue_[left]){
    biggest = left;
  }

  //checks for biggest value on rightChild
  if(numElem_ > right && PCBQueue_[index] < PCBQueue_[right]){
    biggest = right;
  }

  //RECURSIVE CALL
  if(index != biggest){
    swap(biggest, index);
    percolateDown(biggest);
  }
}

void ReadyQueue::percolateUp(int index) {
  // check the value of the parents of index in the heap and swap them if they are smaller
    // run recursively until the current node is small than its parent
    int cur_parent = (index - 1) / 2;
    int new_parent = cur_parent;


  //BASE CASE
    if (index == 0) {
        return;
    }

  //recursively runs while the current node is greater than its parent
  if(PCBQueue_[index] > PCBQueue_[cur_parent]){
    swap(cur_parent, index);
    percolateUp(new_parent);
  }
}
