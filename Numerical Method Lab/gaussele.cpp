#include<bits/stdc++.h>
using namespace std;

class GE{
    public:
    double a[100][101];
    int n;
    double x[100];
    void input(){
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n+1; j++){
                cin >> a[i][j];
            }
        }

    }
    void eschelon(){
        for(int i = 0; i < n-1; i++){
            if(a[i][i] == 0){
                cout << "invalid" << endl;
            }
            for(int j = i+1; j < n; j++){
                double ratio = a[j][i]/a[i][i];
                for(int k = 0; k <n+1; k++){
                    a[j][k] -= ratio*a[i][k]; 
                }
            }
        }
    }
    void print(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n+1; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    void ans(){

        for(int i = n-1; i >= 0; i--){
            double sum = 0;
            for(int j = i+1; j <n; j++){
                sum += x[j]*a[i][j];
            }
            x[i] = (a[i][n]-sum)/a[i][i];
        }

        for(int i = 0; i < n; i++){
            cout << "x[" << i << "] = " << x[i] << endl;
        }
    }
    void solve(){
        input();
        eschelon();
        print();
        ans();
    }

};

int main(){
    freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt","r",stdin);   
    GE ge;
    ge.solve();
}