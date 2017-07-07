#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define Rep(i, n) for (int i = 1; i <= (n); i++)
#define range(x) (x).begin(), (x).end()
typedef long long LL;

int n;
LL a[2048];
vector<int> h;
LL dp[2048][2048];
LL temp;

int main(){
    while (cin >> n){
        h.clear();
        rep (i, n) cin >> a[i], h.push_back(a[i]);
        sort(range(h));
        rep (i, n) {
            if (a[0] <= h[i])
                dp[0][i] = 0;
            else
                dp[0][i] = a[0]-h[i];
        }
        for (int i=1; i<n; i++){
            rep (j, n){
                dp[i][j] = dp[i-1][j] + abs(a[i]-h[j]);
                if (j) dp[i][j] = min(dp[i][j], dp[i][j-1]);
            }
        }
        temp = dp[n-1][n-1];
        h.clear();
        rep (i, n) h.push_back(a[i]=-a[i]);
        sort(range(h));
        rep (i, n) {
            if (a[0] <= h[i])
                dp[0][i] = 0;
            else
                dp[0][i] = a[0]-h[i];
        }
        for (int i=1; i<n; i++){
            rep (j, n){
                dp[i][j] = dp[i-1][j] + abs(a[i]-h[j]);
                if (j) dp[i][j] = min(dp[i][j], dp[i][j-1]);
            }
        }
        cout << min(temp, dp[n-1][n-1]) << endl;
    }
    return 0;
}
