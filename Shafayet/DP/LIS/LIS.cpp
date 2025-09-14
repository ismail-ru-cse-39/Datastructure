#include<iostream>
#include<vector>

using namespace std;

vector<int>mem;
vector<int>nextIndex;

int LIS(int i, vector<int>& v) {
	if(mem[i] != -1) {
		return mem[i];
	}

	int ans = 0;

	for(int j = i + 1; j < v.size(); j++) {
		if(v[j] > v[i]) {
			int subResult = LIS(j, v);
			if(subResult > ans) {
				ans = subResult;
				nextIndex[i] = j;
			}
		}
	}

	mem[i] = ans + 1;

	return mem[i];

}

int main() {
	int n;
	vector<int>v;

	cin>>n;

	for(int i = 0; i < n; i++) {
		int tmp;
		cin>>tmp;
		v.push_back(tmp);
		mem.push_back(-1);
		nextIndex.push_back(-1);
	}

	int ans = 0;
	int startIndex = -1;

	for(int i = 0; i < n; i++) {
		int result = LIS(i, v);
		if(result > ans) {
			ans = result;
			startIndex = i;
		}
	}

	vector<int>resList;

	while(startIndex != -1) {
		resList.push_back(v[startIndex]);
		startIndex = nextIndex[startIndex];
	}

	cout<<"Ans: "<<ans<<endl;

	for(auto a : resList) {
		cout<<a<<" ";
	}

	cout<<endl;

	return 0;

}