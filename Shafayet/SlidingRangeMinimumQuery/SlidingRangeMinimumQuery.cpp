#include<iostream>
#include<vector>
#include<deque>

using namespace std;

deque< pair<int,int> >Dq;

vector<int> sliding_rmq(vector<int>& arr, int m) {
	Dq.clear();

	vector<int>res;

	for(int i = 0 ; i < arr.size(); i++) {
		while(Dq.size() > 0 && Dq.front().first >= arr[i]) {
			Dq.pop_front();
		}
		Dq.push_front(make_pair(arr[i], i));

		while(Dq.size() > 0 && Dq.back().second <= i - m) {
			Dq.pop_back();
		}

		if(i >= m-1) {
			cout<<"minimum: "<<Dq.back().first<<endl;
			res.push_back(Dq.back().first);
		}
	}

	return res;
}

void print(vector<int>& arr) {
	for(auto a: arr) {
		cout<<a<<" ";
	}

	cout<<endl;
} 

int main()
{
	vector<int>arr;
	int n;

	cin>>n;

	while(n--) {
		int tmp;
		cin>>tmp;
		arr.push_back(tmp);
	}

	int q;

	cin>>q;

	while(q--) {
		int m;
		cin>>m;

		vector<int>res;

		res = sliding_rmq(arr, m);

		print(res);
	}

	return 0;
}