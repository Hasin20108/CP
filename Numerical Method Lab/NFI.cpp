#include<iostream>
using namespace std;

class NFI{
    public:
    int n;
    long double u,t,p,h;
    long double x[1000] , y[1000][1000];
    void input(){
        cin >> n >> t;
        for(int i = 0; i < n ;i++){
            cin >> x[i] >> y[0][i];
        }
    }
    void solve(){
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n-i; j++){
                y[i][j] = y[i-1][j+1] - y[i-1][j];
            }
        }
        int save;
        for(int i = 0; i < n; i++){
            if(x[i] > t){p = x[i-1];save = i-1;break;}

        }
        h = x[1] - x[0];
        u = (t - x[0])/h;
        double temp = u;
        double ans = y[0][save];
        for(int i = 1; i < n; i++){
            // cout << "u = " << temp << endl;
            ans += (temp*y[i][0]);
            // cout << temp << "*(" << u << "-" << i << ")/" << t+1 << endl;
            temp = temp*((u-i)/(i+1));
        }
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n-i; j++){
        //         cout << y[i][j] << " ";
        //     }cout << endl;
        // }
        // cout << endl;
        cout << "answer = " << ans << endl;

    }

};

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt","r",stdin);
    NFI x;
    x.input();
    x.solve();
    return 0;
}