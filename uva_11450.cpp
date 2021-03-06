#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////////////////////////////<editor-fold desc="macros">
#define endl "\n"
//#define long long long
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
long long t,n,m,q,tmp;
int p[25][25];
int memo[210][25];
int solve(int money,int c){
    if(money>m)return -INT32_MAX;
    if(c==q)return money;
    if(memo[money][c]!=-1)return memo[money][c];
    int mx=-1;
    for(int i = 1; i <=p[c][0] ; ++i){
        mx=max(mx,solve(money+p[c][i],c+1));
    }
    return memo[money][c]=mx;
}
int main() {
///<editor-fold desc="ios">
    IOS
#ifdef _AD_
    filein //fileout
#endif
///</editor-fold>
    int in=1,o;
    cin>>t;
    while (t--){
        memset(memo,-1);
        cin>>m>>q;
        for(int i = 0; i < q; ++i){
            cin>>p[i][0];
            for(int j = 1; j <= p[i][0]; ++j){
                cin>>p[i][j];
            }
        }
        int ans=solve(0,0);
        if(ans<0)cout<<"no solution"<<endl;
        else cout<<ans<<endl;

    }





}
