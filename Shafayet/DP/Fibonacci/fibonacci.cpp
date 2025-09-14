#include<stdio.h>
#include<iostream>

using namespace std;

class Fibonacci{
public:
	int fbArr[200];
	int fbArr2[200];

	Fibonacci() {
		for(int i = 0; i < 200; i++) {
			fbArr[i] = -1;
			fbArr2[i] = -1;
		}
	}

	int fibonacci(int n) {
		if(n <= 1) {
			fbArr[n] = n;
			return fbArr[n];
		}

		if(fbArr[n] != -1) {
			return fbArr[n];
		}

		fbArr[n] = fibonacci(n-1) + fibonacci(n-2);
		return fbArr[n];
	}

	void fibonacci2(int n) {
		fbArr2[0] = 0;
		fbArr2[1] = 1;

		for(int i = 2; i <= n; i++) {
			fbArr2[i] = fbArr2[i-1] + fbArr2[i-2];
		}
	}

	void print(int n) {
		for(int i = 0; i <= n; i++) {
			cout<<fbArr2[i]<<" ";
		}
		cout<<endl;
	}
};

	int main() {
		int n;
		cin>>n;
		Fibonacci fb;
		fb.fibonacci2(n);
		cout<<fb.fibonacci(n)<<endl;
		fb.print(n);		

		return 0;
	}