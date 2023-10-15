
#include<bits/stdc++.h>
using namespace std;

void solve(){
    map<string,string>mp;
    mp["CSE-3141"] = "Computer Science & Engineering, 3rd year,1st semester, Compiler Design, Theory.";
    string t;cin >> t;
    cout << mp[t] << endl;

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