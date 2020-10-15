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

int x=0,n;
int has[20][20];
bitset<30> ld,rd,row;

int check(int r,int c){
    if(has[r][c])return 0;
    if(row[r] || ld[r-c+n-1] || rd[r+c])
        return 0;
    return 1;
}
void search(int c){
    if(c==n){
        x++;
    }
    for(long r = 0; r < n; ++r){
        if(check(r,c)){
            row[r]=ld[r-c+n-1]=rd[r+c]= true;
            search(c+1);
            row[r]=ld[r-c+n-1]=rd[r+c]= false;
        }
    }
}

int main() {
///<editor-fold desc="ios">
    IOS
#ifdef _AD_
    filein //fileout
#endif
///</editor-fold>
    long in=1,o;
    long t,m;
    while (cin>>n,n){
        memset(has,0);
        ld.reset();
        rd.reset();
        row.reset();
        x=0;
        for(long i = 0; i < n; ++i){
            for(long j = 0; j < n; ++j){
                char z;
                cin>>z;
                if(z=='*')has[i][j]=1;
            }
        }
        search(0);
        printcase(x);
    }
}
