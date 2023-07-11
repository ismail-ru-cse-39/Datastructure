#include<iostream>
#include<vector>
#include<stack>

using namespace std;
#define SZ 2000+10

vector<int>Adj[SZ];
stack<int>Stk;
int Visited[SZ];
int VisitedCnt;


void init() {
	for(int i = 0; i < SZ; i++) {
		Adj[i].clear();
		Visited[i] = 0;
	}

	Stk = stack<int>();

	VisitedCnt = 0;
}

void print() {

	while(!Stk.empty()) {
		cout<<Stk.top()<<" ";
		Stk.pop();
	}

	cout<<endl;
}

void DFS(int u) {
	Visited[u] = VisitedCnt;

	for(auto v : Adj[u]) {
		if(Visited[v] != VisitedCnt) {
			DFS(v);
		}
	}

	Stk.push(u);
}

void topologicalSort(int n) {
	Stk = stack<int>();
	VisitedCnt += 1;

	for(int i = 0; i < n; i++) {
		if(Visited[i] != VisitedCnt) {
			DFS(i);
		}
	}

	print();
}

int main()
{
	init();

	freopen("in.txt", "r", stdin);

	int n, e;

	cin>>n;
	cin>>e;

	for(int i =0 ; i < e; i++) {
		int u, v;
		cin>>u>>v;
		Adj[u].push_back(v);
	}

	topologicalSort(n);
}