#include<iostream>
using namespace std;

class simpson{
    public:
    long double a = 0,b = 1, n = 10;
    long double delx = (b-a)/n;
    long double ans = 0;
    long double f(long double x){
        return 1/x;
    }
    void solve(){
        for(int i = 0; i <= n; i+= 1){
            if(i == 0 ||  i == n){
                ans += f(a + ((long double)i*delx));
            }else{
                if(i%2 == 0){
                    ans += 2*(f(a + ((long double)i*delx)));
                }else{
                    ans += 4*(f(a + ((long double)i*delx)));
                }
            }
        }
        ans = (delx*ans)/3; 
        cout << ans << endl;
    }

    
};

int main(){
    simpson s;
    s.solve();

    return 0;
}