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
////////////////////////////////////////////////////////////////////////////</editor-fold>

int n,m,mx,a,b,ans;
vector<pair<int,int>> v;

void cal(int cur,int vis,int count){
    if(count>=n){
        if(cur==b)ans=1;
        return;
    }
    for(int i = 0; i < m; ++i){
        if(!(vis&(1<<i))){
            if(v[i].first==cur)cal(v[i].second,vis|(1<<i),count+1);
            if(v[i].first!=v[i].second && v[i].second==cur)cal(v[i].first,vis|(1<<i),count+1);
        }
    }

}


int main() {
///<editor-fold desc="ios">
    //IOS
#ifdef _AD_
    filein //fileout
#endif
///</editor-fold>
    int in=1,o;
    //int t,n,m,d;
    while (cin>>n,n){
        v.clear();
        ans=0;
        cin>>m;
        cin>>a>>a;
        cin>>b>>mx;
        int x,y;
        for(int i = 0; i < m; ++i){
            cin>>x>>y;
            v.emplace_back(x,y);
        }
        cal(a,0,0);
        printf(ans?"YES\n":"NO\n");

    }




}
