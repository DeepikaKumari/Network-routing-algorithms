/*
 * routing.cpp
 *
 *  Created on: Apr 4, 2017
 *      Author: Deepika
 */
#include "routing.h"
#include <climits>
#include <ctime>

using namespace std;

void dijkstra(vector<vector <Edge>>& G, int s, int t){

	int n = G.size();
	vector<state> status(n);
	vector<int> Dad(n);
	vector<int> bw(n);
	vector<int> fringes;

	for(int i=0; i<n; i++)
		status[i] = unseen;

	status[s] = inTree;
	Dad[s] = -1;
	bw[s] = INT_MAX;

	for(int i=0; i<G[s].size(); i++){

		int w = G[s][i].neighbor-1;
		bw[w] = G[s][i].weight;
		status[w] = fringe;
		fringes.push_back(w);
		Dad[w] = s+1;
	}

	while(fringes.size()!=0){

		//select max bandwidth fringe
		int v = fringes[0];
		int maxBW = bw[v];
		int index = 0;
		for(int i=1; i<fringes.size(); i++){
			if(bw[fringes[i]] > maxBW){
				maxBW = bw[fringes[i]];
				v = fringes[i];
				index = i;
			}
		}
		status[v] = inTree;
		fringes.erase(fringes.begin()+index);
		for(int i=0; i<G[v].size(); i++){
			int w = G[v][i].neighbor - 1;
			int min_bw_wt = (bw[v] < G[v][i].weight)? bw[v] : G[v][i].weight;
			if(status[w]==unseen){
				status[w] = fringe;
				fringes.push_back(w);
				bw[w] = min_bw_wt;
				Dad[w] = v+1;
			}
			else if((status[w]==fringe)&&(bw[w]<min_bw_wt)){
				bw[w]=min_bw_wt;
				Dad[w] = v+1;
			}
		}
	}

	int dest = t;
	while(dest>=0){
		cout << dest+1 << "<-";
		dest = Dad[dest]-1;
	}
	cout << endl;
}

void dijkstra_heaps(vector<vector <Edge>>& G, int s, int t){

	int n = G.size();
	vector<state> status(n);
	vector<int> Dad(n);
	vector<int> bw(n);
	vector<int> fringe_nodes;

	for(int i=0; i<n; i++){
		status[i] = unseen;
	}

	status[s] = inTree;
	Dad[s] = -1;
	bw[s] = INT_MAX;

	for(int i=0; i<G[s].size(); i++){

		int w = G[s][i].neighbor-1;
		bw[w] = G[s][i].weight;
		status[w] = fringe;
		fringe_nodes.push_back(w+1);
		Dad[w] = s+1;
	}

	Heap fringes(fringe_nodes,&bw);
	fringes.build_heap();

	while(fringes.heap_size!=0){

		//select max bandwidth fringe
		int v = fringes.maximum()-1;
		int maxBW = bw[v];
		status[v] = inTree;

		fringes.delete_element(0);

		for(int i=0; i<G[v].size(); i++){
			int w = G[v][i].neighbor - 1;
			int min_bw_wt = (bw[v] < G[v][i].weight)? bw[v] : G[v][i].weight;
			if(status[w]==unseen){
				status[w] = fringe;
				bw[w] = min_bw_wt;
				fringes.insert(w+1,bw[w]);
				Dad[w] = v+1;
			}
			else if((status[w]==fringe)&&(bw[w]<min_bw_wt)){
				bw[w]=min_bw_wt;
				Dad[w] = v+1;
				fringes.changeValue(w+1, bw[w]);
			}
		}
	}
	int dest = t;
	while(dest>=0){
		cout << dest+1 << "<-";
		dest = Dad[dest]-1;
	}
	cout << endl;
}

int find(vector<int>& D, int v){
	int w = v;
	vector<int> S;
	while(D[w]!=0){
		S.push_back(w);
		w = D[w];
	}
	while(S.size()!=0){
		int u = S.back();
		S.pop_back();
		D[u] = w;
	}
	return w;
}
void Union(vector<int>& D, vector<int>& rank, int r1, int r2){
	if(rank[r1]>rank[r2]){
		D[r2]=r1;
	}
	else if(rank[r1]<rank[r2]){
		D[r1] = r2;
	}
	else{
		D[r2] = r1;
		rank[r1]++;
	}
}
void kruskalMST(vector<vector <Edge>>& G, vector<vector <int>>& T){
	T.clear();
	int n = G.size();
	vector<int> edge_weights;
	vector<int> edge_names;
	vector<int> nextIndex(n);
	vector<vector <int>> edge_set;
	vector<int> D(n);
	vector<int> rank(n);

	for(int i=0; i<n; i++){
		nextIndex[i] = 0;
		D[i] = 0;
		rank[i] = 0;
	}
	int count = 0;

	for(int i = 0; i < n; i++){
		for(int j=nextIndex[i]; j<G[i].size(); j++){
			int w = G[i][j].neighbor;
			edge_set.push_back({i+1,w});
			edge_weights.push_back(G[i][j].weight);
			nextIndex[w]++;
			count++;
			edge_names.push_back(count);
		}
	}

	Heap edges(edge_names, &edge_weights);
	edges.build_heap();
	//sort the edges increasingly
	vector<int> sorted_edges = edges.HeapSort();
	for(int i = sorted_edges.size()-1; i>=0; i--){
		int u = edge_set[edge_names[i]-1][0];
		int v = edge_set[edge_names[i]-1][1];
		int r1 = find(D, u-1);
		int r2 = find(D, v-1);
		if(r1!=r2){
			T.push_back({u,v});
			Union(D, rank, r1,r2);
		}
	}
}

