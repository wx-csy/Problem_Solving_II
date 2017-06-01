#include <iostream>
#include <queue>
#include <utility>
#include <cassert>
using namespace std;

int adj[2050][2050];
bool visited[2050];
int dist[2050], pr[2050];
int n, s;

typedef pair<int, int> pii;

void bfs(){
    pii cur;
    fill(visited, visited+n, false);
    queue<pii> q;
    q.push(make_pair(s, -1));
    dist[s] = 0;
    while (!q.empty()){
        cur = q.front(); q.pop();
        if (visited[cur.first]) continue;
        visited[cur.first] = true;
        pr[cur.first] = cur.second;
        if (cur.second != -1) dist[cur.first] = dist[cur.second] + 1;
        for (int i=0; i<n; i++){
            if (adj[cur.first][i] && !visited[i]){
                q.push(make_pair(i, cur.first));
            }
        }
    }
    for (int i=0; i<n; i++){
        if (!visited[i]){
            cout << i << ' ' << 9999 << ' ' << -1 << endl;
        } else {
            cout << i << ' ' << dist[i] << ' ' << pr[i] << endl;
        }
    }
}

int t;
void dfs(int s, int depth){
    visited[s] = true;
    t++;
    dist[s] = t;
    for (int i=0; i<n; i++){
        if (adj[s][i] && !visited[i]){
            dfs(i, depth + 1);
        }
    }
    pr[s] = ++t;
}

int main(){
    while (cin >> n >> s){
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                cin >> adj[i][j];
        bfs();
        fill(visited, visited+n, false);
        t = 0;
        for (int i=0; i<n; i++) if (!visited[i]) dfs(i, 1);
        for (int i=0; i<n; i++){
            cout << i << ' ' << dist[i] << ' ' << pr[i] << endl;
        }
    }
    return 0;
}
