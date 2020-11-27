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
long t,n,m,q,tmp,d;
vector<long> p,w;
long dp[102][10300];
long solve(long id,long remW){
    if(remW>n&&n<=1800)return -INT16_MAX;
    if(remW>n+200)return -INT16_MAX;
    if(id==q){
        if(remW>n&&remW<=2000)return -INT16_MAX;
        return 0;
    }
    if(dp[id][remW]!=-1)return dp[id][remW];

    return dp[id][remW]=max(solve(id+1,remW),p[id]+solve(id+1,remW+w[id]));
}

int main() {
///<editor-fold desc="ios">
     IOS
#ifdef _AD_
    filein //fileout
#endif
///</editor-fold>

    int in=1,o;
    while (cin>>n>>q&&(n||q)){
        p.clear();
        w.clear();
        memset(dp,-1);
        for(int i = 0; i < q; ++i){
            int a,b;
            cin>>a>>b;
            w.push_back(a);
            p.push_back(b);
        }
        cout<<solve(0,0)<<endl;


    }





}