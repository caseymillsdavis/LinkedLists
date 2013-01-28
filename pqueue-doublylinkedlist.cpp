/*************************************************************
 * File: pqueue-doublylinkedlist.cpp
 *
 * Implementation file for the DoublyLinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-doublylinkedlist.h"
#include "error.h"
#include <iostream>

DoublyLinkedListPriorityQueue::DoublyLinkedListPriorityQueue() {
	head = NULL;
    minCell = NULL;
    qSize = 0;    
}

DoublyLinkedListPriorityQueue::~DoublyLinkedListPriorityQueue() {
	while (head != NULL) {
		Cell* next = head->next;
		delete head;
		head = next;
	}
}

int DoublyLinkedListPriorityQueue::size() {
	return qSize;
}

bool DoublyLinkedListPriorityQueue::isEmpty() {
	return head == NULL;
}

void DoublyLinkedListPriorityQueue::enqueue(string value) {
    qSize++;
	Cell* cell = new Cell;
    cell->value = value;
    cell->next = head;
    cell->prev = NULL;
    if (head != NULL) {
        head->prev = cell;
    }
    head = cell;
}

string DoublyLinkedListPriorityQueue::peek() {
	if (isEmpty()) {
        error("DoublyLinkedListPriorityQueue is empty. No peeking.");
    }
    
    minCell = head;
    for (Cell* curr = head; curr != NULL; curr = curr->next) {
        if (curr->next == NULL) {
            return minCell->value;
        } 
        if (curr->next->value < minCell->value) {
            minCell = curr->next;
        }
    }
}

string DoublyLinkedListPriorityQueue::dequeueMin() {
	if (isEmpty()) {
        error("DoublyLinkedListPriorityQueue is empty. No dequeuing.");
    }
	
    qSize--;
    string result = peek();
    
    if ((minCell->prev != NULL) && (minCell->next != NULL)) {
        minCell->prev->next = minCell->next;
        minCell->next->prev = minCell->prev;
    } else if ((minCell->prev == NULL) && (minCell->next != NULL)) {
        minCell->next->prev = NULL;
        head = minCell->next;
    } else if ((minCell->prev != NULL) && (minCell->next == NULL)) {
        minCell->prev->next = NULL;
    } else {
        head = NULL;
    }
    delete minCell;
    return result;
}

