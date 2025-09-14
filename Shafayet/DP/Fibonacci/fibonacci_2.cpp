#include<iostream>

using namespace std;

int A[200];

void init() {
	for(int i = 0; i < 200; i++) {
		A[i] = -1;
	}
}

int f(int n) {
	if(n <= 1) {
		A[n] = n;
		return n;
	}
	if(A[n] != -1) {
		return A[n];
	}

	A[n] = f(n-1) + f(n-2);

	return A[n];
}

void print(int n) {
	for(int i = 0; i <= n; i++) {
		cout<<A[i]<<" ";
	}

	cout<<endl;
}

int main() {
	int n;

	init();

	cin>>n;

	cout<<f(n)<<endl;

	print(n);

	return 0;
}