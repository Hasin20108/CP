#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt","r",stdin);   
    
    string s,sletter,sdigit,sother;
    getline(cin,s);
    cout << s << endl;


    int ar[150];
    int word = 1, letters = 0, digits = 0, other = 0;

    int n = s.length();
    bool ok = true;
    for(int i = 0; i < n ;i++){
        if(s[i] == ' '){
            if(ok)word++;
            ok = false;
        }else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            ok = true;
            letters++;
            sletter += s[i];
        }else if(s[i] >= '0' && s[i] <= '9'){
            ok = true;
            digits++;
            sdigit += s[i];
        }else{
            ok = true;
            sother += s[i];
            other++;
        }
    }

    cout << word << " words" << endl;
    cout << "letters = " << letters << "   " << sletter << endl;
    cout << "digits = " << digits << "     " << sdigit << endl;
    cout << "others = " << other << "      " << sother << endl;
       

    return 0;
}