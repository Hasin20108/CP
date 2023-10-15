#include<bits/stdc++.h>
using namespace std;
vector<int> adj[20000];
int ind[200001];
int n,m;
vector<int> ans;


void kahn(){
    queue <int> q;
    for(int i = 1; i <= n ;i++){
        if(ind[i] == 0)q.push(i);
    }

    while(!q.empty()){
        int x = q.front();
        ans.push_back(x);
        q.pop();
        for(auto t: adj[x]){
            ind[t]--;
            if(ind[t] == 0)q.push(t);
        }
    }

    for(auto t: ans){
        cout << t << " ";
    }cout << endl;
}

int main(){
    freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt","r",stdin);
    int u,v;    
    cin >> n >> m;
    while(m--){
        cin >> u >> v;
        adj[u].push_back(v);
        ind[v]++;
    }
    kahn();
}