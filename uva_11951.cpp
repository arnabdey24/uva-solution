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


int main() {
///<editor-fold desc="ios">
    IOS
#ifdef _AD_
    filein //fileout
#endif
///</editor-fold>
    long t,m,n,q,tmp;
    int in=1,o;
    cin>>t;
    while (t--){
        cin>>n>>m>>q;
        long a[n][m];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin>>a[i][j];
                if(i>0)a[i][j]+=a[i-1][j];
                if(j>0)a[i][j]+=a[i][j-1];
                if(i>0&&j>0)a[i][j]-=a[i-1][j-1];
            }
        }

        long mx=0,mxSize=0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                for(int k = i; k < n; ++k){
                    for(int l = j; l < m; ++l){
                        tmp=a[k][l];
                        if(i>0)tmp-=a[i-1][l];
                        if(j>0)tmp-=a[k][j-1];
                        if(i>0&&j>0)tmp+=a[i-1][j-1];
                        int size=(k-i+1)*(l-j+1);
                        //cout<<size<<" "<<tmp<<endl;
                        if(size>mxSize&&tmp<=q){
                            mxSize=size;
                            mx=tmp;
                        }
                        if(size>=mxSize&&tmp<=q){
                            mx=min(tmp,mx);
                        }
                    }
                }
            }
        }
        printf("Case #%d: %d %d\n",in++,mxSize,mx);


    }





}