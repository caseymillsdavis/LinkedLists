/**********************************************
 * File: pqueue-heap.h
 *
 * A priority queue class backed by a binary
 * heap.
 */
#ifndef PQueue_Heap_Included
#define PQueue_Heap_Included

#include <string>
using namespace std;

/* A class representing a priority queue backed by an
 * binary heap.
 */
class HeapPriorityQueue {
public:
	/* Constructs a new, empty priority queue backed by a binary heap. */
	HeapPriorityQueue();
	
	/* Cleans up all memory allocated by this priority queue. */
	~HeapPriorityQueue();
	
	/* Returns the number of elements in the priority queue. */
	int size();
	
	/* Returns whether or not the priority queue is empty. */
	bool isEmpty();
	
	/* Enqueues a new string into the priority queue. */
	void enqueue(string value);
	
	/* Returns, but does not remove, the lexicographically first string in the
	 * priority queue.
	 */
	string peek();
	
	/* Returns and removes the lexicographically first string in the
	 * priority queue.
	 */
	string dequeueMin();

private:
	// TODO: Fill this in with the implementation of your binary heap
	// priority queue.  You can add any fields, types, or methods that you
	// wish.
	//
	// While you are free to implement this as you see fit, you *must* do
	// all of your own memory management and should not use the Vector.
    
    string* elems;                      // Pointer to elements array
	int logicalLength;                  // How much space is used
	int allocatedLength;                // How much space is available
	
	void grow();                    // Grows the array to increase space.
    void bubbleUp(int index);       // Swap up until lexicographically valid
    void bubbleDown(int index);     // Swap down until lexicographically valid
    void swap(int index1, int index2);  // Swap elements
        
};

#endif
