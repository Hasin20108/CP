#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj[200001];   
int vis[200001];

int main(){
    freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt","r",stdin);   
    int n,m;
    int u,v,w;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> >g;
    // set<pair<int,int>> s;
    // s.insert({0,1});
    g.push({0,1});
    int ans = 0;
    while(!g.empty()){
        auto x = g.top();
        g.pop();
        cout << x.first << " " << x.second << endl;
        if(vis[x.second] == 1)continue;
        vis[x.second] = 1;
        ans += x.first;
        for(auto t: adj[x.second]){
            if(vis[t.first] != 1){
                g.push({t.second,t.first});
                // ans += t.second;
            }
        }
    }
    cout << ans << endl;
    return 0;
}