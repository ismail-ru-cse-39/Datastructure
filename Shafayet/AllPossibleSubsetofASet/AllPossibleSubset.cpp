#include<bits/stdc++.h>
using namespace std;

void subsetBackTracking(vector<int>&nums, vector<int>&subset, vector<vector<int>>&res, int indx) {
    res.push_back(subset);

    for(int i = indx; i < nums.size(); i++) {
        subset.push_back(nums[i]);
        subsetBackTracking(nums, subset, res, i+1);
        subset.pop_back();
    }
}

int main() {
    vector<vector<int>>res;
    vector<int>subset;
    vector<int>nums;
    int n;
    cin>>n;

    for(int i = 1; i <= n; i++) {
        nums.push_back(i);
    }

    subsetBackTracking(nums, subset, res, 0);
    cout<<"[ ";
    for(auto a: res) {
        cout<<"[ ";
        for(auto b: a) {
            cout<<b<<", ";
        }
        cout<<"]"<<", ";
    }
    cout<<" ]"<<endl;
}
