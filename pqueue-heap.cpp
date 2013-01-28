/*************************************************************
 * File: pqueue-heap.cpp
 *
 * Implementation file for the HeapPriorityQueue
 * class.
 */
 
#include "pqueue-heap.h"
#include "error.h"

const string DUMMY_VALUE = "dummy";
const int START_SIZE = 4;
const int PARENT_CHILD_MULT = 2;

HeapPriorityQueue::HeapPriorityQueue() {
	elems = new string[START_SIZE];
    allocatedLength = START_SIZE;
    elems[0] = DUMMY_VALUE;
    logicalLength = 0;
}

HeapPriorityQueue::~HeapPriorityQueue() {
	delete[] elems;
}

int HeapPriorityQueue::size() {
	return logicalLength;
}

bool HeapPriorityQueue::isEmpty() {
	return size() == 0;
}

void HeapPriorityQueue::enqueue(string value) {
    logicalLength++;
    if ((size()) == allocatedLength) {
		grow();
	}
    elems[size()] = value;
    bubbleUp(size());
}

string HeapPriorityQueue::peek() {
    if (isEmpty()) {
		error("HeapPriorityQueue is empty. No peeking.");
	}
	return elems[1];
}

string HeapPriorityQueue::dequeueMin() {
	if (isEmpty()) {
		error("HeapPriorityQueue is empty. No dequeuing.");
	}
	string returnStr = elems[1];
    elems[1] = elems[size()];
    logicalLength--;
    bubbleDown(1);
    return returnStr;
}


/* helper function: bubbleUp(int index)
 *
 * lexicographically repairs the heap
 * by swapping elements with their parents
 */
void HeapPriorityQueue::bubbleUp(int index) {
    int parentIndex = index / PARENT_CHILD_MULT;
    if (parentIndex == 0) return;
    if (elems[index] < elems[parentIndex]) {
        swap(index, parentIndex);
        bubbleUp(parentIndex);
    }
}

/* helper function: bubbleDown(int index)
 *
 * lexicographically repairs the heap
 * by swapping elements with their children
 */
void HeapPriorityQueue::bubbleDown(int index) {
    int childIndex1 = PARENT_CHILD_MULT*index;
    int childIndex2 = PARENT_CHILD_MULT*index + 1;
    bool has1Child = size() == childIndex1;
    bool has2Children = size() >= childIndex2;
    if (has2Children) {
        if (elems[childIndex1] < elems[childIndex2] &&
            elems[index] > elems[childIndex1]) {
            swap(index, childIndex1);
            bubbleDown(childIndex1);
        } else if (elems[index] > elems[childIndex2]) {
            swap(index, childIndex2);
            bubbleDown(childIndex2);
        }
    }else if (has1Child && 
              elems[index] > elems[childIndex1]) {
        swap(index, childIndex1);
    }
}


/* helper function: swap(int index1, int index2)
 */
void HeapPriorityQueue::swap(int index1, int index2){
    string tempStr = elems[index1];
    elems[index1] = elems[index2];
    elems[index2] = tempStr;
}


/* helper function: grow()
 *
 * allocates more space for the underlying array
 * does so by allocating an array with twice
 * the space, copying the elements over, and
 * deleting the old array
 */
void HeapPriorityQueue::grow() {
	allocatedLength *= 2;
	string* newElems = new string[allocatedLength];
	for (int i = 0; i < size(); i++) {
		newElems[i] = elems[i];
	}
	delete[] elems;
	elems = newElems;
}

