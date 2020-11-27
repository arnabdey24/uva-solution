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
int dr[]={1,1,0,-1,-1,-1,0,1};
int dc[]={0,1,1,1,0,-1,-1,-1};
int t,n,m,q,k,d,tmp;
int l,p;
vector<string> g;
int vis[110][110];
vector<int> lvl;

int solve(int r,int c){
    if(r>=n || r<0 || c>=m || c<0)return 0;
    if(g[r][c]=='L')return 0;
    if(vis[r][c]==1)return 0;
    vis[r][c]=1;
    int ans=1;
    for(int i = 0; i < 8; ++i){
        ans+=solve(r+dr[i],c+dc[i]);
    }
    return ans;
}

int main() {
///<editor-fold desc="ios">
    //IOS
#ifdef _AD_
    filein //fileout
#endif
///</editor-fold>

    int in=1,o;
    cin>>t;
    cin.ignore();getchar();
    while (t--){
        g.clear();
        n=0;m=0;
        string s;
        while (getline(s) && !s.empty()){
            //if(s=="")break;
            //cout<<-1<<endl;
            if(s[0]=='L' || s[0]=='W')g.push_back(s);
            else {
                /*for(auto x : g){
                    cout<<x<<endl;
                }*/
                n=g.size();
                m=g[0].size();
                int x,y;
                stringstream ss(s);
                ss>>x>>y;
                memset(vis,0);
                cout<<solve(x-1,y-1)<<endl;
            }
        }
        if(t)cout<<endl;



    }
    







}