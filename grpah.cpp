/*
 * grpah.cpp
 *
 *  Created on: Apr 4, 2017
 *      Author: Deepika
 */

#include "graph.h"
#include <random>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

bool contains(vector<int> listIn, int num){
	unsigned int i;
    for (i=0; i<listIn.size(); i++){
    	if(listIn[i]==num)
    	            return true;
    }
    return false;
}

void buildGraph_type1(vector< vector <Edge> >& G, int n, int d){

	int max_wt = 100;
	int i, j, k, r, wt;
	G.clear();
	for(i=0; i<n; i++)
		G.push_back(vector <Edge>());

	srand(time(NULL));
	vector<int> nextIndex(n);
	vector<int> randNumList;

	for(int i=0; i<n; i++)
		nextIndex[i] = 0;

	for(i=0; i<n-1; i++){
		randNumList.clear();
		for(k=nextIndex[i]; k<d; k++){
			//pick random number between i+1 and n-1
			r=(rand() % (n-i-1)) + i + 1;
			int count=0;
			while(contains(randNumList,r)||(nextIndex[r]==d)){
				//pick random number between i+1 and n-1
				r=(rand() % (n-i-1)) + i + 1;
				if(count==10){
					break;
				}
				count++;
			 }

			if(count<10){
				randNumList.push_back(r);
				wt = rand() % max_wt + 1;

				Edge newEdge = {r+1, wt};

				Edge revEdge = {i+1, wt};

				G[i].push_back(newEdge);

				G[r].push_back(revEdge);
				nextIndex[r]++;
				nextIndex[i]++;
			}

		}
	}
	/* if a node does not yet have full degree, do:
	look for another node which is deficient,
	add edge between the two. Repeat till all nodes have degree d.*/
	i = 0;
	j = n-1;
	while(!(i>=j)){
		if(nextIndex[i]<d){
			if(nextIndex[j]<d){
				wt = rand() % max_wt + 1;
				Edge newEdge = {j+1, wt};
				G[i].push_back(newEdge);
				Edge revEdge = {i+1, wt};
				G[j].push_back(revEdge);
				nextIndex[i]++;
				nextIndex[j]++;
			}
			else
				j--;
		}
		else if(nextIndex[j]<d)
			i++;
		else{
			i++;
			j--;
		}
	}
}

void buildGraph_type2(vector< vector <Edge> >& G, int n, double p){
	int i, j, wt;
	int max_wt = 100;
	G.clear();
	for(i=0; i<n; i++)
		G.push_back(vector <Edge>());

	srand(time(NULL));

	default_random_engine generator;
	bernoulli_distribution place_edge(p);

	for(i=0; i<n; i++){
		for(j = i+1; j< n; j++){
			if(place_edge(generator)){

				wt = rand() % max_wt + 1;
				Edge newEdge = {j+1, wt};
				Edge revEdge = {i+1, wt};
				G[i].push_back(newEdge);
				G[j].push_back(revEdge);
			}
		}
	}

}

void printGraph(vector< vector <Edge> >& G){
	int n = G.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<G[i].size();j++){
			cout << G[i][j].neighbor << '(' << G[i][j].weight  << ')' << ",";
		}
		cout << endl;
	}
}

void addPath(vector<vector <Edge>>& G, int s, int t){
	int n = G.size();
	int maxwt = 100;
	int u, v;
	srand(time(NULL));
	vector<int> edges_from;
	vector<int> path_nodes;
	for(int i = 0 ; i < n; i++){
		if((i!=s)&&(i!=t))
			path_nodes.push_back(i);
	}
	random_shuffle(path_nodes.begin(),path_nodes.end());

	for(int i=0; i<G[s].size();i++){
		edges_from.push_back(G[s][i].neighbor-1);
	}

	if(!contains(edges_from,path_nodes[0])){
		int w =rand()%maxwt + 1;
		G[s].push_back({path_nodes[0]+1,w});
		G[path_nodes[0]].push_back({s+1,w});
	}

	for(int i = 0; i< path_nodes.size()-1; i++){
		u = path_nodes[i];
		v = path_nodes[i+1];
		edges_from.clear();
		for(int j = 0; j< G[u].size(); j++)
			edges_from.push_back(G[u][j].neighbor-1);

		if(!contains(edges_from, v)){
			int wt = rand()%maxwt + 1;

			Edge newEdge = {v+1, wt};
			Edge revEdge = {u+1 , wt};
			G[u].push_back(newEdge);
			G[v].push_back(revEdge);
		}

	}
	edges_from.clear();
	for(int i=0; i<G[v].size();i++){
		edges_from.push_back(G[v][i].neighbor-1);
	}
	if(!contains(edges_from, t)){
		int w =rand()%maxwt + 1;
		G[t].push_back({v+1,w});
		G[v].push_back({t+1,w});
	}

}
