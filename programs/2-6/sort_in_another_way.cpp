#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

queue<int> seq;
vector<bool> visited;
int n;

int main(){
    int x;
    int cur;
    while (cin>>x){
        seq.push(x);
    }
    n = seq.size();
    visited.resize(n+2, false);
    cur = 1;
    while (cur <= n){
        while (!seq.empty() && !visited[cur]){
            x = seq.front();
            seq.pop();
            visited[x] = true;
        }
        x = cur;
        while (visited[cur]) cur++;
        for (int i = x; i < cur; i++){
            cout << i << (i == cur-1 ? "" : ",");
        }
        cout << endl;
    }
    return 0;
}
