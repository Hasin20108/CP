#include<bits/stdc++.h>
using namespace std;
#define    ll       long long
#define    int      long long 

int32_t main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;cin >> n;
    int ar[1000001];
    for(int i = 0 ; i < n; i++){
        cin >> ar[i];
    }
    int ans = 0;
    int temp,z;
    for(int i = 1; i < n-1; i++){
        if(ar[i] > ar[i-1] && ar[i] > ar[i+1]){
            temp = 1;z = 1;
            while(true){
                if(i-z < 0 || i+z >= n) break;
                if(ar[i-z] == ar[i+z]){
                    temp += 2;
                }else break;
                z++;
            }
            ans = max(ans,temp);
        }
    }
    if(ans < 3) cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}