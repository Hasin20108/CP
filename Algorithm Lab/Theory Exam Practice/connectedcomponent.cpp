#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int vis[200001];

void dfs(int v){
    vis[v] = 1;
    for(auto a : adj[v]){
        if(vis[a] != 1){
            dfs(a);
        }
    }
}

int main(){
    freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt","r",stdin);  
    int n,e;
    cin >> n >> e;
    int a,b;
    for(int i = 0; i < e; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;
    for(int i = 1; i < n ; i++){
        if(vis[i] != 1){
            ans++;
            dfs(i);
        }
    }
    cout << ans << endl;
    return 0;
}