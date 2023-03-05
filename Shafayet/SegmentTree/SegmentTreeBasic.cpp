#include<iostream>
using namespace std;

#define SZ 10000

int Arr[SZ];
int Tree[SZ*3];

void init(int node, int b, int e) {
    if(b == e) {
        Tree[node] = Arr[b];
        return;
    }
    int left = node*2;
    int right = node*2 + 1;
    int mid = (b + e)/2;

    init(left, b, mid);
    init(right, mid + 1, e);

    Tree[node] = Tree[left] + Tree[right];
}

int query(int node, int b, int e, int i, int j ) {
    if(i > e  || j < b) {
        return 0; //outside
    }
    if(b >= i && e <= j) {
        return Tree[node]; //fully inside
    }
    //Need to break down
    int left = node*2;
    int right = node*2 + 1;
    int mid = (b + e) /2;

    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid + 1, e, i, j);

    return p1 + p2;
}

void update(int node, int b, int e, int i, int newVal) {
    if(i > e || i < b) {
        return;
    }
    if(b >= i && e <= i)  {
        Tree[node] = newVal;
        return;
    }
    int left = node*2;
    int right = node*2 +1;
    int mid = (b + e)/2;

    update(left, b, mid, i, newVal);
    update(right, mid + 1, e, i, newVal);

    Tree[node] = Tree[left] + Tree[right];
}

int main()
{
    int n;

    cin>>n;
    for(int i = 1; i <= n; i++) {
       Arr[i] = i;
    }
    init(1, 1, n);
    update(1, 1, n, 2, 0);
    cout << query(1, 1, n, 1, 3) << endl;
    update(1, 1, n, 2, 2);
    cout << query(1, 1, n, 2, 2) << endl;
    return 0;
}
