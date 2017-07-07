#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define Rep(i, n) for (int i = 1; i <= (n); i++)
#define range(x) (x).begin(), (x).end()
typedef long long LL;

int A, B, C;

bool r[1024][1024];
struct state{
    int a, b, n;

    state(int a, int b, int n){
        this->a=a; this->b=b; this->n=n;
    }
    state(){}
};
queue<state> q;

int main(){
    state cur, next;
    while (cin >> A >> B >> C){
        memset(r, 0, sizeof(r));
        while (!q.empty()) q.pop();
        q.push(state(0,0,0));
        while (!q.empty()){
            cur = q.front(); q.pop();
            if (r[cur.a][cur.b]) goto cont;
            r[cur.a][cur.b]=true;
            if (cur.a==C || cur.b==C){
                cout << cur.n << endl;
                goto next;
            }
            next = cur;
            next.n++;
            next.a=A;  q.push(next);
            next.a=0;  q.push(next);
            next.a=cur.a;
            next.b=B; q.push(next);
            next.b=0; q.push(next);
            if (cur.a<B-cur.b){
                next.a=0;
                next.b=cur.b+cur.a;
                q.push(next);
            } else {
                next.b=B;
                next.a=cur.a+cur.b-B;
                q.push(next);
            }
            if (cur.b<A-cur.a){
                next.b=0;
                next.a=cur.a+cur.b;
                q.push(next);
            } else {
                next.a=A;
                next.b=cur.a+cur.b-A;
                q.push(next);
            }

cont:;
        }
        cout << -1 << endl;
next:;
    }

    return 0;
}
