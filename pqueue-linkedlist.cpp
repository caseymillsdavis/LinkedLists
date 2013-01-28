/*************************************************************
 * File: pqueue-linkedlist.cpp
 *
 * Implementation file for the LinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-linkedlist.h"
#include "error.h"

LinkedListPriorityQueue::LinkedListPriorityQueue() {
	head = NULL;
    qSize = 0;
}

LinkedListPriorityQueue::~LinkedListPriorityQueue() {
	while (head != NULL) {
		Cell* next = head->next;
		delete head;
		head = next;
	}
}

int LinkedListPriorityQueue::size() {
	return qSize;
}

bool LinkedListPriorityQueue::isEmpty() {
	return head == NULL;
}

void LinkedListPriorityQueue::enqueue(string value) {
    qSize++;
	Cell* cell = new Cell;
    cell->value = value;
    
    if (isEmpty()) {
        head = cell;
        cell->next = NULL;
        return;
    } 
    
    Cell* prev = NULL;
    Cell* curr;
    for (curr = head; curr != NULL; curr = curr->next) {
		if (cell->value < curr->value) {
            cell->next = curr;
            if (prev != NULL) {
                prev->next = cell;
            } else {
                head = cell;
            }
            return;
        }
        if (curr != NULL) prev = curr;
	}
    
    prev->next = cell;
    cell->next = NULL;
}

string LinkedListPriorityQueue::peek() {
	if (isEmpty()) {
        error("LinkedListPriorityQueue is empty. No peeking.");
    }
	
	return head->value;
}

string LinkedListPriorityQueue::dequeueMin() {
	if (isEmpty()) {
        error("LinkedListPriorityQueue is empty. No dequeuing.");
    }
    
    Cell* result = head;
    head = head->next;
    string value = result->value;
    delete result;
    qSize--;
    return value;
}

