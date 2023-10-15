#include<bits/stdc++.h>
using namespace std;
int m,n;
int par[200001];
int size[200001];
bool comp(pair<pair<int,int>,int>a,pair<pair<int,int>,int>b){
    return a.second < b.second;
}
void make(int n){
    par[n] = n;
    size[n] = 1;
}
int find(int a){
    if(par[a] == a) return a;
    return par[a] = find(par[a]);
}
void Union(int a, int b){
    a = find(par[a]);
    b = find(par[b]);
    if(a!= b){
        if(size[a] < size[b]) swap(a,b);
        par[b] = a;
        size[a] += size[b];
    }
}
int main(){
    freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt","r",stdin);   
    vector<pair<pair<int,int>,int>> edges;
    cin >> n >> m; 
    int u,v,w;
    for(int i= 0; i < m; i++){
        cin >> u >> v >> w;
        edges.push_back({{u,v},w});
    }
    sort(edges.begin(),edges.end(),comp);
    // par[(*edges.begin()).first.first] =(*edges.begin()).first.first;
    // int ancient = (*edges.begin()).first.first;
    int ans = 0;
    for(int i = 1; i <= n ;i++){
        make(i);
    }
    for(auto t: edges){
        // cout << t.first.first << " " << t.first.second << " " << t.second << endl;
        if(find(t.first.first) != find(t.first.second)){
            Union(t.first.first,t.first.second);
            ans += t.second;
        }else{
            continue;
        }
    }
    cout << ans;
     

    return 0;
}