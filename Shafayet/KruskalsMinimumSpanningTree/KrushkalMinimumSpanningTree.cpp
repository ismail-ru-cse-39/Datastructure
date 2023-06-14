#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

#define SZ 100000+1

struct Edge{
	int u, v, w;
	bool operator<(const Edge& p) const {
		return w < p.w;
	}
};

vector<Edge>E;
int Parent[SZ];

int find(int p) {
	return (Parent[p] == p) ? p : find(Parent[p]);
}

int mst(int n) {
	sort(E.begin(), E.end());

	for(int i = 1; i <= n; i++) {
		Parent[i] = i;
	}

	int cnt = 0;
	int cost = 0;

	for(int i = 0; i < E.size(); i++) {
		int u = find(E[i].u);
		int v = find(E[i].v);

		if(u != v) {
			Parent[u] = v;
			cnt++;
			cost += E[i].w;

			if(cnt == n-1) {
				break;
			}
		}
	}

	return cost;
}

int main()
 {
 	freopen("in.txt", "r", stdin);

 	int n, m;
 	cin>>n>>m;

 	for(int i = 1; i <= m; i++) {
 		int u,v,w;
 		cin>>u>>v>>w;

 		Edge node;

 		node.u = u;
 		node.v = v;
 		node.w = w;

 		E.push_back(node);

 	}

 	int res = mst(n);

 	cout<<res<<endl;

 	return 0;
 }