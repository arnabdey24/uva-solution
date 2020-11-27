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


int main() {
///<editor-fold desc="ios">
     IOS
#ifdef _AD_
    filein //fileout
#endif
///</editor-fold>

    int in=1,o;
    while (cin>>n){
        long dp[n+1],coins[]={1,5,10,25,50};
        memset(dp,0);
        dp[0]=1;
        for(int j = 0; j < 5; ++j){
            for(int i = 1; i <=n; ++i){
                if((i-coins[j])>=0){
                    dp[i]+=dp[i-coins[j]];
                }
            }
        }
        if(dp[n]==1)printf("There is only %lld way to produce %d cents change.\n",dp[n],n);
        else printf("There are %lld ways to produce %d cents change.\n",dp[n],n);

    }





}