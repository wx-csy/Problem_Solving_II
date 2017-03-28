#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> linklist[100005];
int a[100005];
bool visited[100005];
vector<int> offspring[100005];

void loadData(){
    int a, b;
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>a[i];
    for (int i=1; i<n; i++){
        cin>>a>>b;
        linklist[a].push_back(b);
        linklist[b].push_back(a);
    }
}

void buildTree(int i){
    for (vector<int> iterator it = linklist[i].begin(); it!=linklist[i].end(); it++){
        if (!visited[*it]){
            visited[*it] = true;
            offspring[i].push_back(*it);
            buildTree(*it);
        }
    }
}

int main(){

    return 0;
}
