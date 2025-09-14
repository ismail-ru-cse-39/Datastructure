#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool checkValidParanthesis(string s) {
	stack<int>opn;

	for(int i = 0; i < s.size(); i++) {
		if(s[i] == ')') {
			if(!opn.empty()) {
				opn.pop();
			} else {
				return false;
			}
		} else {
			opn.push(i);
		}
	}

	return opn.empty();
}

int main() {
	string s;

	while(true) {
	cin>>s;
	
	if(checkValidParanthesis(s)) {
		cout<<"valid parantheisis"<<endl;
	} else {
		cout<<"Not valid parantheisis"<<endl;

	}
}
}