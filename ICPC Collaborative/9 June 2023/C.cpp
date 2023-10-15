
#include<bits/stdc++.h>
using namespace std;

#define     int     long long int
int32_t main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    while(scanf("%lld" , &n) != EOF){
        // cout << n << endl;
        stack<int> st;
        queue<int> que;
        priority_queue<int>pq;
        int a,b;
        bool stk = true ,quee = true ,priority = true;
        int one = 0, two = 0;
        for(int i = 0; i < n; i++){
            scanf("%lld %lld ",&a,&b);
            // cout << " a = " << a << "  b = " << b << endl;
            if(a == 1)one++;
            else two++;
            if(two > one){
                stk = false;quee = false;priority = false;
            }
            if(a == 1){
                st.push(b);
                que.push(b);
                pq.push(b);
            }else{
                if(stk){
                    if(st.top() == b){
                        st.pop();
                    }else stk = false;
                }
                if(quee){
                    if(que.front() == b){
                        que.pop();
                    }else quee  = false;
                }
                if(priority){
                    if(pq.top() == b){
                        pq.pop();
                    }else priority = false;
                }
            }
        }
        if((stk && quee) || (stk && priority) || (quee && priority)){
            cout << "not sure\n";
        }
        else if(stk) cout << "stack\n";
        else if(quee)cout << "queue\n";
        else if(priority) cout << "priority queue\n";
        else cout << "impossible\n";
    }
    return 0;
}