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
vector<int> g[110];
int vis[110],cnt[110];
vector<int> lvl;
void dfs(int a){
    cnt[a]=1;
    for(auto x : g[a]){
        if(!cnt[x])dfs(x);
    }
}
void solve(int a,int b){
    if(a==b)return;
    vis[a]=1;
    for(auto x : g[a]){
        if(!vis[x])solve(x,b);
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
    cin>>t;
    while (t--){
        cout<<"Case "<<in++<<":"<<endl;
        memset(g,0);
        memset(cnt,0);
        cin>>n;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin>>tmp;
                if(tmp)g[i].push_back(j);
            }
        }
        dfs(0);
        string z="+";
        for(int j = 0; j < n*2-1; ++j){
            z+='-';
        }
        z+='+';
        //print1d(cnt)
        for(int i = 0; i < n; ++i){
            cout<<z<<endl;
            cout<<"|";
            memset(vis,0);
            solve(0,i);
            for(int j = 0; j < n; ++j){
                if(cnt[j] && !vis[j])cout<<'Y'<<"|";
                else cout<<'N'<<"|";
            }
            cout<<endl;
        }

        cout<<z<<endl;
    }
    







}