#include<iostream>
#include<vector>

#define INF 99999
#define Empty -1
#define SZ 2000

using namespace std;


int Mem[SZ][SZ];


int coinChange(int i, int n, int w, vector<int>& coin) {
	if(i >= n) return INF;

	if(i == n-1) {
		if(w == 0) return 0;
		return INF;
	}

	if(Mem[i][w] != Empty) {
		return Mem[i][w];
	}

	Mem[i][w] = min(1+coinChange(i+1, n, w-coin[i], coin), coinChange(i+1, n, w, coin));

	return Mem[i][w];
}

int main()
{
	vector<int>coin;
	int n, w;

	cin>>n;
	cin>>w;

	for(int i = 0; i < n; i++) {
		int tmp;
		cin>>tmp;

		coin.push_back(tmp);
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= w; j++) {
			Mem[i][j] = Empty;
		}
	}

	int ans = coinChange(0, n, w, coin);

	cout<<"Ans: "<<ans<<endl;

	return 0;

}
