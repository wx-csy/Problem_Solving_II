#include <iostream>
#include <numeric>
#include <cstring>
using namespace std;

const char* codetable[10] = {
    "11000", "00011", "00101", "00110", "01001",
    "01010", "01100", "10001", "10010", "10100"
};
const int weight[5] = {7, 4, 2, 1, 0};

int decode(const char* c){
    int cnt = 0;
    int ans;
    int code[5];
    for (int i=0; i<5; i++){
        code[i]=c[i]-'0';
        if (code[i]==1) cnt++;
    }
    if (cnt != 2) return -1;
    ans = inner_product(code, code+5, weight, 0);
    if (ans == 11) ans = 0;
    return ans;
}

int main(){
char tmp[50];
while (!cin.getline(tmp, 40).eof()){
    int ans[10];
    if (strlen(tmp) == 5){
        cout << codetable[tmp[0]-'0'] << ' ';
        cout << codetable[tmp[1]-'0'] << ' ';
        cout << codetable[tmp[2]-'0'] << ' ';
        cout << codetable[tmp[3]-'0'] << ' ';
        cout << codetable[tmp[4]-'0'] << endl;
    } else {
        for (int i=0; i<5; i++){
            ans[i] = decode(tmp + 6*i);
            if (ans[i] < 0){
                cout << "error" << endl;
                goto nw;
            }

        }
        for (int i=0; i<5; i++){
            cout << ans[i];
        }
        cout << endl;
    }
nw:;
}
    return 0;
}
