#include<bits/stdc++.h>
using namespace std;

class simpsons{
    private:
    double n,u,l;
    double func(double x){
        return (1/(1+(x*x)));
    }
    public:
    void solve(){
        cout << "Enter the Lower Limit -->  ";cin >> l;cout << endl;
        cout <<"Enter the upper Limit -->  ";cin >> u;cout << endl;
        cout <<"Enter the value of n -->  ";cin >> n;cout << endl;
        double h = (u-l)/n;
        double ans = 0;

        for(int i = 0; i <= (int)n; i++){
            if(i == 0){
                ans += func(l);
            }else if(i == n){
                ans += func(l);
            }else if(i%2 == 1){
                ans += 4*func(l);
            }else{
                ans += 2*func(l);
            }
            l+= h;
        }
        ans = ans*h/3;
        cout << "Integrations value is -->  " <<  ans << endl;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt","r",stdin);   
    
    
    simpsons smp;
    smp.solve();
    
    return 0;
}


// #include <bits/stdc++.h>

// using namespace std;

// class Simpson {

//     public:

//     double function(double x) {
//         return (1 / (1 + pow(x, 2)));
//     }

//     void solve() {

//         double l, u, n, h;

//         cout << "Enter lower limit: ";
//         cin >> l;
//         cout << "Enter upper limit: ";
//         cin >> u;

//         cout << "Enter sub-interval: ";
//         cin >> n;

//         // step size 
//         h = (u-l) / n;

//         // integration
//         double i = function(l);  // integration -> i;

//         for(int j = 1; j < n; j++) {
//             double k = l + j*h;   // k = l + j*h; -> xi = a + i*del(x);
//             if(j%2 == 0) {
//                 i = i + 2 * function(k);
//             } else {
//                 i = i + 4 * function(k);
//             }
//         }

//         i = i + function(u);
//         i = i * h/3;

//         cout<< endl << "Required value of integration is: " << i << endl << endl;

//     }
        
// };

// int main() {
//     Simpson simpson;
//     simpson.solve();

//     return 0;

// }