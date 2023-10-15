#include<bits/stdc++.h>
using namespace std;

int y,ymin,xmin;
bool comp(pair<int,int> x, pair<int,int> y){
    float z = ((x.first - xmin) * (y.second - ymin) - (x.second  - ymin)* (y.first - xmin));
    if( z > 0) return true;
    if( z < 0) return false;
    else{
       return (x.first + x.second < y.first + y.second) ? true: false;
    }
}

bool check(pair<int,int> x, pair<int,int> y, pair<int,int> a){
    float z = ((x.first - a.first) * (y.second - a.second) - (x.second  - a.second)* (y.first - a.first));
    if(z < 0)return  false;
    else return true;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    freopen("/media/hasin/New Volume/DESKTOP/desktop files/CP/input.txt","r",stdin);   
    
    vector<pair<int,int>> points;
    int x,y;
    int n;
    cin >> n;
    for(int i = 0; i < n ;i++){
        cin >> x >> y;
        points.push_back({x,y});
    }
    ymin = points[0].second;
    xmin = points[0].first;
    for(int i = 1; i < n; i++){
        y = points[i].second;
        if(y<= ymin){
            ymin = y;
            xmin = points[i].first;
            swap(points[i],points[0]);
        }  
    }

    sort(points.begin() +1 ,points.end(),comp);
    stack<pair<int,int>> s;
    s.push(points[0]);
    s.push(points[1]);
    s.push(points[2]);
    pair<int,int> t,ref;
    for(int i = 3; i < n; i++){
        t = s.top();
        s.pop();
        ref = s.top();
        while(check(points[i],t,ref)){
            t = s.top();
            s.pop();
            ref = s.top();
        }
        s.push(t);
        s.push(points[i]);
    }
    while(!s.empty()){
        cout << s.top().first << " " << s.top().second << endl;
        s.pop();
    }
    return 0;
}