#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
 
int total;
int n;
int depth[10000005];
 
int main(){
    int l, r;
    int lp, rp;
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> depth[i];
    l = 0; r = n + 1;
    while (depth[l+1] > depth[l]) l++;
    while (depth[r-1] > depth[r]) r--;
    while (l!=r){
        if (depth[l] >= depth[r]){
            rp = r;
            while (depth[--rp] < depth[r]){
                total += depth[r] - depth[rp];
            }
            r = rp;
        } else {
            lp = l;
            while (depth[++lp] < depth[l]){
                total += depth[l] - depth[lp];
            }
            l = lp;
        }
    }
    cout << total << endl;
    return 0;
}