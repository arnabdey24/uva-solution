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
vector<long> v;
long dp[210][22][11];
long solve(long id,long sum,long count){
    if(count==m)return (sum==0);
    if(id>=n)return 0;
    if(dp[id][sum][count]!=-1)return dp[id][sum][count];
    long a=solve(id+1,sum%d,count);
    tmp=sum;
    tmp+=v[id];
    tmp%=d;
    if(tmp<0)tmp+=d;
    long b=solve(id+1,tmp,count+1);
    return dp[id][sum][count]=a+b;

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
        printf("SET %d:\n",in++);
        v.clear();
        for(int i = 0; i < n; ++i){
            cin>>tmp;
            v.push_back(tmp);
        }
        for(int i = 0; i < q; ++i){
            cin>>d>>m;
            memset(dp,-1);
            printf("QUERY %d: %lld\n",i+1,solve(0,0,0));
            //cout<<solve(0,0,0)<<endl;
        }


    }





}