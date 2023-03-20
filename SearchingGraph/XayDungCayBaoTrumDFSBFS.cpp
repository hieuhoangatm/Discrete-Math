#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
int n,s;
int mt[100][100];
vector<vector<int>> e;

void dfstree(int s){
    vector<pair<int,int>> tree;
    vector<bool> vs(n+1,false);
    stack<int> st;
    st.push(s);
    vs[s]=true;
    while( !st.empty() ){
        int u= st.top();
        st.pop();
        for(int i:e[u]){
            if(!vs[i]){
                tree.push_back( {min(u,i), max(u,i)});
                st.push(u);
                st.push(i);
                vs[i]=true;
                break;
            }
        }
    }
    cout << "DFS tree\n";
    for(auto i:tree){
        cout << i.first <<" "<<i.second;
        cout << endl;
    }
    //cout << endl;
}

void bfstree(int s){
    vector<pair<int,int>> tree;
    vector<bool> vs(n+1,false);
    queue<int> q;
    q.push(s);
    vs[s]=true;
    while(!q.empty()){
        int u= q.front();
        q.pop();
        for(int i:e[u]){
            if(!vs[i]){
                tree.push_back({min(u,i), max(u,i)});
                q.push(i);
                vs[i]=true;
            }
        }
    }
    cout <<"BFS tree\n";
    for(auto i:tree){
        cout << i.first <<" "<<i.second << endl;
    }
   // cout << endl;
}

int main(){
    cin >> n >> s;
    e.resize(n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> mt[i][j];
            if(mt[i][j]==1){
                e[i].push_back(j);
            }
        }
    }
    dfstree(s);
    bfstree(s);
    return 0;
}
