/*
 * routing.h
 *
 *  Created on: Apr 4, 2017
 *      Author: Deepika
 */

#ifndef ROUTING_H_
#define ROUTING_H_
#include "graph.h"
#include "heap.h"

using namespace std;

enum state{ unseen, inTree, fringe};

void dijkstra(vector<vector <Edge>>&, int, int);

void dijkstra_heaps(vector<vector <Edge>>&, int, int);

int find(vector<int>&, int);
void Union(vector<int>&, vector<int>&, int, int);
void kruskalMST(vector<vector <Edge>>&, vector<vector <int>>&);

#endif /* ROUTING_H_ */
