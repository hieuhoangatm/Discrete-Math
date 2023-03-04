#include<bits/stdc++.h>
using namespace std;

vector<int> v[100];
bool visit1[100], visit2[100];
int cha1[100], cha2[100];
int n,s,t,a[100][100];

void ktao(){
    cin >> n >> s >> t;
    for(int i=0;i<100;i++){
        v[i].clear();
    }
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
    memset(visit1, false, sizeof(visit1));
    memset(visit2, false, sizeof(visit2));
    memset(cha1,0,sizeof(cha1));
    memset(cha2,0,sizeof(cha2));
}

void DFS(int u){
    visit1[u]=true;
    for(int x:v[u]){
        if(!visit1[x]){
            cha1[x]=u;
            DFS(x);
        }
    }
}

void BFS(int u){
    queue<int> q;
    q.push(u);
    visit2[u]=true;
    while(!q.empty()){
        int cnt= q.front();
        q.pop();
        for(int x: v[cnt]){
            if(!visit2[x]){
                q.push(x);
                cha2[x]=cnt;
                visit2[x]=true;
            }
        }
    }
}

void DuongDi(int s,int t){
    int m=s, n=t;
    DFS(s); BFS(m);
    if(!visit1[t] || !visit2[n]){
        cout <<"no path\n";
    }
    else{
        vector<int> tmp1;
        while(t!=s){
            tmp1.push_back(t);
            t= cha1[t];
        }
        tmp1.push_back(s);
        cout <<"DFS path: ";
        for(int x:tmp1) cout << x << " ";
        cout << endl;
        
        vector<int> tmp2;
        while(n!=m){
            tmp2.push_back(n);
            n= cha2[n];
        }
        tmp2.push_back(m);
        cout <<"BFS path: ";
        for(int x:tmp2) cout << x <<" ";
        cout << endl;
    }
}

int main(){
    ktao();
    DuongDi(s,t);
}