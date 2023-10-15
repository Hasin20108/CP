
#include<bits/stdc++.h>
using namespace std;
#define    ll       long long
#define    int      long long 
#define    rep      for(int i = 0; i < n; i++)
#define    repi     for(int i = a; i < n; i++)
#define    yes      cout << "YES\n"
#define    no       cout << "NO\n"
#define    endl     '\n'

void solve(int testcase){
    int n,a;cin >> a >> n;

    if(n < a){
        cout << "Case " << testcase << ": "<< 0 << endl;
        return;
    }
    int ans = 0;
    int x = a-1,temp = 0;
    int seg = a*(a-1);
    vector<int>v;

    for(int i = 0; i < seg; i++){
        ans += abs(x%a - x%(a-1));
        temp += abs(x%a - x%(a-1));x++;
        if((i+1)%(a-1) == 0 ){
            v.push_back(temp);
            temp = 0;
        }
    }x--;
    // cout << x << endl;
    int res = 0;
    int vv = v.size();
    int tt = 0;
    x = a-2;
    res += ((n-a+2)/seg)*ans;
    x += ((n-a+2)/seg)*seg;
    // cout << x << " " << res << endl;
    for(int i = x +a-1; i <= n; i+= (a-1)){
        res += v[tt%vv];
        tt++;
        x += a-1;
    }
    // cout << x << " " << res << endl;
    while(x < n){
        x++;
        res += abs(x%a - x%(a-1));

    }


    // cout << ans << endl;
    cout << "Case " << testcase << ": "<< res << endl;
}   

int32_t main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t = 1;  
    cin >> t;
    int i = 1;
    while(t--){
        solve(i++);
    }
    return 0;
}