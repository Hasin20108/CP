
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

string check(string &s,int a,int b){
    int zero = 0;
    int one = 0;
    for(int i = a-1; i <b; i++){
        if(s[i] == '0')zero++;
        else one++;
    }
    for(int i = a-1; i < b; i++){
        if(zero){s[i] = '0';zero--;}
        else s[i] = '1';
    }
    return s;
}
void check2(string &s, string &temp , int a,int b){
    int j = 0;
    for(int i = a-1; i < b; i++){
        s[i] = temp[j];
        j++;
    }
}
void solve(){
    int n,m;cin >> n >> m;
    string s,temp;cin >> s;
    set<string> st;
    int a,b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        temp = s.substr(a-1,b-a+1);
        // cout << temp << endl;
        st.insert(check(s,a,b));
        // cout << s<< endl;
        check2(s,temp,a,b); 
        // cout << s << endl;
    }
    cout << st.size() << endl;
}   

int32_t main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt","r",stdin);   
    // freopen("output.txt","w",stdout);
    #endif
    int t = 1;  
    cin >> t;
    int i = 1;
    while(t--){
        solve();
    }
    return 0;
}