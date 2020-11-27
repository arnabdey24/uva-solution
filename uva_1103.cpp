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
int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};
map<char,string> h2b={{'0',"0000"},{'1',"0001"},{'2',"0010"},{'3',"0011"},{'4',"0100"},{'5',"0101"},{'6',"0110"},{'7',"0111"},{'8',"1000"},{'9',"1001"},{'a',"1010"},{'b',"1011"},{'c',"1100"},{'d',"1101"},{'e',"1110"},{'f',"1111"}};
map<int,char> n2c={{1,'A'},{3,'J'},{5,'D'},{4,'S'},{0,'W'},{2,'K'}};
int t,n,m,q,k,d,tmp=0;
int l,p;
vector<string> g;

void solve(int r,int c){
    if(r>n+1 || r<0 || c>m+1 || c<0)return;
    if(g[r][c]!='0')return;
    //cout<<r<<" "<<c<<" "<<g[r][c]<<endl;
    g[r][c]='.';
    for(int i = 0; i < 4; ++i){
        solve(r+dr[i],c+dc[i]);
    }
}
void solve2(int r,int c){
    if(r>n+1 || r<0 || c>m+1 || c<0)return;
    if(g[r][c]=='.')return;
    if(g[r][c]=='1') {
        g[r][c]='.';
        for(int i = 0; i < 4; ++i){
            solve2(r+dr[i],c+dc[i]);
        }
    }
    if(g[r][c]=='0'){
        tmp++;
        solve(r,c);
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
    while (cin>>n>>m && (n||m)){
        g.clear();
        string tt;
        for(int i = 0; i <=m*4+1 ; ++i){
            tt+='0';
        }
        g.push_back(tt);
        for(int i = 0; i < n; ++i){
            string s,tx="0";
            cin>>s;
            for(int j = 0; j < s.size(); ++j){
                tx.append(h2b[s[j]]);
            }
            tx+='0';
            g.push_back(tx);
        }
        g.push_back(tt);
        m*=4;

        solve(0,0);
        /*for(auto x : g){
            cout<<x<<endl;
        }*/
        string ans;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <=m ; ++j){
                if(g[i][j]=='1'){
                    tmp=0;
                    solve2(i,j);
                    ans+=n2c[tmp];
                }
            }
        }
        sort(all(ans));
        printcase(ans);






    }
    







}