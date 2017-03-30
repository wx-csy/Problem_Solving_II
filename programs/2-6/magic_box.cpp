#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
int dif[3];
int cr, cy, cb;
int mn;

void vanish(){
    int dif2[3] = {abs(cr-cy), abs(cy-cb), abs(cb-cr)};
    sort(dif2, dif2+3);
    if (dif2[0] == dif[0] && dif2[1] == dif[1] && dif2[2] == dif[2]){
        cr = cy = cb = 0;
    }
}

int main(){
    char c;
    cin >> dif[0] >> dif[1] >> dif[2];
    sort(dif, dif+3);
    while (cin >> c){
        if (c=='R') cr++;
        if (c=='Y') cy++;
        if (c=='B') cb++;
        mn = max(mn, cr+cy+cb);
        vanish();
    }
    cout << mn << endl;
    return 0;
}
