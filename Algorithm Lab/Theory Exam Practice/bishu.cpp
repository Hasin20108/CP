#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int vis[200001];
int leng[100001];
void dfs(int v, int dpth){
    vis[v] = 1;
    leng[v] = dpth;
    for(auto a : adj[v]){
        if(vis[a]!= 1){
            dfs(a,dpth+1);
        }
    }
}

int main(){
    freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt","r",stdin);  
    int n,g;
    cin >> n;
    int a,b;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    cin >> g;
    int ans;
    for(int i = 0; i < g; i++){
        cin >> a;
        if(i == 0)ans = a;
        else {
            if(leng[a] < leng[ans]){
                ans = a;
            }else if(leng[a]==leng[ans]){
                if(a < ans){
                    ans = a;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}