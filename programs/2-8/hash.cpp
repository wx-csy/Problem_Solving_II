#include <iostream>
#include <cmath>
using namespace std;

int m, n;

int divhash(int k){
    return k%m;
}

int mulhash(int k){
    const double A = 0.6180339887;
    return int(fmod(double(k)*A, 1.0)*double(m));
}

int cnt1, cnt2;
bool h1[100005], h2[100005];

int main(){
    int k;
    int hk1, hk2;
    while (cin >> n >> m){
        cnt1 = cnt2 = 0;
        for (int i=0; i<m; i++){
            h1[i] = h2[i] = false;
        }
        while (n--){
            cin >> k;
            hk1 = divhash(k);
            if(h1[hk1]) cnt1++;
            h1[hk1] = true;
            hk2 = mulhash(k);
            if(h2[hk2]) cnt2++;
            h2[hk2] = true;
        }
        cout << cnt1 << endl;
        cout << cnt2 << endl;
    }
    return 0;
}
