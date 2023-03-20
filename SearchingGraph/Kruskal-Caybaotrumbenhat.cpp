#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct edge{
    int u,v;
    int w;
};

int n,m;
const int maxn=100;
int parent[maxn],sz[maxn];
vector<edge> canh;

void make_set(){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        sz[i]=1;
    }
}

int find(int v){
    if(v==parent[v]) return v;
    return parent[v]= find(parent[v]);
}

bool Union(int a, int b){
    a= find(a);
    b= find(b);
    if(a==b){
        return false;
    }
    if(sz[a] < sz[b]) swap(a,b);
    parent[b]=a;
    sz[a]+=sz[b];
    return true;
}

int ai[100][100];
void inp(){
    //cin >> n >>m;
    cin >> n;
    // for(int i=0;i<m;i++){
    //     int x,y,w; cin >> x >> y >>w;
    //     edge e;
    //     e.u=x; e.v=y; e.w=w;
    //     canh.push_back(e);
    // }
    for(int i=1;i<=n;i++){
        edge e;
        for(int j=1;j<=n;j++){
            cin >> ai[i][j];
            if(i<j && ai[i][j]!=0){
                e.u=i;
                e.v=j;
                e.w= ai[i][j];
                canh.push_back(e);
            }
        }
    }
}

bool cmp(edge a, edge b){
    if(a.w != b.w) return a.w < b.w;
    else{
        if(a.u !=b.u) return a.u< b.u;
        else return a.v < b.v;
    }
}

void Kruskal(){
    vector<edge> mst;
    int d=0;
    sort(canh.begin(), canh.end(),cmp);
    for(int i=0;i<canh.size();i++){
        if(mst.size()==n-1) break;
        edge e = canh[i];
        if(Union(e.u, e.v)){
            mst.push_back(e);
            d+=e.w;
        }
    }
    if(mst.size() == n-1){
        cout << "dH = "<<d << endl;
        for(auto it:mst) cout << it.u <<" "<<it.v << endl;
    }
}

int main(){
    inp();
    make_set();
    Kruskal();
}
