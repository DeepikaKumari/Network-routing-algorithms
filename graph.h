/*
 * graph.h
 *
 *  Created on: Apr 4, 2017
 *      Author: Deepika
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include "heap.h"

using namespace std;

struct Edge{
	int neighbor;	//node - integer between 1 and n
	int weight;	//integer between 1 and 100
};

bool contains(vector<int>, int);

void buildGraph_type1(vector< vector <Edge> >&, int, int);

void buildGraph_type2(vector< vector <Edge> >&, int, double);

void printGraph(vector< vector <Edge> >&);

void addPath(vector<vector <Edge>>&, int, int);

#endif /* GRAPH_H_ */
