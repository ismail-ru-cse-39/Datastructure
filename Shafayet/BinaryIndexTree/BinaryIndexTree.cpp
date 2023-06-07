//1 based indx array

#include<iostream>
#include<vector>

using namespace std;

#define SZ 100000+10

int Tree[SZ];
int Arr[SZ];
int N;

int queryBIT(int indx) {
	int sum = 0;

	while(indx > 0) {
		sum += Tree[indx];
		indx -= indx & (-indx);
	}

	return sum;
}

void updateBIT(int indx, int x, int n) {
	while(indx <= n) {
		Tree[indx] += x;
		indx += indx & (-indx);
	}
}

void constructBIT() {
	for(int i = 1 ; i <= N; i++) {
		Tree[i] = 0;
	}

	for(int i = 1; i <= N; i++) {
		updateBIT(i, Arr[i], N);
	}
}

int main()
{
	cin>>N;

	for(int i = 1 ; i <= N; i++) {
		cin>>Arr[i];
	}

	constructBIT();

	cout<<"No of operation: ";

	int test;
	cin>>test;

	while(test--) {
		cout<<"1. update"<<endl;
		cout<<"2. query"<<endl;

		int q;

		cin>>q;

		if(q == 1) {
			int indx, val;
			cin>>indx>>val;
			updateBIT(indx, val, N);
		} 
		if(q == 2) {
			int indx;
			cin>>indx;
			int sum = queryBIT(indx);
			cout<<"Sum from 1 to "<<indx<<" : "<<sum<<endl;
		}
	}

	return 0;

}