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
int t,n,m,q,d,tmp;
int l,r,p;
vector<pair<int,int>> v;
int solve(int mask,int at){
    if(__builtin_popcount(mask)==q+1){
        return abs(v[0].first-v[at].first)+abs(v[0].second-v[at].second);
    }
    int mn=INT16_MAX;
    for(int i = 0; i <= q; ++i){
        if((mask&(1<<i))==0){
            mn=min(mn,solve(mask|(1<<i),i)+abs(v[i].first-v[at].first)+abs(v[i].second-v[at].second));
        }
    }
    return mn;
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
        v.clear();
        cin>>n>>m;
        cin>>l>>r;
        v.emplace_back(l,r);
        cin>>q;
        for(int i = 0; i < q; ++i){
            int a,b;
            cin>>a>>b;
            v.emplace_back(a,b);
        }
        printf("The shortest path has length %d\n",solve(0|(1<<0),0));
        //cout<<<<endl;

    }







}