
#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n; cin >> n;
    int x = 0;
    for(int i = 1; i < n; i *= 2){
        x++;
    }
    cout << x + 1 << endl;
    return 0;
}