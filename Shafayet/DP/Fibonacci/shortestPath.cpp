#include<iostream>
#include<vector>

using namespace std;

class ShortestPath {
	int SZ = 1000;
	int INF = 1001;
	vector<int>minD(1000, 1001);
	vector<vector<int>>adj(SZ, vector<int>(SZ, INF));

	int path(int u, int n) {
		if(u == n-1) {
			return 0;
		}
		if(minD[u] != INF) {
			return minD[u];
		}

		int ans = INF;

		for(auto v : adj[u]) {
			if(adj[u][v] != INF) {
				ans = min(ans, path(v, n) + adj[u][v]);
			}
		}

		minD[u] = ans;
		return minD[u];
	}
};

int main() {
	int n, m;
	cin>>n>>m;

	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin>>u>>v>>w;
		adj[u][v].push_back(w);
	}

	ShortestPath sp;

	cout<<sp.path(0, n)<<endl;

	return 0;
}