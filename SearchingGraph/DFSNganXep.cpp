#include<bits/stdc++.h>
using namespace std;
#define MAX 100
class Graph{
    private:
        int a[MAX][MAX],n;
        bool chuaxet[MAX];
    public:
        void dataInput();
        void graphInit();
        void vertexVisit(int v);
        void stackDFS(int u);
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

void Graph::vertexVisit(int v){
   cout << v << " ";
   chuaxet[v]=0;
}

void Graph::stackDFS(int u){
    stack<int> nxep;
    nxep.push(u);
    vertexVisit(u);
    while(!nxep.empty()){
        int s=nxep.top();
        nxep.pop();
        for(int i=1;i<=n;i++){
            if(a[s][i]==1 && chuaxet[i]==1){
                nxep.push(s);
                nxep.push(i);
                vertexVisit(i);
                break;
            }
        }
    }
}

int main(){
    Graph g;
    g.dataInput();
    g.graphInit();
    g.stackDFS(1);
}