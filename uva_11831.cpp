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
int t,n,m,q,k,d,tmp=0;
int dr,dc;
vector<string> g;


int main() {
///<editor-fold desc="ios">
    IOS
#ifdef _AD_
    filein //fileout
#endif
///</editor-fold>

    int in=1,o;
    while (cin>>n>>m>>t && (n||m||t)){
        g.clear();
        string s;
        for(int i = 0; i < n; ++i){
            cin>>s;
            g.push_back(s);
        }
        int x,y;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(g[i][j]=='N' || g[i][j]=='O' || g[i][j]=='L' || g[i][j]=='S'){
                    x=i;y=j;
                    if(g[i][j]=='N')dr=-1,dc=0;
                    if(g[i][j]=='O')dr=0,dc=-1;
                    if(g[i][j]=='S')dr=1,dc=0;
                    if(g[i][j]=='L')dr=0,dc=1;
                    g[i][j]='.';
                }
            }
        }
        tmp=0;
        cin>>s;

        for(int i = 0; i < s.size(); ++i){
            //cout<<x<<" "<<y<<endl;
            //cout<<dr<<" "<<dc<<endl;
            if(s[i]=='D'){
                if(dr==-1 && dc==0)dr=0,dc=1;
                else if(dr==0 && dc==1)dr=1,dc=0;
                else if(dr==1 && dc==0)dr=0,dc=-1;
                else if(dr==0 && dc==-1)dr=-1,dc=0;
            }
            if(s[i]=='E'){
                if(dr==-1 && dc==0)dr=0,dc=-1;
                else if(dr==0 && dc==-1)dr=1,dc=0;
                else if(dr==1 && dc==0)dr=0,dc=1;
                else if(dr==0 && dc==1)dr=-1,dc=0;
            }
            if(s[i]=='F'){
                x+=dr;
                y+=dc;
                if(x<0 || x>=n || y<0 || y>=m)x-=dr,y-=dc;
                if(g[x][y]=='#')x-=dr,y-=dc;
                if(g[x][y]=='*'){
                    g[x][y]='.';
                    tmp++;
                }
            }
        }
        cout<<tmp<<endl;








    }
    







}