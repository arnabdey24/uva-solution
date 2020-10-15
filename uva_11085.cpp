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

long x=0,n;
int board[8][8];
bitset<30> ld,rd,row;
vector<vector<int>> v;
vector<int> rowTmp(8);

int check(int r,int c){
    if(row[r] || ld[r-c+8-1] || rd[r+c])
        return 0;
    return 1;
}
void search(int c){
    if(c==8){
        v.push_back(rowTmp);
        x++;
    }
    for(long r = 0; r < 8; ++r){
        if(check(r,c)){
            rowTmp[c]=r+1;
            row[r]=ld[r-c+8-1]=rd[r+c]= true;
            search(c+1);
            row[r]=ld[r-c+8-1]=rd[r+c]= false;
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
    search(0);
    int rw[8];
    while (cin>>rw[0]){
        for(long i = 1; i < 8; ++i){
            cin>>rw[i];
        }
        long ans=LONG_LONG_MAX;
        for(auto z : v){
            long tmp=0;
            for(long i = 0; i < 8; ++i){
                if(abs(rw[i]-z[i])!=0)tmp++;
            }
            ans=min(ans,tmp);
        }
        printcase(ans);

    }

}
