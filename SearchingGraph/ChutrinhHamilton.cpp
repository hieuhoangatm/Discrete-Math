#include<iostream>
#define MAX 100
using namespace std;

class Graph{
    private:
        int A[MAX][MAX], n, start, X[MAX];
        bool chuaxet[MAX];
    public:
        void dataInput();
        void graphInit();
        void hmt(int k);
        int  getStart(){   
             return  start;   X[j]
        }
        void setXk(int k, int v0){ 
             X[k]=v0;    
        }
        void setChuaxet(int v0){    
            chuaxet[v0]=0;  
        }
};

void Graph::dataInput(){
    cin>>n>>start;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) cin>>A[i][j];
}

void Graph::graphInit(){
    for(int i=1; i<=n; i++) chuaxet[i]=1;
}

void Graph::hmt(int k){
    for(int y=1; y<=n; y++){
        if(A[y][X[k-1]]==1){
            if((k==n+1)&&(y==start)){
                for(int j=1; j<=n; j++) cout<<X[j]<<" ";
                cout<<start<<"\n";    
            }else{
                if(chuaxet[y]==1){
                    X[k]=y;
                    chuaxet[y]=0;  
                    hmt(k+1);   
                    chuaxet[y]=1;
                }
            }
        }
    }
}

int main(){
    Graph g;
    g.dataInput();  g.graphInit(); 
    g.setXk(1, g.getStart());  g.setChuaxet(g.getStart());  g.hmt(2);   
}
