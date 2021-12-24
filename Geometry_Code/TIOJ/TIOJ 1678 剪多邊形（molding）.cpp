#include <bits/stdc++.h>
#define Orz ios::sync_with_stdio(0),cin.tie(0)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define pdd pair<double,double>
#define int long long
#define ll long long
#define ld long double
#define N 100001
#define all(x) x.begin(),x.end()
#define eps 1e-9
#define x first
#define y second

using namespace std;

struct pt{
    int x,y;
    bool operator < (pt b){
        if(x == b.x)return y < b.y;
        return x < b.x;
    }
    bool operator > (pt b){
        if(x == b.x)return y > b.y;
        return x > b.x;
    }
    bool operator == (pt b){
        if(x-b.x == 0 && y-b.y == 0)return true;
        return false;
    }
    pt operator+(pt b) {return {x + b.x, y + b.y};} //向量相加
    pt operator-(pt b) {return {x - b.x, y - b.y};} //向量相減
    int operator^(pt b) {return x * b.y - y * b.x;} //向量外積cross
    int operator*(pt b) {return x * b.x + y * b.y;} //向量內積dot
};

vector<pt> p,temp,pp;
vector<int>  cnt;
int n,a,ans = 0;

bool cmp(pt a, pt b){
    if(a.x == b.x)return a.y < b.y;
    return a.x < b.x;
}

bool check(pt a,pt b,pt o){
    pt aa = a - o;
    pt bb = b - o;
    return (aa^bb) >= 0;
}

vector<pt> solve(){
    sort(all(p),cmp);
    vector<pt> h;
    for(pt i : p){
        while(h.size()>=2 && check(i,h[h.size()-1],h[h.size()-2]))
            h.pop_back();
        h.push_back(i);
    }
    int sz = h.size();
    h.pop_back();
    reverse(all(p));
    for(auto i : p){
        while(h.size()>sz && check(i,h[h.size()-1],h[h.size()-2]))
            h.pop_back();
        h.push_back(i);
    }
    return h;
}

int Polygon(){
    vector<pt> temp(p);
    temp.push_back(temp[0]);
    int area = 0;
    rep(i,0,n-1)area += (temp[i]^temp[i+1]);
    return abs(area);
}

signed main(){
    Orz;
    cin>>n>>a;
    p.resize(n,{0,0});
    rep(i,0,n-1)cin>>p[i].x>>p[i].y;
    ld small = (ld)Polygon()/2;
    vector<pt> hull = solve();
    int area = 0,sz = hull.size();
    rep(i,0,sz-2)area += (hull[i]^hull[i+1]);
    ld big = (ld)area/2;
    int ans = ceil((big-small)/a);
    cout<<ans<<endl;
}