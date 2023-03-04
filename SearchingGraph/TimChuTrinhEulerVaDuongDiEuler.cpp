#include<bits/stdc++.h>
using namespace std;

int n,a[100][100],k;
int degree[100];
set<int> adj[100];

void ktao(){
    cin >> n>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            if(a[i][j]==1){
                adj[i].insert(j);
                adj[j].insert(i);
                degree[i]++;
                degree[j]++;
            }
        }
    }
}

void euler(int v){
    stack<int> st;
    vector<int> EC;
    st.push(v);
    while(!st.empty()){
        int x= st.top();
        if(adj[x].size() !=0){
            int y= *adj[x].begin();
            st.push(y);
            adj[x].erase(y);
            adj[y].erase(x);
        }
        else{
            st.pop();
            EC.push_back(x);
        }
    }
    reverse(begin(EC), end(EC));
    for(int x:EC) cout << x <<" ";
}

int main(){
    ktao();
    euler(k);
}