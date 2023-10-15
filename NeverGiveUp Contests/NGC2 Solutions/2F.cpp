#include<bits/stdc++.h>
using namespace std;
#define    int      long long 
#define    rep      for(int i = 0; i < n; i++)
#define    repi     for(int i = a; i < n; i++)
#define    yes      cout << "yes\n"
#define    no       cout << "no\n"
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
void solve(){
    int n;
    cin >> n;
    bool ok = false;
    int ar[200001],ar1[200001];
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        // ar1[i] = ar[i];
    }
    vector<int>v1,v2,v3;
    int x = 1;
    int l,r;
    for(int i = 1; i < n;i++){
        if(ar[i]< ar[i-1]){
            if(x == 3){
                no;
                return;
            }
            if(x == 1){
                l = i-1;
                v1.push_back(ar[i-1]);
            }
            v1.push_back(ar[i]);
            x = 2;
            r = i;
        }else if(x <= 3){
            if(x == 2) x == 3;
            continue;
        }else{
            no;

            cout << "  erer\n";
            return;
        }
        
    }
    // cout << l << r << endl;
    // for(auto t: v1){
    //     cout << t << " ";
    // }
    int p = v1.size();
    sort(v1.begin(),v1.end());
    if(l != 0){
        if(ar[l-1]<v1[0] && ar[r+1] > v1[p-1]){
            yes;
            cout << l+1 << " " << r+1 << endl; 
        }else{
            no;
        }
    }else{
        if(ar[r+1] > v1[p-1]){
            yes;
            cout << l+1 << " " << r+1 << endl;
        }else{
            no;
        }
    }

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