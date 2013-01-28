/*************************************************************
 * File: pqueue-vector.cpp
 *
 * Implementation file for the VectorPriorityQueue
 * class.
 */
 
#include "pqueue-vector.h"
#include "error.h"

VectorPriorityQueue::VectorPriorityQueue() {
}

VectorPriorityQueue::~VectorPriorityQueue() {
	qVec.clear();
}

int VectorPriorityQueue::size() {
	return qVec.size();
}

bool VectorPriorityQueue::isEmpty() {
	return qVec.isEmpty();
}

void VectorPriorityQueue::enqueue(string value) {
	qVec.push_back(value);
}

string VectorPriorityQueue::peek() {
    if (isEmpty()) {
        error("VectorPriorityQueue is empty. No peeking.");
    }
    
	string firstString = qVec.get(0);
    int indexCount = 0;
    firstIndex = 0;
    foreach(string str in qVec){
        if (str < firstString) {
            firstIndex = indexCount;
            firstString = str;
        }
        indexCount++;
    }
	return firstString;
    
}

string VectorPriorityQueue::dequeueMin() {
    if (isEmpty()) {
        error("VectorPriorityQueue is empty. No dequeuing.");
    }
    
	string strTemp = peek();
    qVec.removeAt(firstIndex);
	return strTemp;
}

