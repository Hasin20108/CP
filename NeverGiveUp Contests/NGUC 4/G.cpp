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
    // if(x.first == y.first){
    //     return (x.second <= y.second);
    // }
    // else {
    //     return (x.first < y.first)  ;
    // }
    return x.first < y.first;
}
int dig(int temp){
        int sum = 0;
        while (temp != 0) {
            temp = temp / 10;
            sum++;
        }
        return sum;
}
int operation(int temp){
    int sum = 0;
        while (temp != 0) {
            sum = sum + temp % 10;
            temp = temp / 10;
        }
    return sum ;
}
int frq[1000001];
const int mod = 1e9+7;
vector<int> v[200001];
const int N = 200005;
int f[N][2],x[N],y[N];
int uniq(string s){
    int n = s.length();
    set<char>t;
    rep{
        t.insert(s[i]);
    }
    return t.size();
}
int hashing(string s){
    int hassh = 0;
    int n = s.length();
    // cout << hassh << " " << n << endl;
    for(int i = 0; i < n; i++){
        // cout << hassh << endl;
        hassh *= 26;
        hassh += (s[i] - 'a' + 1);
    }
    // cout << hassh << endl;
    return hassh;
}
bool chek(string s,string t){
    int n = t.length();
    for(int i = 0; i < n;i++){
        if(t[i] != s[i]){
            return false;
        }
    }
    return true;
}
int hashing2(int fst,char ch, char ch1, int tt){
    int x = ch - 'a' + 1;
    tt--;
    while(tt--){
        x *= 26;
    }
    fst = fst - x;
    fst *= 26;
    fst += (ch1 - 'a' + 1);
    return fst;

}
int RabinCarp(string haystack, string needle) {
    int pat = hashing(needle);
    int fst = hashing(haystack.substr(0,needle.length()));
    if(pat == fst){
        if(chek(haystack.substr(0,needle.length()), needle)){
            // cout << "0\n";
            return 0;
        }
    }

    int tt = needle.length();
    int n = haystack.length();
    char ch = haystack[0], ch1;
    for(int i = 1; i < n-tt+1; i++){
        ch1 = haystack[i+tt-1];
        int p = hashing2(fst,ch,ch1,tt);
        if(p == pat){
            if(chek(haystack.substr(i,tt),needle)){
                return i;
            }
        }
        ch = haystack[i];
        fst = p;
    }
    return -1;
}
int digSum(int x){
    int sum = 0;
    while(x){
        sum += x%10;
        x = x/10;
    }
    return sum;
}
int arr[200001];
int parent[200001];
int find(int v){
if(v == parent[v]) return v;
return find(parent[v]);
}
void join(int a, int b){
a = find(a);
b = find(b);
if(a != b){
parent[b] = a;
}
}
void solve(){
    int n;
    int ar[200001];
    cin >> n;
    rep{
        cin >> ar[i];
    }
    int mx = 0;
    int pos;
    for(int i = 1; i < n ;i++){
        ar[i] = ar[i] + ar[i-1];
        if(ar[i] > mx ){
            mx = ar[i];
            pos = i;
        }
    }
    // cout << mx << pos << endl;
    for(int i = 0; i <= pos ;i++){
        mx = max(mx - ar[i] , mx);
    }
    cout << mx << endl;
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