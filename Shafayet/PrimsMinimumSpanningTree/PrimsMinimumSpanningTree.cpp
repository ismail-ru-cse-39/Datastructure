#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define SZ 10000+10
typedef pair<int, int> iPair;

vector<pair<int, int> > Adj[SZ];
int N;
int inf = 10000000;

void addEdge(int u, int v, int w) {
	Adj[u].push_back(make_pair(v, w));
	Adj[v].push_back(make_pair(u, w));
}

void printPMST(vector<int> parent) {

	for(int i = 1; i < N; i++) {
		cout<< parent[i] <<" - "<<i<<" "<<Adj[parent[i]][i].second<<endl;
	}
}

void primMST() {

	priority_queue<iPair, vector<iPair>, greater<iPair> > pq;

	int src = 0;
	vector<int> distance(N, inf);
	vector<int>parent(N, -1);
	vector<int>visitedMST(N, false);

	pq.push(make_pair(0, src));
	distance[src] = 0;


	while(!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		if(visitedMST[u]) {
			continue;
		}

		visitedMST[u] = true;

		for(auto v : Adj[u]) {
			int vv = v.first;
			int w = v.second;

			if(visitedMST[vv] == false && distance[vv] > w) {
				distance[vv] = w;
				pq.push(make_pair(distance[vv], vv));
				parent[vv] = u;
			}
		}

	}

	printPMST(parent);

}

int main()
{

	N = 9;

	addEdge(0, 1, 4);
	addEdge(0, 7, 8);
	addEdge(1, 2, 8);
	addEdge(1, 7, 11);
	addEdge(2, 3, 7);
	addEdge(2, 8, 2);
	addEdge(2, 5, 4);
	addEdge(3, 4, 9);
	addEdge(3, 5, 14);
	addEdge(4, 5, 10);
	addEdge(5, 6, 2);
	addEdge(6, 7, 1);
	addEdge(6, 8, 6);
	addEdge(7, 8, 7);
	
	primMST();

	return 0;
}