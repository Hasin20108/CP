#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,int> mp1,mp2;
int a,b,ar[200],n,m,res = 0;

void rec(int sum , int z){
    if(z == a){
        mp1[sum]++;
        return; 
    }
    rec(sum , z+1);
    rec(sum + ar[z], z+1);
}

void rec2(int sum, int z){
    if(z == n){
        if(m>= sum) res += mp1[m-sum];
        return;
    }
    rec2(sum, z+1);
    rec2(sum+ar[z],z+1);
}

int32_t main(){
    // freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt","r",stdin);   
    cin >> n >> m;
    for(int i = 0; i < n ;i++){
        cin >> ar[i];
    }
    a = n/2;
    rec(0,0);
    rec2(0,a);
    cout << res << endl;
    return 0;
}