#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n = 100;
    int a = 5;       
    // cout << "n  -> i%a   i%(a-1)  "<< endl; 
    int t = 0;
    for(int i = 1; i <= n; i++){
        t++;
        if(t%4 == 0) cout << endl;
        cout << i << " -> " << i%a << " " << i%(a-1)  << " > " << abs(i%a - i%(a-1))<< endl; 
    }
    return 0;
}
