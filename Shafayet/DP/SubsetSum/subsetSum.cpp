#include<iostream>
#include<vector>

using namespace std;

int Mem[1000][1000];


int subsetSum(vector<int> &nums, int i, int w) {
	//cout<<"sz, i, w, Mem[i][w]: "<<nums.size()<<" "<<i<<" "<<w<<" "<<Mem[i][w]<<endl;
	if(w == 0) return 1;
	if(i == nums.size()) return 0;
	if(Mem[i][w] != -1) return Mem[i][w];

	int res1 = subsetSum(nums, i+1, w - nums[i]);
	int res2 = subsetSum(nums, i+1, w);

	//cout<<"i, w, res1, res2:"<<i<<" "<<w<<" "<<res1<<" "<<res2<<endl;
	Mem[i][w] = res1 + res2;

	return Mem[i][w];
}

void initMemo(int n, int r) {
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= r; j++) {
			Mem[i][j] = -1;
		}
	}
}

int combination(int n, int r) {
	if(r == 0 || r == n) return 1;
	if(r > n) return 0;
	if(Mem[n][r] != -1) return Mem[n][r];

	return Mem[n][r] = combination(n-1, r-1), combination(n-1, r);
}


int main()
{
	int n;
	vector<int> nums;
	int w;


	cin>>n;
	cin>>w;
	for(int i = 0; i < n; i++) {
		int tmp;
		cin>>tmp;
		nums.push_back(tmp);
	}

	initMemo()

	int res = subsetSum(nums, 0, w);
	cout<<"Res: "<<res<<endl;

	initMemo()

	int res = combination(n, r)

	cout<<"Combination: "<<res<<endl;

	return 0;
}