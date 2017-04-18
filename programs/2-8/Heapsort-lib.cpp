#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int n;
int heap[10000008];

int main(){
    while (cin >> n){
        for (int i=0; i<n; i++)
            cin >> heap[i];
        make_heap(heap, heap+n, greater_equal<int>());
        while (n>0){
            cout << heap[0];
            pop_heap(heap, heap+n, greater_equal<int>());
            if (--n) cout << ' ';
        }
        cout << endl;
    }
    return 0;
}
