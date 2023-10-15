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

void solve(){
  string s[] = {"millu","rongon","likhon","arman"};
  int mulla,sayed,neon,fahim;
  int x;
  int t = 5;
  while(t--){
    // cout << "enter iteration time : ";
    cin >> x;
    if(x == -1)break;
    for(int i = 0; i < x; i++){
      mulla = rand() % 4;
      while(true){
        sayed = rand() % 4;
        if(sayed != mulla){
          break;
        }
      }
      while(true){
        neon = rand() % 4;
        if(neon != sayed && neon != mulla){
          break;
        }
      }
      while(true){
        fahim = rand()%4;
        if(fahim != neon && fahim != mulla && fahim != sayed){
          break;
        }
      }
    }
  }
  cout << "Mulla = " << s[mulla] << endl;
  cout << "neon = " << s[neon] << endl;
  cout << "sayed = " << s[sayed] << endl;
  cout << "fahin = " << s[fahim] << endl;

  // cout << endl;
  // int x = 10;
  // while(x--){
  //   cout << rand() % 100 << endl;
  // }
}   


int32_t main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt","r",stdin);   
    // freopen("output.txt","w",stdout);
    #endif
    int t = 1;  
    // cin >> t;
    int i = 1;
    while(t--){
        solve();
    }
    return 0;
}