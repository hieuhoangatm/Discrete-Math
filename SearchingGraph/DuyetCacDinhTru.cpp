#include<bits/stdc++.h>
using namespace std;

bool visited[100];
int a[100][100],n;
vector<int> v[100];

void ktao(){
    cin >> n;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++) a[i][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            if(a[i][j]==1){
                v[i].push_back(j);
            }
        }
    }
}

void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int m:v[x]){
            if(!visited[m]){
                q.push(m);
                visited[m]=true;
            }
        }
    }
}

void dinhtru(){
    int dinhlt=0;
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dinhlt++;
            BFS(i);
        }
    }
    for(int i=1;i<=n;i++){
        memset(visited,false,sizeof(visited));
        visited[i]=true;
        int dem=0;
        for(int j=1;j<=n;j++){
            if(!visited[j]){
                dem++;
                BFS(j);
            }
        }
        if(dem> dinhlt) cout << i << " ";
    }
}

int main(){
    ktao();
    dinhtru();
}
