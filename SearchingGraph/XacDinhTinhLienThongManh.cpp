#include<bits/stdc++.h>
using namespace std;

int a[50][50],n;
bool visited[50];
vector<int> v[50];

void ktao(){
    cin >> n;
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++) a[i][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            if(a[i][j]==1) v[i].push_back(j);
        }
    }
    memset(visited,false,sizeof(visited));  
}

int BFS(int u){
    queue<int> q;
    q.push(u);
    int dem=0;
    visited[u]=true;
    while(!q.empty()){
        int cnt = q.front();
        q.pop();
        dem++;
        for(int x: v[cnt]){
            if(!visited[x]){
                visited[x]=true;
                q.push(x);
            }
        }
    }
    return dem;
}

bool Strongly_connected(){
    for(int i=1;i<=n;i++){
        if(BFS(i)!=n){
            return false;
            break;
        }
        memset(visited,false,sizeof(visited));
    }
    return true;
}

int main(){
    ktao();
    if(Strongly_connected()) cout << "strongly connected";
    else cout <<"not strongly connected";
}