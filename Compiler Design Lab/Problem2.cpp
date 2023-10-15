#include<bits/stdc++.h>
using namespace std;

char low(char ch){
    if(ch >= 'A' && ch <= 'Z')ch = 'a' + ch - 'A'; 
    return ch;
}
bool vol(char ch){
    ch = low(ch);
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
        return true;
    }else return false;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt","r",stdin);   

    string s;
    getline(cin,s);
    int n = s.length();
    set<char>vowels,consonents;
    int tvow = 0,tcon = 0;
    vector<string> vword,cword;
    string t;
    for(int i = 0; i < n; i++){
       if(s[i] != ' '){
            t += s[i];
       }else{
            if(vol(t[0])){
                vword.push_back(t);
            }else  if(low(t[0]) >= 'a'  && low(t[0]) <= 'z'){
                cword.push_back(t);
            }
            t.clear();
       }

       if(vol(s[i])){
            vowels.insert(low(s[i]));
            tvow++;
       }else if(low(s[i]) >= 'a'  && low(s[i]) <= 'z'){
            consonents.insert(low(s[i]));
            tcon++;
       }

    }
    cout << "total vowel = " << tvow << "    ";
    for(auto t : vowels){
        cout << t;
    }cout << endl;

    cout << "total consonant = " << tcon << "    ";
    for(auto t : consonents){
        cout << t;
    }cout << endl;
    
    cout  << "words starts with vowel :   ";
    for(auto t: vword){
        cout << t << " ";
    }cout << endl;
    cout  << "words starts with consonant :   ";
    for(auto t: cword){
        cout << t << " ";
    }cout << endl;
    
    return 0;
}