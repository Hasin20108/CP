
    int tt = needle.length();
    int n = haystack.length();
    char ch = haystack[0], ch1;
    for(int i = 1; i < n-tt+1; i++){
        ch1 = haystack[i+tt-1];
        int p = hashing2(fst,ch,ch1,tt);
        if(p == pat){
            if(chek(haystack.substr(i,tt),needle)){
                return i;
            }
        }
        ch = haystack[i];
        fst = p;
    }
    return -1;
}
int digSum(int x){
    int sum = 0;
    while(x){
        sum += x%10;
        x = x/10;
    }
    return sum;
}
int arr[200001];
int parent[200001];
int find(int v){
if(v == parent[v]) return v;
return find(parent[v]);
}
void join(int a, int b){
a = find(a);
b = find(b);
if(a != b){
parent[b] = a;
}
}
void solve(){
    vector<int>p;
    map<int,int>mp;
    int n,a,b;
    cin >> n;