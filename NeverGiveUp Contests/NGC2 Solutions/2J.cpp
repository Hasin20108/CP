#include<bits/stdc++.h>
using namespace std;
#define    int      long long 
#define    rep      for(int i = 0; i < n; i++)
#define    repi     for(int i = a; i < n; i++)
#define    yes      cout << "YES\n"
#define    no       cout << "NO\n"
#define    endl     '\n'
#define    in(n)    int n; cin>>n;

string reverse(string str){string s;for (int i = str.length() - 1; i >= 0; i--){s += str[i];}return s;}
bool palindrome(string s){string tem = reverse(s);return tem == s;}
string lower(string s){int n = s.length();rep{if(s[i] < 'a'){char ch = s[i] + 'a' - 'A' ;s[i] = ch;}}return s;}
string upper(string s){int n = s.length();rep{if(s[i] >= 'a'){char ch = s[i] + 'A' - 'a' ;s[i] = ch;}}return s;}
bool comp(pair<int ,int> t, pair<int, int> p){return t.first< p.first ;}
int nextsquare(int n){float t = sqrt(n);int x = ceil(t);return x*x;}
bool comp1(int x, int y){
    return x > y;
}
int myceil(double x){
    int t = x;
    if(x*10 > t*10){
        return t+1;
    }else{
        return t;
    }
}
int power(int x, int y){
    int ans = 1;
    while(y--){
        ans *= x;
    }
    return ans;
}
int bin(int x){
    int ans = 0;
    int n = log2(x) + 1;
    int temp;
    for(int i = 0; i < n; i++){
        if(x & power(2,i)){
            temp = 1;
        }else{
            temp = 0;
        }
        temp = temp* power(10,i);
        ans += temp;
    }
    return ans;
}
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
bool comp4(pair <int, int> x , pair <int, int> y){
    return ((x.first <= y.first) && (x.second >= y.second));
}
int frq[1000001];
const int mod = 1e9+7;
string s;

vector<int> g[200001];
void solve(){
    int n,m;
    cin >> n >> m;
    int a , b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;
    map<int,int> v;
    map<int,int>v1;
    // v1.push_back(0);
    // cout << v1[5] << endl;
    vector<int>::iterator it;
    bool hi = true;
    while(true){
        for(int i = 1; i <= n; i++){
            cout << "v[" << i << "] : ";
            for(int t: g[i]){
                cout << t << " ";
            }
            cout << endl;
        }

        for(int i = 1; i <= n; i++){
            cout << "g[i].size()- v1[i] (i = "  << i << ") : "<< g[i].size() - v1[i]<< endl;
            if(g[i].size() - v1[i] == 1){
                // g[i].clear();
                v[i] = 1;
            }

        }
        for(int i = 1; i <=n; i++){
            cout << "g[i] = "  << i << ": "<< g[i].size()<< endl;
        }
        hi = true;
        for(int i= 1; i <= n; i++){
            cout << "v1[" << i << "] = " << v1[i] << endl;
        }
        for(int i = 1; i <= n; i++){
            // cout << "size of g[i] if section  i = "  << i << ": "<< g[i].size()<< endl;
            if(g[i].size()-v1[i] > 0){
                for(int t: g[i]){
                    if(v[t] == 1){
                        // g[i].erase(it);
                        v1[i]++;
                    }
                }
                
                hi = false;
            }
            // cout << v1[i] << endl;
        }
        // for(int i= 1; i <= n; i++){
        //     cout << "v1[" << i << "] = " << v1[i] << endl;
        // }
        if(hi) break;
        ans++;
       
        if(ans >1) break;
    }
    // for(int i = 1; i <= n; i++){
    //         if(g[i].size() > 0){
    //             for(auto it = g[i].begin(); it != g[i].end(); it++){
    //                 if(v[*it] == 1){
    //                     g[i].erase(it);
    //                     break;
    //                 }
    //                 cout << *it << " ";
    //             }

    //             // hi = false;
    //         }
    //     }
    cout << endl;
    cout << ans << endl;
    // cout << g[6].size() << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    #endif
    int t = 1;
    // cin >> t;
    int i = 1;
    while(t--){
        solve();
    }
    return 0;
}