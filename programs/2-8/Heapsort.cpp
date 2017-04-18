#include <iostream>
#include <algorithm>
using namespace std;

int n, size;
int heap[10000008];

#define LEFT(x) ((x)<<1)
#define RIGHT(x) (LEFT(x)+1)
#define PARENT(x) ((x)>>1)

void heapify(int i){
    int l = LEFT(i), r = RIGHT(i);
    int largest = i;
    if (l <= size && heap[l] > heap[largest])
        largest = l;
    if (r <= size && heap[r] > heap[largest])
        largest = r;
    if (largest != i){
        swap(heap[i], heap[largest]);
        heapify(largest);
    }
}

void build_heap(){
    for (int i = size/2; i > 0; i--){
        heapify(i);
    }
}

void heapsort(){
    build_heap();
    for (int i = size; i > 1; i--){
        swap(heap[1], heap[i]);
        size--;
        heapify(1);
    }
}

int main(){
    while (cin >> n){
        size = n;
        for (int i=1; i<=n; i++)
            cin >> heap[i];
        heapsort();
        for (int i=1; i<=n; i++){
            cout << heap[i] << (i!=n?" ":"");
        }
        cout << endl;
    }
    return 0;
}
