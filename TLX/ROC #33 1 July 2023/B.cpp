
#include<bits/stdc++.h>
using namespace std;
#define    ll       long long
#define    int      long long 
int32_t main(){
    // freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt","r",stdin); 
    int m,a,b;
    cin >> m >> a >> b;
    int x = (a/2) + a%2;
    int y = b/2 + b%2;
    if(x+y <= m){
        cout << 0 << " " << min(a,b) << endl;
    }else{
        cout << 1 << " " << min(a,b) << endl;
    }
    return 0;
}   
