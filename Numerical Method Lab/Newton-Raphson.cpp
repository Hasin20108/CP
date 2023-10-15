#include<bits/stdc++.h>
using namespace std;

class NewtonRaphson{
    public:
    double epsilon = .00001;
    double fx(double n){
        return n*n*n + n*n -1;
    }
    double fxbar(double n){
        return 3*n*n + 2*n;
    }
    void solve(){
        double x = 1000;
        double x1;
        int c = 0;
        while(true){
            // cout << x << endl;
            x1 = x - (fx(x)/fxbar(x));
            // if(fx(x) <= epsilon){
            //     cout << x << endl;
            //     return;
            // }
            if(abs(x1-x) < epsilon){
                cout << x1 << endl;
                break;  
            }
            x = x1;
            // c++;
            // if(c>5000){
            //     cout << "infinity loop\n";
            //     break;
            // }
        }
        
    }

};
int main(){
    NewtonRaphson a;
    a.solve();
    return 0;
}