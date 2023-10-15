#include<bits/stdc++.h>
using namespace std;

class secant{
    public:
    double f(double x){
        return (x*x*x) + (x*x) -1;
    }
    double a,b;
    void solve(){
        while(true){
            a = rand()%100;
            b = rand()%100 - 100;
            if(f(a) * f(b) <= 0){
                break;
            }
        }
        double c;
        int d= 0;
        while(true){
            c = b - ((b-a)/(f(b)-f(a))) * f(b);
            if(c == b){
                cout << b << endl;
                break;
            }else{
                a = b;
                b = c;
            }
            d++;
            if(d > 50){
                cout << "infinity loop\n";
                break;
            }
        }
    }  
};
int main(){
    secant secant;
    secant.solve();

    return 0;
}