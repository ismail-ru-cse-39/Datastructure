#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define SZ 100000

struct Node {
	int u, cost;

	Node(int _u, int _cost) {
		u = _u;
		cost = _cost;
	}
};

struct Cmp {
	bool operator()(const Node& a, const Node& b) const {
		return a.cost > b.cost;
	}
};

vector<pair<int, int> > Adj[SZ];
int N;

void print(int u, vector<int> d) {
	cout<<"distance from: "<<u<<endl;

	for(auto v: d) {
		cout<<v<<" ";
	}

	cout<<endl;
}

void dijkstra(int u) {
	priority_queue<Node, vector<Node>, Cmp>pq;
	int infinity = INT_MAX;
	vector<int>distance(N, infinity);

	distance[u] = 0;
	pq.push(Node(u, 0));

	while(!pq.empty()) {
		Node n = pq.top();
		pq.pop();

		int uu = n.u;

		for(auto v : Adj[uu]) {
			if(distance[uu] + v.second < distance[v.first]) {
				distance[v.first] = distance[uu] + v.second;
				pq.push(Node(v.first, distance[v.first]));
			}
		}
	}

	print(u, distance);
}

void addEdge(int u, int v, int w) {
	Adj[u].push_back(make_pair(v, w));
	Adj[v].push_back(make_pair(u, w));
}

int main ()
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

    dijkstra(0);

    return 0;

}