#include<bits/stdc++.h>
using namespace std;

class Trape{
    private:
    double n,u,l;
    double func(double x){
        return (1/(1+x*x));
    }
    public:
    void solve(){
        cout << "Enter the Lower Limit -->  ";cin >> l;cout << l;cout << endl;
        cout <<"Enter the upper Limit -->  ";cin >> u;cout << u;cout << endl;
        cout <<"Enter the value of n -->  ";cin >> n;cout << n << endl;
        double h = (u-l)/n;
        double ans = 0;

        for(int i = 0; i <= (int)n; i++){
            if(i == 0){
                ans += (func(l)/2);
            }else if(i == n){
                ans += (func(l)/2);
            }else{
                ans += func(l);
            }
            l+= h;
        }
        ans *= h;
        cout << "Integrations value is -->  " <<  ans << endl;
    }
    
};

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt","r",stdin);   
    Trape tp;
    tp.solve();
    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// class Trapezoidal {

//     public:

//     // double function(double x) {
//     //     return (1 / (1 + pow(x, 2)));
//     // }

//     double function(double x) {
//         return (1/(1+x*x));
//     }
    
//     double a, b, n, h;

//     Trapezoidal() {

//         cout << "Enter lower limit: ";
//         cin >> a;
//         cout << "Enter upper limit: ";
//         cin >> b;

//         cout << "Enter sub-interval: ";
//         cin >> n;
//     }

//     void solve() {

//     // step size
//     h = (b-a) / n;

//     // integrated value
//     double i_val = function(a);
//     for(int i = 1; i < n; i++) {
//         double x = a + i*h;
//         i_val += 2*function(x);
//     }

//     i_val += function(b);

//     i_val = (i_val * h) / 2;

//     cout<< endl << "Required value of integration is: " << i_val;

//     }
        
// };

// int main() {

//     Trapezoidal trapezoidal;
//     trapezoidal.solve();

//     return 0;

// }