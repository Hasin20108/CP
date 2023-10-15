#include<bits/stdc++.h>
using namespace std;

class GaussEle{
    private:
    int n;
    double ar[100][101];
    int x[100];
    public:
    void print(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= n; j++){
                cout << ar[i][j] << " ";
            }
            cout << endl;
        }
    }
    void solve(){
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= n; j++){
                cin >> ar[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(ar[i][i] == 0){
                    cout <<"Wrong input\n";
                    return ;
                }
                double ratio = ar[j][i]/ar[i][i];
                for(int k = 0; k <= n; k++){
                    ar[j][k] -= (ratio*ar[i][k]);
                }
            }
        }

        for(int i = n-1; i >= 0; i--){
            for(int j = i-1; j >= 0 ; j--){
                if(ar[i][i] == 0){
                    cout <<"Wrong input\n";
                    return ;
                }
                double ratio = ar[i][i]/ar[j][i];
                for(int k = 0; k <= n; k++){
                    ar[j][k] -= (ar[i][k]/ratio);
                }
            }
        }
        print();
        
        for(int i = 0; i < n; i++){
            x[i] = ar[i][n]/ar[i][i];
        }
        for(int i = 0; i < n; i++){
            cout << "x[" << i << "] = " << x[i] << endl;
        }

    }
    

};

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt","r",stdin);   

    GaussEle ge;
    ge.solve();
    return 0;
}