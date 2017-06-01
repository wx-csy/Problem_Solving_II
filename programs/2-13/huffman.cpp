#include <iostream>
#include <queue>
#include <utility>
#include <functional>
using namespace std;

typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > q;

int main(){
    int n;
    int f, c;
    pii a, b;
    while (cin >> n){
        for (int i=0; i<n; i++){
            cin >> f >> c;
            q.push(make_pair(f, 0));
        }
        while (q.size()>1){
            a = q.top(); q.pop();
            b = q.top(); q.pop();
            q.push(make_pair(a.first+b.first, a.second+b.second+a.first+b.first));
        }
        cout << q.top().second << endl;
        q.pop();
    }
    return 0;
}
