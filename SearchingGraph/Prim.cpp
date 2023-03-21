#include<vector>
//#include<pair>
#include<climits>
#include<iostream>
#include<cstring>

using namespace std;

const int maxn=1001;

int n,k;
vector<pair<int,int>> adj[maxn];
bool used[maxn];
int a[maxn][maxn];

void nhap(){
    cin >> n>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            if(a[i][j] !=0 ){
                adj[i].push_back({j,a[i][j]});
                adj[j].push_back({i,a[i][j]});
            }
        }
    }
    memset(used,false,sizeof(used));
}

struct canh{
    int x,y,w;
};

void prim(int u){
    vector<canh> mst;
    int d=0;
    used[u]=true;
    while(mst.size()<n-1){
        int min_w = INT_MAX;
        int x,y;
        for(int i=1;i<=n;i++){
            if(used[i]){
                for(pair<int,int> it:adj[i]){
                    int j=it.first, trongso= it.second;
                    if(!used[j] && trongso < min_w){
                        min_w= trongso;
                        x=j; y=i;
                    }
                }
            }
        }
        mst.push_back({x,y,min_w});
        d+=min_w;
        used[x] =true;
    }
    cout << "dH = " << d << endl;
    for(canh e:mst){
        if(e.x > e.y) swap(e.x,e.y);
        cout << e.x << " "<<e.y << endl;
    }
}

int main(){
    nhap();
    prim(k);
}
