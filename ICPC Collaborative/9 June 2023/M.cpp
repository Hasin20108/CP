
#include<bits/stdc++.h>
using namespace std;
 

int32_t main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int x,n;
    cin >> x >> n;
    int rest = 0;
    int p ;
    while(n--){
        cin >> p;
        rest = (rest+x-p);
    }
    cout << rest + x << endl;
    return 0;
}