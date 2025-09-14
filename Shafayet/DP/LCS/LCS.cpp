#include<iostream>
#include<string>
#include<vector>

using namespace std;

int mxsz = 10000;

vector<vector<int>>Mem(mxsz, vector<int>(mxsz));

int lcs(int i, int j, string &a, string &b) {
	if(i == a.size() || j == b.size()) return 0;

	if(Mem[i][j] != -1) {
		return Mem[i][j];
	}

	int ans = 0;

	if(a[i] == b[j]) {
		ans = 1 + lcs(i+1, j+1, a, b);
	} else {
		int val1 = lcs(i+1, j, a, b);
		int val2 = lcs(i, j+1, a, b);
		ans = max(val1, val2);
	}

	Mem[i][j] = ans;

	return Mem[i][j];
}

int lcsIterator(string &a, string &b) {
	int n = a.size();
	int m = b.size();

	for(int i = 0; i <= n; i++) {
		Mem[i][m] = 0;
	}
	for(int j = 0; j <= m; j++) {
		Mem[n][j] = 0;
	}

	for(int i = n-1; i >= 0; i--) {
		for(int j = m-1; j >= 0; j--) {
			if(a[i] == b[j]) {
				Mem[i][j] = 1 + Mem[i+1][j+1];
			} else {
				Mem[i][j] = max(Mem[i][j+1], Mem[i+1][j]);
			}
		}
	}

	return Mem[0][0];
}

int main() {
	string a, b;

	cin>>a>>b;

	for(int i = 0; i < mxsz; i++) {
		for(int j = 0; j < mxsz; j++) {
			Mem[i][j] = -1;
		}
	}

	int ans = lcs(0, 0, a, b);
	int ans2 = lcsIterator(a, b);
	cout<<"ans: "<<ans<<endl;
	cout<<"ans2: "<<ans2<<endl;


	return 0;
}