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
void solve(int t){
    int t25 = 0,t50 = 0,t100 = 0;
    int n;
    cin >> n;
    int x;
    bool ok = false;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(ok){
            continue;
        }
        else if(x == 25){
            t25++;
        }else if(x == 50){
            if(t25 == 0){
                ok = true;
            }
            t25--;
            t50++;
        }else{
            if(t50 > 0){
                if(t25 > 0){
                    t25--;
                    t50--;
                }else{
                    ok = true;
                }
            }else{
                if(t25 > 2){
                    t25 -= 3;
                }else{
                    ok = true;
                }
            }
            t100++;
        }
    }
    if(ok){
        no;
    }else{
        yes;
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
        solve(i);
        i++;
    }
    return 0;
}