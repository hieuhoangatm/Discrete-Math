#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
using ll = long long;

const int INF=1e9;
const int maxn=1001;
vector<pair<int,int>> adj[maxn];
int n,s;
vector<int> truoc;

void nhap(){
    for(int i=0;i<maxn;i++) adj[i].clear();
    cin >> n >> s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int w; cin >> w;
            if(w!=0){
                adj[i].push_back({j,w});
            }
        }
    }
}

void dijkstra(int s){
    vector<ll> d(n+1, INF);
    truoc.resize(n+1,0);
    d[s]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,s});
    while(!q.empty()){
        pair<int,int> top=q.top(); q.pop();
        int u= top.second; int kc=top.first;
        if(kc>d[u]) continue;
        for(auto it: adj[u]){
            int v= it.first;
            int w= it.second;
            if(d[v]> d[u]+w){
                d[v]=d[u]+w;
                q.push({d[v],v});
                truoc[v]=u;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout <<"K/c "<< s << " -> "<<i<<" = ";
        if(d[i]==INF){
            cout <<"INF;" << endl;
            continue;
        }
        cout << d[i]<<";     ";
        if(s==i){
            cout << s <<" <- "<<s << endl;
            continue;
        }
        int prev=i;
        while(true){
            cout <<prev;
            prev=truoc[prev];
            if(prev==0) break;
            else cout <<" <- ";
        }
        cout << endl;
    }
}

int main(){
    nhap();
    dijkstra(s);
}
