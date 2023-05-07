#include<iostream>

using namespace std;

#define SZ 100000+22

int Parent[SZ];
int Level[SZ];
int SparseTable[SZ][22];
vector<int>Adj[SZ];

void dfs(int from, int u, int dep) {
	Parent[u] = from;
	Level[u] = dep;

	for(auto v : Adj[u]) {
		if(v == from) {
			continue;
		}
		dfs(u, v, dep + 1);
	}
}

void initLCA(int N) {
	memset(SparseTable, -1, sizeof(SparseTable));

	for(int i = 0; i < N; i++) {
		SparseTable[i][0] = Parent[i];
	}

	for(int j = 1; 1<<j < N; j++) {
		for(int i = 0; i < N; i++) {
			if(SparseTable[i][j-1] != -1) {
				SparseTable[i][j] = SparseTable[SparseTable[i][j-1]][j-1];
			}
		}
	}
}

int LCAQuery(int N, int p, int q) {

	if(Level[p] < Level[q]) {
		swap(p,q);
	}

	int log = 1;

	while(true) {
		int next = log + 1;

		if(1 << next > Level[p]) {
			break;
		}
		log++;
	}

	for(int i = log; i >= 0; i--) {
		if(Level[p] - (1<<i) >= Level[q]) {
			p = SparseTable[p][i];
		}
	}

	if(p == q) {
		return p;
	}

	for(int i = log; i >= 0; i--) {
		if(SparseTable[p][i] != -1 && SparseTable[p][i] != SparseTable[q][i]) {
			p = SparseTable[p][i];
			q = SparseTable[q][i];
		}
	}

	return Parent[p];
}

int main() {
	Adj[0].push_back(1);
	Adj[0].push_back(2);
	Adj[2].push_back(3);
	Adj[2].push_back(4);

	dfs(0, 0, 0);
	initLCA(5);

	cout<<LCAQuery(5, 3, 4)<<endl;

	return 0;
}