#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin >> n;
    int ar[2000001];
    int a,b;cin >> a >> b;
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    sort(ar,ar+n);

    int pnt1 =-1, pnt2 = -1;
    int ans = 0;    
    for(int j = 1; j < n; j++){
        if(ar[0]+ar[j] >= a && ar[0]+ar[j]){
            pnt1 = 0,pnt2 = j;
            break;
        }
    }
    if(pnt2 == -1){
        pnt2 = n-1;
        for(int i = 0; i < n-1; i++){
            if(ar[i] + ar[pnt2] >= a && ar[i]+ar[pnt2] <= b){
                pnt1 = i;
                break;
            }
        }
    }
    if(pnt1 == -1){
        cout << 0 << endl;
        return;
    }

    int cnt = pnt1 + 1;
    // cout << pnt1 << "  " << pnt2 << "   cnt = " << cnt << "    ans = " << ans << endl;
    while(pnt2 < n){
        if(ar[pnt1] + ar[pnt2] > b){
            while(cnt){
                pnt1--;cnt--;
                if(ar[pnt1] + ar[pnt2] <= b)break;
            }
            ans += cnt;
            pnt2++;
            if(cnt == pnt1) break;
        }
        else if(pnt2 - pnt1 == 1){
            pnt2++;
            ans += cnt;
        }else{
            pnt1++;cnt++;
        }
        // cout << pnt1 << "  " << pnt2 << "   cnt = " << cnt << "    ans = ";
        // cout << ans << endl;
    }
    cout << ans << endl;

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