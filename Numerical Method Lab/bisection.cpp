#include<bits/stdc++.h>
using namespace std;

class Bisection{
    public:
    double function(double x){
        return (x*x*x) + (x*x) -1;
    }
    double upper,lower;
    double epsilon = .0001;
    void solve(){
        srand(int(time(0)));
        while(true){
            upper = rand()%100;
            lower = rand()%100 - 100;
            if(function(upper) * function(lower) <= 0){
                break;
            }
        }
        double mid;
        int c= 0;
        while(true){
            mid = (lower + upper)/2;
            if(abs(function(mid)) < epsilon){
                // cout << "function = " << function(mid) << endl;
                cout <<"ans = " <<  mid << endl;
                break;
            }
            if(function(mid)*function(lower) > 0){
                lower = mid;
            }else{
                upper = mid;
            }
            c++;
            if(c > 50){
                cout << "infinity loop\n";
                break;
            }
        }
    }  
};
int main(){
    Bisection bisection;
    bisection.solve();

    return 0;
}