#include<bits/stdc++.h>
#include<vector>
using namespace std;

int a[100][100];
vector<int> v[105];
int n;
bool visited[105];

void ktao(){
    cin >> n;
    for(int i=0;i<105;i++){
        v[i].clear();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) a[i][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            if(a[i][j]==1) v[i].push_back(j);
        }
    }
    memset(visited,false,sizeof(visited));
}

void DFS(int u){
    visited[u]=true;
    for(int x:v[u]){
        if(!visited[x]){
            DFS(x);
        }
    }
}

void Dem(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cnt++;
            DFS(i);
        }
    }
    cout << cnt << endl;
}

int main(){
    ktao();
    Dem();
}

