#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define Rep(i, n) for (int i = 1; i <= (n); i++)
#define range(x) (x).begin(), (x).end()
#define next(x) scanf("%d", &x)
typedef long long LL;

int n;
LL f[205];
LL psum[205];
LL dp[205][205];

int main(){

    LL minv;
    while (cin >> n){
        rep (i, n) cin >> f[i];
        partial_sum(f, f+n, psum);
        for (int i=0; i<n; i++) dp[i][i] = 0;
        for (int j=1; j<n; j++){
            for (int i=0; i+j<n; i++){
                minv = LLONG_MAX;
                for (int k=0; k<j; k++){
                    minv = min(minv,
                               dp[i][i+k] + dp[i+k+1][i+j] + psum[i+j] - psum[i] + f[i]);
                }
                dp[i][i+j] = minv;
            }
        }
        cout << dp[0][n-1] << endl;
    }
    return 0;
}
