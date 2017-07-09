#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define Rep(i, n) for (int i = 1; i <= (n); i++)
#define range(x) (x).begin(), (x).end()
typedef long long LL;

int n;
LL mat[1024][1024];
LL dp[1024][1024];

int main(){
    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<=i; j++) cin >> mat[i][j];
    for (int i=0; i<=n; i++)
        for (int j=0; j<=i; j++) dp[i][j] = LLONG_MAX;
    dp[0][0] = 0;
    for (int i=0; i<n; i++)
        for (int j=0; j<=i; j++)
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]+mat[i][j]),
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+mat[i][j]);
    LL ans = LLONG_MAX;
    for (int i=0; i<=n; i++) ans = min(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}
