
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

    if(low(s[0]) >= 'a' && low(s[0]) <= 'h' || low(s[0]) >= 'o' && low(s[0]) <= 'z' ){
        for(int i = 1; i < n; i++){
            bool x = (low(s[i]) >= 'a' && low(s[i]) <= 'z');
            bool y = (s[i] >= '0' && s[i] <= '9');
            if(!x && !y){
                ok = false;
            }
        }
        if(ok){
            cout << "Float variable\n";
        }else{
            cout << "Invalid Input\n";
        }
    }else if(n >= 4){
        int cnt = 0;
        if(s[0]=='0' && s[1] == '.'){
            for(int i = 2; i <n; i++){
                if(s[i] < '0' && s[i] > '9'){
                    cout << "Invalid Input\n"; 
                    return;
                }
                cnt++;
            }
            if(cnt > 2){
                cout << "Double Number\n";
            }else{
                cout << "Invalid Input\n";
            }
        }else {
            int save = 0;
            if(s[0] >= '9' && s[0] <= '1'){
                cout << "Invalid Input\n";
                return;
            }
            for(int i = 1; i < n; i++){
                if(s[i] == '.'){
                    save = i; break;
                }
                else if(s[i] >= '9' && s[i] <= '0'){
                    cout << "Invalid Input\n";
                    return;
                }
            }
            for(int i = save + 1; i < n; i++){
                if(s[i] >= '9' && s[i] <= '0'){
                    cout << "Invalid Input\n";
                    return;
                }
                cnt++;
            }
            if(cnt <= 2){
                cout << "Float Number\n";
            }else{
                cout << "Double Number\n";
            }
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