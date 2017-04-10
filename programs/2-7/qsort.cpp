#include <iostream>
using namespace std;

#define unsigned int
inline void swap(unsigned* a, unsigned* b){
    static unsigned x;
    x = *a;
    *a = *b;
    *b = x;
}

void isort(unsigned* begin, unsigned* end){
    static unsigned key;
    static unsigned* j;
    for (unsigned* i = begin + 1; i < end; i++){
        key = *i;
        j = i-1;
        while (j >= begin && *j > key){
            *(j+1) = *j;
            j--;
        }
        *(j+1) = key;
    }
}

inline unsigned* midnum(unsigned* a, unsigned* b, unsigned* c){
    if (*a < *b){
        if (*c < *a) return a;
        if (*c > *b) return b;
        return c;
    } else{
        if (*c > *a) return a;
        if (*c < *b) return b;
        return c;
    }
}

void quicksort(unsigned* begin, unsigned* end){
    if (end - begin < 36) {
        isort(begin, end);
        return;
    }
    static unsigned* L;
    static unsigned* last;
    L = begin; last = end-1;
    swap(midnum(begin + (end-begin)/6,
                begin + (end-begin)/2,
                end - (end-begin)/6), last);
    for (unsigned* ptr = begin; ptr != last; ptr++){
        if (*ptr < *last){
            swap(L, ptr);
            L++;
        }
    }
    swap(L, last);
    quicksort(begin, L);
    quicksort(L + 1, end);
}

unsigned a[1000005];
int n;

int main(){
    while (cin >> n){
        for (int i=0; i<n; i++)
            cin >> a[i];
        quicksort(a, a+n);
        for (int i=0; i<n; i++){
            cout << a[i] << (i==n-1?"":" ");
        }
        cout << endl;
    }
    return 0;
}
