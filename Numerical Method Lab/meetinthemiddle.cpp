#include<bits/stdc++.h>
using namespace std;

vector<int> v,v1,v2;
map<int,int> mp1,mp2;
int n;
void first(int sum , int i){
    mp1[sum] = 1;
    if(i >= n/2){
        return;
    }
    first(sum,i+1);
    first(sum+v[i],i+1);
}

void second(int sum, int i){
    mp2[sum] = 1;
    if(i >= n){
        return;
    }
    second(sum,i+1);
    second(sum+v[i],i+1);
}

void solve(){
    int a,b,x;
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    cout << lower_bound(v.begin(),v.end(),3) - v.begin() << endl;
    cout << upper_bound(v.begin(),v.end(),3) - v.begin() << endl;
    
    first(0,0);
    second(0,n/2);
    
    
}


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt","r",stdin);   
    solve();

    return 0;
}