/*
 * heap.cpp
 *
 *  Created on: Apr 4, 2017
 *      Author: Deepika
 */
#include "heap.h"

using namespace std;

Heap::Heap(vector<int> names, vector<int>* values){

	int numKeys=(*values).size();
	heap_size=names.size();
	for(int i=0; i<heap_size; i++)
		H.push_back(names[i]);

	for(int i=0; i<numKeys; i++)
		D.push_back(values->at(i));

}

int Heap::left_child(int i){
	if(2*i+1 < heap_size){
		return 2*i + 1;
	}
	else return -1;
}

int Heap::right_child(int i){
	if(2*(i+1) < heap_size){
		return 2*(i + 1);
	}
	else return -1;
}

int Heap::parent(int i){
	return (i-1)>>1;
}

int Heap::maximum(){
	return H[0];
}

void Heap::max_heapify(int i){
	int l = left_child(i);
	int r = right_child(i);

	int lchild = H[l];
	int rchild = H[r];
	int max;

	if((!(l==-1)) && (D[lchild-1] > D[H[i]-1]))
		max = l;
	else max = i;
	if((!(r==-1)) && (D[rchild-1] > D[H[max]-1]))
		max = r;

	if(!(max==i)){
		int temp = H[max];
		H[max] = H[i];
		H[i] = temp;
		max_heapify(max);
	}
}

void Heap::build_heap(){
	for(int i=(heap_size>>1); i>=1; i--)
		max_heapify(i-1);
}

void Heap::insert(int name, int key){
	D.push_back(key);
	heap_size++;
	H.push_back(name);
	int i = heap_size-1;
	int parent_i = parent(i);

	while((i>=1)&&(D[H[parent_i]-1] < D[H[i]-1])){
		int temp = H[parent_i];
		H[parent_i] = H[i];
		H[i] = temp;
		i = parent_i;
		parent_i = parent(i);
	}
}

void Heap::delete_element(int index){
	//index in H
	H[index]=H.back();
	H.pop_back();
	heap_size--;
	int i = index;
	int parent_i = parent(index);

	if(i>=1){
	if(D.at(H[i]-1) > D.at(H[parent_i]-1)){
		while((i>=1)&&(D.at(H[i]-1) > D.at(H[parent_i]-1))){
			int temp = H[parent_i];
			H[parent_i] = H[i];
			H[i] = temp;
			i = parent_i;
			parent_i = parent(i);
		}
	}
	}
	else
		max_heapify(i);
}

void Heap::print_heap(){
	for (int i=0; i<heap_size; i++){
		cout << D[H[i]-1] << "  ";
	}
	cout << endl;
}

void Heap::changeValue(int name, int newVal){
	D[name-1] = newVal;
	build_heap();
}

vector<int> Heap::HeapSort(){
	vector<int> sortedArr;
	while(heap_size!=0){
		sortedArr.push_back(H[0]);
		delete_element(0);
	}
	return sortedArr;
}


