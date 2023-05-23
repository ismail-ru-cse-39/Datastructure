#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

#define SZ 100000+10

int Arr[SZ];
int Group[SZ];
int N;
int SegmentSize;

void preprocess() {
    SegmentSize = sqrt(N);

    for(int i = 0; i < N; i++) {
        Group[i/SegmentSize] += Arr[i];
    }
}

void update(int i, int val) {
    Group[i/SegmentSize] -= Arr[i];
    Group[i/SegmentSize] += val;

    Arr[i] = val;
}

int query(int l, int r) {
    int sum = 0;

    //loop before segment start
    while(l < r && l % SegmentSize != 0) {
        sum += Arr[l];
        l++;
    }

    //All full segment

    while(l + SegmentSize <= r) {
        sum += Group[l/SegmentSize];
        l += SegmentSize;
    }

    //Post segment

    while(l <= r) {
        sum += Arr[l];
        l++;
    }

    return sum;
}


int main()
{
    cin>>N;
    for(int i = 0; i < N; i++) {
        int a;
        cin>>Arr[i];
    }

    preprocess();

    int t;
    cin>>t;

    while(t--) {
        int option;

        cout<<"1. query, 2. update: "<<endl;
        cin>>option;

        if(option == 1) {
            int l, r;
            cin>>l>>r;
            int sum = query(l, r);
            cout<<"sum : " <<sum<<endl;
        }
        if(option == 2) {
            int i, val;
            cin>>i>>val;
            update(i, val);
        }
    }

    return 0;
}

