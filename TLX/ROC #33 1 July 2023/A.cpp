
#include<bits/stdc++.h>
using namespace std;
#define    ll       long long
int main(){
    // freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt","r",stdin);   
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    int xum = (n-x) + 2*(m-y);
    if(xum > 25){
        cout << "LOLOS\n";
    }else{
        cout << "TIDAK LOLOS\n";
    }
    return 0;
}   