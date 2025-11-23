#include<iostream>
#include<vector>

using namespace std;

struct Matrix{
	int row, col;
	Matrix(int _row, int _col) {
		row = _row;
		col = _col;
	}
};

vector<Matrix> mats;

int mem[1000][1000];

void init() {
	for(int i = 0; i < 1000; i++) {
		for(int j = 0; j < 1000; j++) {
			mem[i][j] = 0;
		}
	}
}

int mergeCell(int i, int k, int j) {
	return mats[i].row * mats[k].col * mats[j].col;
}


int mcm(int i, int j) {
	if(i >= j) return 0;
	if(mem[i][j] != 0) return mem[i][j];

	int ans = 999999;
	for(int k = i; k < j; k++) {
		int res_left = mcm(i, k);
		int res_right = mcm(k+1, j);
		int cost = res_left + res_right + mergeCell(i, k, j);
		ans = min(cost, ans);
	}

	mem[i][j] = ans;

	return mem[i][j];
}


int main() {
	int n = 0;
	int row , col;

	cin>>n;
	for(int i = 0; i < n; i++) {
		cin>>row>>col;
		mats.push_back(Matrix(row, col));
	}


	int res = mcm(0, n-1);

	cout<<res<<endl;

	return res;

}