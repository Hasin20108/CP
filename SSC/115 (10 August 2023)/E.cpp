
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define    rep      for(int i = 0; i < n; i++)
#define    repi     for(int i = a; i < n; i++)
#define    yes      cout << "YES\n"
#define    no       cout << "NO\n"
#define    endl     '\n'
#define    inar    int ar[200001],n; cin>>n;for(int i = 1; i <= n;i++)cin>> ar[i];
const int mod = 998244353;


string reverse(string str){string s;for (int i = str.length() - 1; i >= 0; i--){s += str[i];}return s;}
bool palindrome(string s){string tem = reverse(s);return tem == s;}
string lower(string s){int n = s.length();rep{if(s[i] < 'a'){char ch = s[i] + 'a' - 'A' ;s[i] = ch;}}return s;}
string upper(string s){int n = s.length();rep{if(s[i] >= 'a'){char ch = s[i] + 'A' - 'a' ;s[i] = ch;}}return s;}
bool comp(pair<int ,int> t, pair<int, int> p){return t.first< p.first ;}
int nextsquare(int n){float t = sqrt(n);int x = ceil(t);return x*x;}
bool rev(int x, int y){return x > y;}
int myceil(double x){int t = x;if(x*10 > t*10){return t+1;}else{return t;}}
int power(int x, int y){int ans = 1;while(y--){ans *= x;ans %= mod;}return ans;}
int dectobin(int x){int ans = 0;int n = log2(x) + 1;int temp;for(int i = 0; i < n; i++){temp = ((x & power(2,i)) != 0);temp = temp* power(10,i);ans += temp;}return ans;}
int gcd(int a, int b) {if (b == 0) {return a;}return gcd(b, a % b);}
int lcm(int a, int b) {return (a * b) / gcd(a, b);}
int dig(int temp){int sum = 0;while (temp != 0) {temp = temp / 10;sum++;}return sum;}
int uniq(string s){int n = s.length();set<char>t;rep{t.insert(s[i]);}return t.size();}
int digSum(int x){int sum = 0;while(x){sum += x%10;x = x/10;}return sum;}

ll n,m,cnt,x,y;
ll ar[200005],size1[200005];

vector<ll>ans;
struct node{
	ll x,y;
	node(){
		
	}
	node(ll nx,ll ny){
		x=nx;
		y=ny;
	}
};
vector<node>point;
ll khojo(ll x){
	if(ar[x]==x){
		return x;
	}else{
		return ar[x]=khojo(ar[x]);
	}
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		ar[i]=i;
		size1[i]=1;
	}
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		point.push_back(node(x,y));
	}
	cnt=n*(n-1)/2;
	for(int i=point.size()-1;i>=0;i--){
		x=point[i].x;
		y=point[i].y;
		ans.push_back(cnt);
		if(khojo(x)!=khojo(y)){
			cnt-=(size1[khojo(x)]*size1[khojo(y)]);
			//cout<<size[khojo(x)]<<" "<<size[khojo(y)]<<"\n";
			size1[khojo(y)]+=size1[khojo(x)];
			ar[khojo(x)]=khojo(y);
		}
	}
	for(int i=ans.size()-1;i>=0;i--){
		cout<<ans[i]<<"\n";
	}
} 

int32_t main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt","r",stdin);   
    // freopen("output.txt","w",stdout);
    #endif
    int t = 1;  
    // cin >> t;
    int i = 1;
    while(t--){
        solve();
    }
    return 0;
}