#include<iostream>
using namespace std;

int main (){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    int n,m,x,y,d;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> x >> y>> d;
        // cout << n << m << x << y << d << endl;
        if(x+d >= n && x-d <= 1){
            cout << -1 << endl;
        }else if(y+d >= m && y-d <= 1){
            cout << -1 << endl;
        }else if(x-d <= 1 && y-d <= 1){
            cout << -1 << endl;
        }else if(x+d >= n && y+d >= m){
            cout << -1 << endl;
        }
        else if(abs(n-x) + abs(m-y) <= d){
            cout << -1 << endl;

        }
        else{
            cout << n+m-2 << endl;
        }
    }
    return 0;
}