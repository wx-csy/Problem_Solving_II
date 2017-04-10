#include <iostream>
#include <cstring>
using namespace std;

int a[1000005];
int temp[1000005];
long long cnt = 0;

void mergesort(int l, int r){
    int mid;
    if (l>=r) return;
    mid = (l+r)/2;
    mergesort(l, mid);
    mergesort(mid+1, r);
    int pl = l, pr = mid+1;
    int cur = l;
    while (pl<=mid && pr<=r){
        if (a[pl]>a[pr]){
            cnt += mid-pl+1;
            temp[cur++] = a[pr++];
        } else {
            temp[cur++] = a[pl++];
        }
    }
    while (pl<=mid){
        temp[cur++] = a[pl++];
    }
    while (pr<=r){
        temp[cur++] = a[pr++];
    }
    memcpy(a+l, temp+l, sizeof(int) * (r-l+1));
}

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    mergesort(0, n-1);
    cout << cnt << endl;
    return 0;
}
