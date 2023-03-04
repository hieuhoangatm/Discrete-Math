#include<bits/stdc++.h>
using namespace std;

bool visited[1000];
int a[1000][1000];
vector<int> v[1000];
vector<pair<int,int>> dscanh;
int n;

void ktao(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            if(a[i][j]==1){
                v[i].push_back(j);
                dscanh.push_back({i,j});
            }
        }
    }
}

void DFS(int u){
    visited[u]=true;
    for(int x:v[u]){
        if(!visited[x]){
            DFS(x);
        }
    }
}

void DFS2(int u,int s,int t){
    visited[u]=true;
    for(int x:v[u]){
        if( (u==s && x==t)  || ( u==t &&  x==s)) continue;
        if(!visited[x]) DFS2(x,s,t);
    }
}

void canhcau(){
    int dem=0;
    int lienthong=0;
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            lienthong++;
            DFS(i);
        }
    }
    for(auto it:dscanh){
        int x = it.first, y=it.second;
        memset(visited,false,sizeof(visited));
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(!visited[j]){
                cnt++;
                DFS2(j,x,y);
            }
        }
        if(cnt > lienthong && x<y){
            cout << x << " "<<y << endl;
        }
    }
}

int main(){
    ktao();
    canhcau();
}