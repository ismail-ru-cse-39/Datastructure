#include<iostream>
#include<vector>
using namespace std;

#define SZ 1000

//Largest number, larger then total sum
int infinity = 100000;

vector<vector<int> > Adj;
vector<vector<int> > Path; // for storing the path

void init()
{
	Adj.resize(SZ, vector<int> (SZ));
	Path.resize(SZ, vector<int> (SZ));

	//initialise the adj
	for(int i = 0; i < SZ; i++) {
		for(int j = 0; j < SZ; j++) {
			if(i == j) {
				Adj[i][j] = 0;
			} else {
				Adj[i][j] = infinity;
			}

			Path[i][j] = j;
		}
	}
}

void floyadWarshall(int v) {
	for(int k = 1; k <= v; k++) {
		for(int i = 1; i <= v; i++) {
			for(int j = 1; j <= v; j++) {
				if(Adj[i][k] + Adj[k][j] < Adj[i][j]) {
					Adj[i][j] = Adj[i][k] + Adj[k][j];
					Path[i][j] = Path[i][k];
				}
			}
		}
	}
}




vector<int> findPath(int i, int j) {
	vector<int>vpath;
	vpath.push_back(i);
	while(i != j) {
		i = Path[i][j];
		vpath.push_back(i);
	}

	return vpath;
}




int main()
{
	init();
	
	freopen("in.txt", "r", stdin);

	int vertex;
	cin>>vertex;

	int edge;
	cin>>edge;

	while(edge--) {
		int u, v, w;
		cin>>u>>v>>w;
		Adj[u][v] = w;
	}

	floyadWarshall(vertex);

	int query;
	cin>>query;

	while(query--) {
		int i, j;

		cin>>i>>j;

		cout<<"Cost: "<<Adj[i][j]<<endl;
		vector<int>path = findPath(i, j);

		cout<<"Path: "<<endl;

		for(int i = 0; i < path.size(); i++) {
			cout<<path[i];
			if(i != path.size()-1) {
				cout<<"->";
			}
		}

		cout<<endl;
	}
}