#include <iostream>
#include <cstdio>
#include <cctype>
#include <numeric>
#include <cassert>
#include <cstring>
using namespace std;

const char* codetable[10] = {
    "11000", "00011", "00101", "00110", "01001",
    "01010", "01100", "10001", "10010", "10100"
};

void decode(const char* c){
    int ans[6];
    char sections[5][8];
    assert (c[5] == ' ' && c[11] == ' ' && c[17] == ' '
        && c[23] == ' ');
    sscanf(c, "%s %s %s %s %s",
           sections[0], sections[1], sections[2], sections[3], sections[4]);
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            assert(sections[i][j] == '0' || sections[i][j] == '1');
        }
    }
    for (int i=0; i<5; i++){
        for (int j=0; j<10; j++){
            if (strcmp(sections[i], codetable[j])==0){
                ans[i] = j;
                goto nf;
            }
        }
        cout << "error" << endl;
        return;
nf:;
    }
    for (int i=0; i<5; i++){
        cout << ans[i];
    }
    cout << endl;
}

void encode(char* str){
    assert(strlen(str) == 5);
    const char* sections[50];
    for (int i=0; i<5; i++){
        sections[i] = codetable[str[i]-'0'];
    }
    for (int i=0; i<5; i++){
        cout << sections[i];
        if (4-i) cout << ' ';
    }
    cout << endl;
}

int main(){
    char tmp[50];
    int x;
    while (!cin.getline(tmp, 40).eof()){
        if (strlen(tmp)  == 5){
            for (int i=0; i<5; i++){
                assert(isdigit(tmp[i]));
            }
            encode(tmp);
        } else if (strlen(tmp) == 29) {
            decode(tmp);
        } else {
            assert(false);
        }
    }
    return 0;
}
