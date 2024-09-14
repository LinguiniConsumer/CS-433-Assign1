#include "heap.h"

// @brief gets the maximum value in the heap
// @return the highest value integer in the heap
int Heap::getMax() const {
    if (count == 0)
        return -1;
    return heaparray[0];
}


// @brief default constructor. Construct an empty heap with initial capacity
Heap::Heap(int size) {
    capacity = size;
    heaparray = new int[size];
    count = 0;
}

// @brief destructor
Heap::~Heap() {
    delete[] heaparray;
}

/**
 * @brief constructor to build a heap from an array of values
 * @param values array of values to be added to the heap
 * @param length the size of the array
 */
Heap::Heap(int *values, int length) {
    this->capacity = length;
    this->heaparray = values;
    this->count = length;
}

/**
 * @brief Copy constructor to build a heap from another heap
 * @param the heap to be copied
 */
Heap::Heap(const Heap& heap) {
    capacity = heap.capacity;
    for (int i = 1; i <= heap.count; i++)
    {
        heaparray[i - 1] = heap.heaparray[i - 1];
    }
    count = heap.count;
}

/**
  * @brief assignment operator to set one heap to another
  * @param the heap that you want to set your heap to
  */
Heap& Heap::operator = (const Heap& heap)
{
    if (this != &heap)
    {
        capacity = heap.capacity;
        for (int i = 1; i <= heap.count; i++)
        {
            heaparray[i - 1] = heap.heaparray[i - 1];
        }
        count = heap.count;
    }
    return *this;
}
  
/**
 * @brief   organizes the values in the heap to satisfy heap property.
 */
void Heap::heapify() {
    // Organize the heap values by percolating through the heap
  //starting from the last non leaf node, percolates down each value until root is reached
  for(int i = (count/2)-1; i >= 0; i--){
    percolateDown(i);
  }
}

/**
 * @brief  Runs percolate down on the heap for the node stored in index.
 */
void Heap::percolateDown(int index) {
    //check the values at index in the heap and decide whether they need to be swapped.
    // Run recursively until the current node is bigger than its children

  //sets local variables left,right to the index of the left and right child
  int left = leftChild(index);
  int right = rightChild(index);

  //local varaible denoting the node which after searching will be bigger than its children
  int biggest = index;

  //checks first if the left index is within range
  //checks for biggest value on leftChild
  if(count > left && heaparray[index] < heaparray[left]){
    biggest = left;
  }

  //checks for biggest value on rightChild
  if(count > right && heaparray[index] < heaparray[right]){
    biggest = right;
  }

  //RECURSIVE CALL
  if(index != biggest){
    swap(biggest, index);
    percolateDown(biggest);
  }
}

/**
 * @brief  Runs percolate up on the heap for the node stored in index.
 */
void Heap::percolateUp( int index) {
  // check the value of the parents of index in the heap and swap them if they are smaller
    // run recursively until the current node is small than its parent
    int cur_parent = (index - 1) / 2;
    int new_parent = cur_parent;


  //BASE CASE
    if (index == 0) {
        return;
    }

  //recursively runs while the current node is greater than its parent
  if(heaparray[index] > heaparray[cur_parent]){
    swap(cur_parent, index);
    percolateUp(new_parent);
  }
}

/**
 * @brief inserts a value into the heap
 *
 */
void Heap::insert(int value) {
    // resize the Heap array if neccessary and insert the value into the heap.
    // percolate the Heap to rearange after the value is inserted

  //To large, resizes
  if (count == capacity) {
    capacity = capacity * 2 + 1;
  }

  //Empty
  else if (this->count == 0) {
    //inserts value into first position
    heaparray[0] = value;
    count++;
    return; 
  }

  //all other cases: simply uses percolate up to insert value in proper place
  else{
    //sets new element after the last element
    heaparray[count] = value;
    percolateUp(count);
    count++;
  }
}

/**
 * @brief  Removes the max value from the heap
 * @return the value that was removed
 */
int Heap::removeMax() {
    // remove the max value from the heap and then percolate the heap to rearrange values
  //other way would be to manually swap till max is in last position, then remove

  //local variable which will contain max value
  int max = -1; //starting at -1 for return value if error occurs

  //checks for empty list
  if (count == 0) {
    return max;
  }

  //checks for single element 
  else if (count == 1) {
    count--;
    return heaparray[0];
  }

  //all other cases
  else if (count > 1) {
    //sets max to last element
    max = heaparray[count-1];

    //used for switching
    int temp = 0;
    int parent = -1;
    int child;
    count = count-1;
    child = count;

    //based on the structure of heap in array form, even index means a right child and odd a left child
    while(parent != 0){
      //checks if right child, which is an even index
      if(child%2 == 0){
        parent = child/2-1;
      }

      //checks if left child, which is an odd index
      if(child%2 == 1){
        parent = child/2;
      }

      //switches the parent and max 
      temp = heaparray[parent];
      heaparray[parent] = max;
      max = temp;
      child = parent;
    }    
  }

  //re-heapifies to ensure heap properties are bing followed
  heapify();

  //returning the maximum value
  return max;
}

/**
 * @brief  Prints the values in the heap
 */
void Heap::printHeap() {
    int i;
    cout << "[ ";
    for (i = 0; i < count; i++)
        cout << heaparray[i] << " ";
    cout << "]\n";
}

/**
 * @brief  Prints the values in an array
 */
void printArray(int values[], int length) {
    int i;
    cout << "[ ";
    for (i = 0; i < length; i++) {
        cout << values[i] << " ";
    }
    cout << "]\n";
}

/**
 * @brief  Swaps the values in the heap at index1 and index2
 */
void Heap::swap(int index1, int index2) {
    int temp = heaparray[index1];
    heaparray[index1] = heaparray[index2];
    heaparray[index2] = temp;
}

/**
 * @brief  Sorts the values of an array by using the heap
 */
void Heap::heapSort(int values[], int length) {
    //Create a heap from the array and then remove them from the heap into the array in order 

  //clears out the heap, to make room for array elements that will be added
  while(count != 0){ 
    removeMax();
  }

  cout << "Array Before Sorting: \n";
  printArray(values, length);


  //inserting array values into heap
  for(int i = 0; i < length; i++){
    insert(values[i]);
  }
  
  //uses removeMax function to sort through and place largest value at the rear of the array
  for (int i = length - 1; i >= 0; i--) {
    values[i] = removeMax();
  }
  

  //returning sorted array
  cout << "Array After Sorting: \n";
  printArray(values, length);

}

/**
     * @brief Change the key of the element at position i to the new value.
     *        It maintains the heap property.
     * @param i the position of the element to be decreased
     * @param value the new value
     */
void Heap::changeKey(int i, int new_val) {
    if (i < capacity) {
        heaparray[i] = new_val;
        percolateDown(0);
    }
}