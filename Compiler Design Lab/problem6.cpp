#include<bits/stdc++.h>
using namespace std;

char low(char ch){
    if(ch >= 'A' && ch <= 'Z')ch = 'a' + ch - 'A'; 
    return ch;
}

void solve(){
    string t;cin >> t;
    cout << t << endl;
    int n = t.length();
    if(t[0] == 'c'){
        for(int i = 0; i < n; i++){
            if(i == 0){
                if(t[i] != 'c'){
                    cout << "invalid input" << endl;return;
                } 
            }else if (i == 1){
                if(t[i] != 'h'){
                    cout << "invalid input" << endl;return;
                } 
            }else if(i == 2){
                if(t[i] != '_'){
                    cout << "invalid input" << endl;return;
                } 
            }else{
                if((low(t[i]) > 'z' || low(t[i]) < 'a') && (t[i] > '9' || t[i] < '0')){
                    cout << "invalid input" << endl;return;
                }
            }
        }
        if(n < 4){
            cout << "invalid input" << endl;return;
        }
        cout << "Character variable\n";
    }else if(t[0] == 'b'){
        for(int i = 0; i < n; i++){
            if(i == 0){
                if(t[i] != 'b'){
                    cout << "invalid input" << endl;return;
                } 
            }else if (i == 1){
                if(t[i] != 'n'){
                    cout << "invalid input" << endl;return;
                } 
            }else if(i == 2){
                if(t[i] != '_'){
                    cout << "invalid input" << endl;return;
                } 
            }else{
                if((low(t[i]) > 'z' || low(t[i]) < 'a') && (t[i] > '9' || t[i] < '0')){
                    cout << "invalid input" << endl;return;
                }
            }
        }
        if(n < 4){
            cout << "invalid input" << endl;return;
        }
        cout << "Binary variable\n";
    }else if(t[0] == '0'){
        for(int i = 1; i < n; i++){
            if(i == 1){
                if(t[i] > '1' ||  t[i] < '0'){
                    cout << "invalid input" << endl;return;
                } 
            }else{
                if(t[i] > '1' || t[i] < '0'){
                    cout << "invalid input" << endl;return;
                }
            }
        }
        if(n < 3) {
            cout << "invalid input" << endl;return;
        }
        cout << "Binary Number\n";

    }else cout << "invalid input" << endl;
}   

int32_t main(){
    freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt","r",stdin);   
    int t = 1;  
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}