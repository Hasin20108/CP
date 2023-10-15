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
int frq[1000001];
const int mod = 1e9+7;
string s;
void solve(int t){
    int n;
    cin >> n;
    int ar[8]={0};
    for(int i = 0; i < n ;i++){
        int x; 
        cin >> x;
        ar[x]++;
    }
    // for(int i= 1; i <= 7; i++){
    //     cout << i << " " <<  ar[i] << endl; 
    // }
    if(ar[1] != n/3){
        cout << "-1\n";
    }else if(ar[7] > 0){
        cout << "-1\n";
    }else if(ar[6] < ar[3]){
        cout << "-1\n";
    }else if((ar[2] + ar[3])*3 != n){
        cout << "-1\n";
    }else if((ar[4]+ar[6]) *3 != n){
        cout << "-1\n";
    }
    else if(ar[2] + ar[3] > ar[4]+ar[6]){
        cout << "-1\n";
    }else{
        for(int i = 0; i < n/3; i++){
            if(ar[3]){
                cout << "1 3 6\n" << endl;
                ar[6]--;
                ar[3]--;
                ar[1]--;
            }else{
                if(ar[4]){
                    cout << "1 2 4\n";
                    ar[4]--;
                }else{
                    cout << "1 2 6\n";
                    ar[6]--;
                }
            }
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
        solve(i);
        i++;
    }
    return 0;
}