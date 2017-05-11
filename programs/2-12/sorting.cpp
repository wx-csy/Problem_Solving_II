#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
unsigned arr[3000005];
unsigned a[3000005];
const unsigned MASK = (1<<16) - 1;

int c[80000];
void magicsort(){
    for (int i=0; i<n; i++)
        c[arr[i]&MASK]++;
    for (int i=1; i<(1<<16); i++)
        c[i] += c[i-1];
    for (int i=n-1; i>=0; i--)
        a[--c[arr[i]&MASK]] = arr[i];

    memset(c, 0, sizeof(c));
    for (int i=0; i<n; i++)
        c[a[i]>>16]++;
    for (int i=1; i<(1<<16); i++)
        c[i] += c[i-1];
    for (int i=n-1; i>=0; i--)
        arr[--c[a[i]>>16]] = a[i];
}

int main(){
    while(~scanf("%d", &(arr[n]))) n++;
    magicsort();
    for (int i=0; i<n-1; i++)
        printf("%d ", arr[i]);
    printf("%d\n", arr[n-1]);
    return 0;
}
