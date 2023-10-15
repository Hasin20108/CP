#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt","r",stdin); 
    int n,e;
    cin >> n >> e;
    vector<int> dist(n+1,1e7);
    vector<pair<int,int>> adj[n+1];
    int u,v,w;
    for(int i = 0; i < e; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    set<pair<int,int>> s;
    int source; cin >> source;
    s.insert({0,source});
    dist[source] = 0;

            // for(int i = 1; i <= n; i++){
            //     cout << i << " : ";
            //     for(auto t: adj[i]){
            //         cout << "("<<t.first << "," << t.second << ")  ";
            //     }cout << endl;
            // }
    
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        for(auto it : adj[x.second]){
            if(dist[it.first] > dist[x.second] + it.second){
                s.erase({dist[it.first],it.first});
                dist[it.first] = dist[x.second] + it.second;
                s.insert({dist[it.first],it.first});
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(dist[i] < 1e7){
            cout << dist[i] << " ";
        }else cout << -1 << " ";
    }cout << endl;
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// typedef pair<int,int>p;
// const int N = 1e6;
// #define INF  1e9
// vector<p>graph[N];
// int dist[N];
// bool visited[N];

// void dijkstra(int src){
//     priority_queue<p,vector<p>,greater<p>>pq;
//     pq.push({0,src});
//     dist[src]=0;
//     visited[src]=true;
//     while(!pq.empty()){
//         p u = pq.top(); pq.pop();
//         for(auto v:graph[u.second]){
//             if((u.first + v.second)<dist[v.first]){
//                 dist[v.first]=u.first + v.second;
//                 pq.push({dist[v.first],v.first});
//             }
//         }
//     }
// }

// int main(){
//     freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt","r",stdin);
//     int n,e;    cin>>n>>e;
//     for(int i=0; i<e; i++){
//         int u,v,w;  cin>>u>>v>>w;
//         graph[u].push_back({v,w});
//         graph[v].push_back({u,w});
//     }

//     for(int i=0; i<=n; i++) dist[i]=INF;

//     dijkstra(0);
//     cout<<"Distance: "<<endl;
//     for(int i=1; i<=n; i++)
//         cout<<i<<"\t\t"<<dist[i]<<endl;
//     return 0;
// }