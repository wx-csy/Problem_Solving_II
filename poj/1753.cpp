#include <iostream>
#include <cstdlib>
#include <queue>
#include <utility>
using namespace std;

typedef unsigned short ushort;

const ushort flip_op[16] = {
    0x0013, 0x0027, 0x004E, 0x008C,
    0x0131, 0x0272, 0x04E4, 0x08C8,
    0x1310, 0x2720, 0x4E40, 0x8C80,
    0x3100, 0x7200, 0xE400, 0xC800
};

inline bool achieved(ushort x){
    return (x==0) || (x==0xFFFF);
}

bool visited[1<<16];
#define state first
#define num second
queue<pair<ushort, ushort> > q;

ushort loadData(){
    ushort init = 0;
    char str[8];
    for (int i=0; i<4; i++){
        cin >> str;
        for (int j=0; j<4; j++){
            init <<= 1;
            if (str[j]=='b') init |= 1;
        }
    }
    return init;
}

inline void push_state(ushort state, ushort num){
    if (achieved(state)){
        cout << num << endl;
        exit(0);
    }
    if (visited[state]) return;
    visited[state] = true;
    q.push(make_pair(state, num));
}

int main(){
    pair<ushort, ushort> cur;
    push_state(loadData(), 0);
    while (!q.empty()){
        cur = q.front();
        q.pop();
        for (int i=0; i<16; i++){
            push_state(cur.state ^ flip_op[i], cur.num + 1);
        }
    }
    cout << "Impossible" << endl;
    return 0;
}
