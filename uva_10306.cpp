#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////////////////////////////<editor-fold desc="macros">
#define endl "\n"
#define long long long
#define all(v) (v).begin(),(v).end()
#define makeset(v) (v).resize(unique((v).begin(),(v).end())-(v).begin())
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define filein freopen("input.txt", "r", stdin);
#define fileout freopen("output.txt", "w", stdout);
#define getline(x) getline(cin,x)
#define makelower(s) transform(s.begin(),s.end(),s.begin(),::tolower)
bool sortby(pair<int,int> a,pair<int,int> b){
    double x=(double )a.first/a.second;
    double y=(double )b.first/b.second;
    return x<y;}
long Pow(long x, long y) {
    if(y == 0)return 1;
    long tmp=Pow(x,y/2);
    tmp*=tmp;
    if(y&1)tmp*=x;
    return tmp;
}
#define printcase(x)  cout<<"Case "<<in++<<": "<<x<<endl
#define memset(a,b) memset(a,b,sizeof(a))
#define print1d(ary) cout<<"[";for(auto x:(ary)){cout<<x<<",";}cout<<"]"<<endl;
#define print2d(x) for(int m = 0; m <sizeof(x)/sizeof(x[0]) ; ++m){for(int l = 0; l <sizeof(x[0])/sizeof(x[0][0]) ; ++l){cout<<x[m][l]<<" ";}cout<<endl;}
#define pi acos(-1)
#define esp 1e-9
////////////////////////////////////////////////////////////////////////////</editor-fold>
long t,n,m,q=0,d;
vector<pair<int,int>> v;
int dp[300][300];

int solve(int w,int p){
    double tmp=hypot(w,p);
    if(tmp>m)return INT16_MAX;
    if(tmp==m){
        q=1;
        return 0;
    }
    if(dp[w][p]!=-1)return dp[w][p];
    int mn=INT16_MAX;
    for(int i = 0; i < n; ++i){
        mn=min(mn,solve(w+v[i].first,p+v[i].second)+1);
    }
    //return min(solve(id+1,w,p),solve(id+1,w+v[id].first,p+v[id].second)+1);
    return dp[w][p]=mn;
}

int main() {
///<editor-fold desc="ios">
     IOS
#ifdef _AD_
    filein //fileout
#endif
///</editor-fold>

    int in=1,o;
    long l,r,p;
    cin>>t;
    while (t--){
        q=0;
        memset(dp,-1);
        v.clear();
        cin>>n>>m;
        for(int i = 0; i < n; ++i){
            cin>>l>>r;
            v.emplace_back(l,r);
        }
        //cout<<INT16_MAX<<endl;
        int ans=solve(0,0);
        if(q)cout<<ans<<endl;
        else cout<<"not possible"<<endl;
    }







}