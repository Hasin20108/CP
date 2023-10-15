
#include<bits/stdc++.h>
using namespace std;
#define    ll       long long
#define    int      long long 
#define    rep      for(int i = 0; i < n; i++)
#define    repi     for(int i = a; i < n; i++)
#define    yes      cout << "YES\n"
#define    no       cout << "NO\n"
#define    endl     '\n'
#define    inar    int ar[200001],n; cin>>n;for(int i = 1; i <= n;i++)cin>> ar[i];
const int mod = 998244353;

string reverse(string str){string s;for (int i = str.length() - 1; i >= 0; i--){s += str[i];}return s;}
bool palindrome(string s){string tem = reverse(s);return tem == s;}
string lower(string s){int n = s.length();rep{if(s[i] < 'a'){char ch = s[i] + 'a' - 'A' ;s[i] = ch;}}return s;}
string upper(string s){int n = s.length();rep{if(s[i] >= 'a'){char ch = s[i] + 'A' - 'a' ;s[i] = ch;}}return s;}
bool comp(pair<int ,int> t, pair<int, int> p){return t.first< p.first ;}
int nextsquare(int n){float t = sqrt(n);int x = ceil(t);return x*x;}
bool rev(int x, int y){return x > y;}
int myceil(double x){int t = x;if(x*10 > t*10){return t+1;}else{return t;}}
int power(int x, int y){int ans = 1;while(y--){ans *= x;ans %= mod;}return ans;}
int dectobin(int x){int ans = 0;int n = log2(x) + 1;int temp;for(int i = 0; i < n; i++){temp = ((x & power(2,i)) != 0);temp = temp* power(10,i);ans += temp;}return ans;}
int gcd(int a, int b) {if (b == 0) {return a;}return gcd(b, a % b);}
int lcm(int a, int b) {return (a * b) / gcd(a, b);}
int dig(int temp){int sum = 0;while (temp != 0) {temp = temp / 10;sum++;}return sum;}
int uniq(string s){int n = s.length();set<char>t;rep{t.insert(s[i]);}return t.size();}
int digSum(int x){int sum = 0;while(x){sum += x%10;x = x/10;}return sum;}

const int N = 200005;
int frq[1000001];
vector<int> v[200001];
int f[N][2],x[N],y[N];

//Rabincurp
int hashing(string s){int hassh = 0;int n = s.length();for(int i = 0; i < n; i++){hassh *= 26;hassh += (s[i] - 'a' + 1);}return hassh;}
bool chek(string s,string t){int n = t.length();for(int i = 0; i < n;i++){if(t[i] != s[i]){return false;}}return true;}
int hashing2(int fst,char ch, char ch1, int tt){int x = ch - 'a' + 1;tt--;while(tt--){x *= 26;}fst = fst - x;fst *= 26;fst += (ch1 - 'a' + 1);return fst;}
int RabinCarp(string haystack, string needle) {int pat = hashing(needle);int fst = hashing(haystack.substr(0,needle.length()));if(pat == fst){if(chek(haystack.substr(0,needle.length()), needle)){return 0;}}int tt = needle.length();int n = haystack.length();char ch = haystack[0], ch1;for(int i = 1; i < n-tt+1; i++){ch1 = haystack[i+tt-1];int p = hashing2(fst,ch,ch1,tt);if(p == pat){if(chek(haystack.substr(i,tt),needle)){return i;}}ch = haystack[i];fst = p;}return -1;}
// rabincurp end

// nCr
struct choosen {
int N;
vector<int> fact, invfact;
ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
    if (b & 1) {
        res = res * a;
        res %= mod;
    }
    a = a * a;
    a %= mod;
    b >>= 1;
    }
    return res;
}
void precompute() {
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    }
    invfact[N - 1] = power(fact[N - 1], mod - 2);
    for (int i = N - 2; i >= 1; i--) {
    invfact[i] = invfact[i + 1] * (i + 1) % mod;
    }
}
ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % mod * invfact[n - r] % mod;
}
void init(int n) {
    N = n;
    fact.resize(N + 5);
    invfact.resize(N + 5);
    precompute();
}
};

int mul(int a, int b){
    return ((a%mod) * (b%mod)) %mod;
}

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void solve(){
    int n,a,b;cin >> n >> a >> b;
    int ar[200001];
    rep{
        cin >> ar[i];
    }
    int ans = 0;
    for(int i = 1; i < n ;i++){
        ans += min(a*(ar[i]-ar[i-1]), b);
    }
    cout << ans << endl;
}   

int32_t main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt","r",stdin);   
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