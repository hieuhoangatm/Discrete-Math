#include<bits/stdc++.h>
#define MAX 100

using namespace std;

class Graph{
    private:
        int a[MAX][MAX],n;
        bool chuaxet[MAX];
    public:
        void dataInput();
        void graphInit();
        void VertexVisit(int v);
        void queueBFS(int u);
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
    cout << v << " ";
    chuaxet[v]=0;
}

void Graph::queueBFS(int u){
    queue<int> hangdoi;
    hangdoi.push(u);
    VertexVisit(u);
    while(!hangdoi.empty()){
        int s= hangdoi.front();
        hangdoi.pop();
        for(int v=1;v<=n;v++){
            if(a[s][v]==1 && chuaxet[v]==1){
                VertexVisit(v);
                hangdoi.push(v);
            }
        }
    }
}

int main(){
    Graph g;
    g.dataInput();
    g.graphInit();
    g.queueBFS(1);
}