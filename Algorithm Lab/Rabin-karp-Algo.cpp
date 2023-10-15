#include<bits/stdc++.h>
using namespace std;
#define    int      long long 
const int mod = 1e17+7;
int hashing(string s){
    int hassh = 0;
    int n = s.length();
    for(int i = 0; i < n; i++){
        hassh *= 26;
        hassh += (s[i] - 'a' + 1);
        hassh %= mod;
    }
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
    x %= mod;
    fst = fst - x;
    fst *= 26;
    fst += (ch1 - 'a' + 1);
    fst %= mod;
    return fst;

}
void solve(){
    

    string s = "ababcaababcaabc";
    string t = "ababcaabc";
    int pat = hashing(t);
    int fst = hashing(s.substr(0,t.length()));
    // cout << pat << "  " << fst << endl;
    if(pat == fst){
        if(chek(s.substr(0,t.length()), t)){
            cout << "0\n";
            return;
        }
    }

    int tt = t.length();
    int n = s.length();
    char ch = s[0], ch1;
    for(int i = 1; i < n-tt+1; i++){
        ch1 = s[i+tt-1];
        int p = hashing2(fst,ch,ch1,tt);
        // cout << pat << "   " << p << endl;
        if(p == pat){
            if(chek(s.substr(i,tt),t)){
                cout << i << endl;
                return;
            }
        }
        ch = s[i];
        fst = p;
    }

    cout << "-1\n";
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