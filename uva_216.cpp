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


int main() {
///<editor-fold desc="ios">
     IOS
#ifdef _AD_
    filein //fileout
#endif
///</editor-fold>

    int in=1,o;
    long l,r,p;
    while (cin>>n,n){
        printf("**********************************************************\n");
        printf("Network #%d\n",in++);
        v.clear();
        for(int i = 0; i < n; ++i){
            cin>>l>>r;
            v.emplace_back(l,r);
        }
        vector<int> x,ans;
        for(int i = 0; i < n; ++i){
            x.push_back(i);
        }
        double mn=INT32_MAX;
        do {
            double dis=0;
            for(int i = 1; i < n; ++i){
                dis+=hypot(abs(v[x[i-1]].first-v[x[i]].first),abs(v[x[i-1]].second-v[x[i]].second))+16;
            }
            if(dis<mn){
                mn=dis;
                ans=x;
            }
        }while (next_permutation(all(x)));
        for(int i = 1; i <n ; ++i){
            double tt=hypot(abs(v[ans[i-1]].first-v[ans[i]].first),abs(v[ans[i-1]].second-v[ans[i]].second))+16;
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",v[ans[i-1]].first,v[ans[i-1]].second,v[ans[i]].first,v[ans[i]].second,tt);
        }
        printf("Number of feet of cable required is %.2lf.\n",mn);
    }







}