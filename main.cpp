/*
 * main.cpp
 *
 *  Created on: Apr 4, 2017
 *      Author: Deepika
 */
#include "heap.h"
#include"graph.h"
#include "routing.h"
#include <ctime>

using namespace std;

int main(){
	int numNodes = 5000;
	int degree = 6;
	vector<vector <Edge>> G1;
	vector<vector <Edge>> G2;
	vector<vector <int>> MST;

	double edge_prob = 0.2;
	srand(time(NULL));

	cout << "Graph type 1" << endl;
		for(int i=0; i<5; i++){
			cout << "graph number" << i+1 << endl;
			buildGraph_type1(G1, numNodes, edge_prob);
			for(int j =0; j<5; j++){
				int s = rand() % numNodes;
				int t = rand() % numNodes;
				while(s==t)
					int t = rand() % numNodes;
				cout << "Finding path: " << '(' << s+1 << ',' << t+1 << ')' <<endl;
				addPath(G1, s, t);
				clock_t t1 = clock();
				cout << "Dijkstra's algorithm without heaps" << endl;
				dijkstra(G1, s, t);
				clock_t t2 = clock();
				cout << "Time :" << (t2-t1)/double(CLOCKS_PER_SEC) << endl;

				clock_t t3 = clock();
				cout << "Dijkstra's algorithm using heaps" << endl;
				dijkstra_heaps(G1, s, t);
				clock_t t4 = clock();
				cout << "Time :" << (t4-t3)/double(CLOCKS_PER_SEC) << endl;

				/*t1 = clock();
				cout << "Kruskal's Maximum Spanning Tree" << endl;
				kruskalMST(G1, MST);
				t2 = clock();
				cout << "Time :" << (t2-t1)/double(CLOCKS_PER_SEC) << endl;*/
			}
		}

	cout << "Graph type 2" << endl;
	for(int i=0; i<5; i++){
		cout << "graph number" << i+1 << endl;
		buildGraph_type2(G2, numNodes, edge_prob);
		for(int j =0; j<5; j++){
			int s = rand() % numNodes;
			int t = rand() % numNodes;
			while(s==t)
				int t = rand() % numNodes;
			cout << "Finding path: " << '(' << s+1 << ',' << t+1 << ')' <<endl;
			addPath(G2, s, t);
			clock_t t1 = clock();
			cout << "Dijkstra's algorithm without heaps" << endl;
			dijkstra(G2, s, t);
			clock_t t2 = clock();
			cout << "Time :" << (t2-t1)/double(CLOCKS_PER_SEC) << endl;

			clock_t t3 = clock();
			cout << "Dijkstra's algorithm using heaps" << endl;
			dijkstra_heaps(G2, s, t);
			clock_t t4 = clock();
			cout << "Time :" << (t4-t3)/double(CLOCKS_PER_SEC) << endl;

			/*t1 = clock();
			cout << "Kruskal's Maximum Spanning Tree" << endl;
			kruskalMST(G2, MST);
			t2 = clock();
			cout << "Time :" << (t2-t1)/double(CLOCKS_PER_SEC) << endl;*/
		}
	}


	return 0;
}
