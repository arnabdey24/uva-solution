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
int t,n,m,q,k,d,tmp;
int l,r,p;
int wind[12][1010];
long dp[12][1010];
long solve(int alt,int lng){
    if(alt>9 || alt<0) return INT32_MAX;
    if(lng==n){
        if(alt==0)return 0;
        else return INT32_MAX;
    }
    if(dp[alt][lng]!=-1)return dp[alt][lng];


    return dp[alt][lng]=min(60-wind[alt][lng]+solve(alt+1,lng+1),
               min(30-wind[alt][lng]+solve(alt,lng+1),20-wind[alt][lng]+solve(alt-1,lng+1)));


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
        memset(dp,-1);
        cin>>n;
        n/=100;
        for(int i = 9; i >=0 ; --i){
            for(int j = 0; j < n; ++j){
                cin>>wind[i][j];
            }
        }
        cout<<solve(0,0)<<endl;
        cout<<endl;



    }







}