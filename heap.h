/*
 * heap.h
 *
 *  Created on: Apr 4, 2017
 *      Author: Deepika
 */

#ifndef HEAP_H_
#define HEAP_H_

#include <iostream>
#include <vector>

using namespace std;

class Heap{
private:
	vector<int> H;
	vector<int> D;
	int left_child(int);
	int right_child(int);
	int parent(int);
	void max_heapify(int);

public:
	Heap(vector<int>,vector<int>*);
	int maximum();
	void insert(int,int);	//insert an element of given value;
	void delete_element(int); //delete element at given index in heap
	void changeValue(int, int); //change value of given node in heap to new value
	void build_heap();
	vector<int> HeapSort();
	int heap_size;
	void print_heap();

};
void swap(int* , int*);

#endif /* HEAP_H_ */
