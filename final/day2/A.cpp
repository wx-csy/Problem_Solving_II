#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define Rep(i, n) for (int i = 1; i <= (n); i++)
#define range(x) (x).begin(), (x).end()
typedef long long LL;

int n, m;
int grid[205][205];

int cnt;
int main(){
    while (cin >> n >> m){
        cnt = 0;
        rep (i, n)
            rep (j, m) cin >> grid[i][j];
        if (n <= m){
            rep (i, n){
                int minv = INT_MAX;
                rep (j, m){
                    minv = min(minv, grid[i][j]);
                }
                cnt += minv;
                rep (j, m) grid[i][j] -= minv;
            }
            rep (j, m){
                int minv = INT_MAX;
                rep (i, n){
                    minv = min(minv, grid[i][j]);
                }
                cnt += minv;
                rep (i, n) grid[i][j] -= minv;
            }
        } else {
            rep (j, m){
                int minv = INT_MAX;
                rep (i, n){
                    minv = min(minv, grid[i][j]);
                }
                cnt += minv;
                rep (i, n) grid[i][j] -= minv;
            }
            rep (i, n){
                int minv = INT_MAX;
                rep (j, m){
                    minv = min(minv, grid[i][j]);
                }
                cnt += minv;
                rep (j, m) grid[i][j] -= minv;
            }
        }

        rep (i, n)
            rep (j, m)
                if (grid[i][j]) {
                    cout << -1 << endl;
                    goto next;
                }
        cout << cnt << endl;
next:;
    }
    return 0;
}
