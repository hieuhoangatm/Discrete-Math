#include<bits/stdc++.h>
using namespace std;
#define Max 100
class Graph{
    private:
        int a[Max][Max],n;
        bool chuaxet[Max];
    public:
        void dataInput();
        void graphInit();
        void VertexVisit(int v);
        void recursiveDFS(int u);
};

void Graph::dataInput(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin >> a[i][j];
    }
}

void Graph::graphInit(){
    for(int i=1;i<=n;i++) chuaxet[i]=1;
}

void Graph::VertexVisit(int v){
    cout << v <<" ";
    chuaxet[v]=0;
}

void Graph::recursiveDFS(int u){
    VertexVisit(u);
    for(int v=1;v<=n;v++){
        if(a[u][v]==1 && chuaxet[v]==1) recursiveDFS(v);
    }
}

int main(){
    Graph g;
    g.dataInput();
    g.graphInit();
    g.recursiveDFS(1);
}
