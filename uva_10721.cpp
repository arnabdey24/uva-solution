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
vector<pair<int,int>> v;
long dp[51][51][51][51];
long solve(int at,int count,int cur,int last){
    if(cur>m || count>k)return 0;
    if(at==n){
        if(count==k)return 1;
        else return 0;
    }
    if(dp[at][count][cur][last]!=-1)return dp[at][count][cur][last];
    if(at==0)return dp[at][count][cur][last]=solve(1,1,1,1);
    else {
        long t1=0,t2=0;
        if(last==1)t1=solve(at+1,count,cur+1,last);
        else t1=solve(at+1,count+1,1,1);

        if(last==0)t2=solve(at+1,count,cur+1,last);
        else t2=solve(at+1,count+1,1,0);

        return dp[at][count][cur][last]=t1+t2;
    }



}

int main() {
///<editor-fold desc="ios">
     IOS
#ifdef _AD_
    filein //fileout
#endif
///</editor-fold>

    int in=1,o;
    //cin>>t;
    while (cin>>n>>k>>m){
        memset(dp,-1);
        cout<<solve(0,0,0,0)<<endl;

    }







}