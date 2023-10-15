
#include<bits/stdc++.h>
using namespace std;
char low(char ch){
    if(ch >= 'A' && ch <= 'Z')ch = 'a' + ch - 'A'; 
    return ch;
}

void solve(){
    string s;cin >> s;
    bool ok = true;
    int n = s.length();

    if(low(s[0]) >= 'i' && low(s[0]) <= 'n'){
        for(int i = 1; i < n; i++){
            bool x = (low(s[i]) >= 'a' && low(s[i]) <= 'z');
            bool y = (s[i] >= '0' && s[i] <= '9');
            if(!x && !y){
                ok = false;
            }
        }
        if(ok){
            cout << "Integer variable\n";
        }else{
            cout << "Undefined\n";
        }
    }else if(s[0] >= '1' && s[0] <= '9'){
        int cnt = 0;
        for(int i = 1; i < n; i++){
            if(s[i] < '0' && s[i] > '9'){
                cout << "Undefined\n"; 
                return;
            }
        }
        if(n > 4){
            cout << "LongInt Number\n";
        }else{
            cout << "ShortIng Number\n";
        }

    }else{
        cout << "Undefined\n";
    }
}   

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt","r",stdin);   
    
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}