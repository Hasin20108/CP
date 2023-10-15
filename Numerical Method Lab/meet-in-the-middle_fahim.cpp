#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define int long long int
#define endl "\n"
#define F first
#define S second
#define deb(args...){string _s = #args;replace(_s.begin(), _s.end(), ',', ' ');stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);}
#define all(v) v.begin(), v.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define multi_ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
ll power(ll x , ll y ){ ll ans =1 ;while(y--){ans *= x;} return ans ;}
ll Ceil(ll dividend , ll divisor){return dividend / divisor + (dividend % divisor ? 1 : 0);}
ll modpow(ll a, ll b,ll m) {ll res = 1; while (b) {if (b & 1) res = res * a % m; a = a * a % m; b >>= 1;} return res;}
using namespace std;
using namespace __gnu_pbds;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << '{';
    for (const auto &x : v)
        os << " " << x;
    return os << '}';
}
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
const int N=2e5+5,M=1e9+7;
void solve(int tt){
    int n,i,a,b,j,ans=0;
    cin>>n>>a>>b;
    vector<int>ar(n),v,w,br,cr;
    for(i=0;i<n;i++){
        cin>>ar[i];
    }
    for(i=0;i<n/2;i++){
        v.push_back(ar[i]);
    }
    for(i=n/2;i<n;i++){
        w.push_back(ar[i]);
    }
    int f=1<<w.size();
    // cout << f << endl;
    for(i=1;i<f;i++){
        int sum=0;
        cout << "i = " << i << endl;
        for(j=0;j<w.size();j++){
            cout << "  j = " << j;
            cout << "   sum  = " << sum << endl;
            if(i&(1<<j)){
                sum+=w[j];
            }
        }
        if(sum>=a && sum<=b){
            ans++;
        }
        cr.push_back(sum);
    }
    sort(all(cr));
    int c=1<<v.size();
    for(i=1;i<c;i++)
    {
        int sum=0;
        for(j=0;j<v.size();j++){
            if(i&(1<<j)){
                sum+=v[j];
            }
        }
        if(sum>=a && sum<=b){
            ans++;
        }
        br.push_back(sum);
    }
    for(i=0;i<br.size();i++){
        int d=a-br[i];
        int e=b-br[i];
        int id=lower_bound(cr.begin(),cr.end(),d)-cr.begin();
        int id2=upper_bound(cr.begin(),cr.end(),e)-cr.begin();
        ans+=(id2-id);
    }
    if(0>=a && 0<=b){
        ans++;
    }
    cout<<ans<<endl;



} 

int32_t main()
{
    freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt", "r", stdin);
    #ifdef DEBUG
        // freopen("output.txt","w", stdout);
    #else
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); 
    #endif
    ll test_case = 1;
    //cin>>test_case;
    for(int i = 1; i <= test_case; i++){
        solve(i);
    }
}