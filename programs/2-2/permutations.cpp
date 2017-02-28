#include <iostream>
#include <cstring>
using namespace std;

string S;
int cnt[256];
string cur;

void generatePermutations(int n){
    if (n==0) {
        cout << cur << endl;
    }
    for (char i='a'; i<='z'; i++){
        if (cnt[i]){
            cnt[i]--;
            cur[S.size() - n] = i;
            generatePermutations(n-1);
            cnt[i]++;
        }
    }
}

int main(){
    int ncase;
    cin >> ncase;
    while (ncase--){
        cin >> S;
        memset(cnt, 0, sizeof(cnt));
        cur = S;
        for (int i = 0; i < S.size(); i++){
            cnt[S[i]]++;
        }
        generatePermutations(S.size());
        if (ncase) cout << endl;
    }
    return 0;
}
