#include<iostream>
using namespace std;

#define SZ 10000+10
struct Node{
    int val;
    int prop;
    int sum;
};
int Arr[SZ];
Node Tree[SZ*4];

void init(int node, int b, int e) {
    if(b == e) {
        Tree[node].sum = Arr[b];
        return;
    }
    int left = node*2;
    int right = node*2 + 1;
    int mid = (b+e)/2;

    init(left, b, mid);
    init(right, mid+1, e);

    Tree[node].sum = Tree[left].sum + Tree[right].sum;
}

void update(int node, int b, int e, int i, int j, int val) {
    if(i > e || j < b) {
        return;
    }
    if(b >= i || e <= j) {
        Tree[node].sum += (e-b+1)*val;
        Tree[node].prop += val;
        return;
    }
    int left = node*2;
    int right = node*2 +1;
    int mid = (b+e)/2;

    update(left, b, mid, i, j, val);
    update(right, mid + 1, e, i, j, val);

    Tree[node].sum = Tree[left].sum + Tree[right].sum + (e - b + 1) * Tree[node].prop;
}

int query(int node, int b, int e, int i, int j, int carry = 0) {
    if(i > e || j < b) {
        return 0;
    }
    if(b >= i && e <= j) {
        return Tree[node].sum + carry*(e-b+1);
    }
    int left = node<<1;
    int right = (node<<1)+1;
    int mid = (b + e)>>1;

    int p1 = query(left, b, mid, i, j, carry +  Tree[node].prop);
    int p2 = query(right, mid+1, e, i, j, carry + Tree[node].prop);

    return p1 + p2;
}

int main()
{
    int n;

    cin>>n;
    for(int i = 1; i <= n; i++) {
       Arr[i] = i;
    }
    init(1, 1, n);
    update(1, 1, n, 2, 4, 2);
    cout << query(1, 1, n, 2, 4) << endl;
    update(1, 1, n, 2, 4, -2);
    cout << query(1, 1, n, 2, 4) << endl;
    return 0;
}
