#include <bits/stdc++.h>
using namespace std;

int capacity = 100000;
int heap_size = 0;
int arr[100000];

void minheapify(int i);

int parent(int i)
{
    return (i-1)/2;
}

int left(int i)
{
    return (i*2)+1;
}

int right(int i)
{
    return (i*2) + 2;
}

int getMin()
{
    return arr[0];
}

void swap_two(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insert_key(int k)
{
    if(heap_size == capacity) {
        cout<<"Array out of bound."<<endl;
        return;
    }

    heap_size++;
    int i = heap_size - 1;

    arr[i] = k;

    while(i != 0 && arr[parent(i)] > arr[i]) {
        swap_two(&arr[parent(i)], &arr[i]);
        i = parent(i);
    }
}

//Decrease value of i to new_value. assuming new_value will be smaller.
void decrease_key(int i, int new_val)
{
    arr[i] = new_val;

    while(i != 0 && arr[parent(i)] > arr[i]) {
        swap_two(&arr[parent(i)], &arr[i]);
        i = parent(i);
    }
}

int extract_min()
{

    if(heap_size <= 0){
        return INT_MAX;
    }
    if(heap_size == 1) {
        heap_size--;
        return arr[heap_size];
    }

    heap_size--;
    int root = arr[0];
    arr[0] = arr[heap_size];
    minheapify(0);

    return root;
}

void delete_key(int i)
{
    decrease_key(i, INT_MIN);
    extract_min();
}
void minheapify(int i)
{
    int l = left(i);
    int r = right(i);

    int smallest = i;

    if(l < heap_size && arr[l] < arr[smallest]){
        smallest = l;
    }
    if(r < heap_size && arr[r] < arr[smallest]) {
        smallest = r;
    }

    if(smallest != i) {
        swap_two(&arr[i], &arr[smallest]);
        minheapify(smallest);
    }
}

void print_heap()
{
    for(int i =0 ; i < heap_size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;

    cin>>n;

    for(int i = 0 ; i < n ; i++) {
        int val;
        cin>>val;
        insert_key(val);
    }
    print_heap();

    delete_key(0);

    print_heap();

    cout<<extract_min()<<endl;
    print_heap();
    cout<<getMin()<<endl;
    print_heap();
    decrease_key(2, 1);
    print_heap();
    cout<<getMin()<<endl;

    return 0;

}
