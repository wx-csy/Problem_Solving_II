#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define int long long
int n;
int dim[1020];
int dp[1020][1020];
#undef int
int main(){
    #define int long long
    int minv;
    while (cin >> n){
        for (int i=0; i<=n; i++) cin >> dim[i];
        for (int i=0; i<n; i++) dp[i][i] = 0;
        for (int j=1; j<n; j++){
            for (int i=0; i+j<n; i++){
                minv = INT_MAX;
                for (int k=0; k<j; k++){
                    minv = min(minv,
                               dp[i][i+k] + dp[i+k+1][i+j] + dim[i] * dim[i+k+1] * dim[i+j+1]);
                }
                dp[i][i+j] = minv;
            }
        }
        cout << dp[0][n-1] << endl;
    }
    return 0;
}
