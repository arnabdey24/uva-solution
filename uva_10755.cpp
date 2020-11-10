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
        long a[n][m][q];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                for(int k = 0; k < q; ++k){
                    cin>>tmp;
                    if(k>0)tmp+=a[i][j][k-1];
                    if(j>0)tmp+=a[i][j-1][k];
                    if(i>0)tmp+=a[i-1][j][k];
                    if(i>0&&j>0)tmp-=a[i-1][j-1][k];
                    if(i>0&&k>0)tmp-=a[i-1][j][k-1];
                    if(k>0&&j>0)tmp-=a[i][j-1][k-1];
                    if(i>0&&j>0&&k>0)tmp+=a[i-1][j-1][k-1];
                    a[i][j][k]=tmp;
                    //cout<<tmp<<endl;
                }
            }
        }

        long mx=-LONG_LONG_MAX;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                for(int k = 0; k < q; ++k){
                    for(int x = i; x < n; ++x){
                        for(int y = j; y < m; ++y){
                            for(int z = k; z < q; ++z){
                                tmp=a[x][y][z];
                                if(k>0)tmp-=a[x][y][k-1];
                                if(j>0)tmp-=a[x][j-1][z];
                                if(i>0)tmp-=a[i-1][y][z];
                                if(i>0&&j>0)tmp+=a[i-1][j-1][z];
                                if(i>0&&k>0)tmp+=a[i-1][y][k-1];
                                if(k>0&&j>0)tmp+=a[x][j-1][k-1];
                                if(i>0&&j>0&&k>0)tmp-=a[i-1][j-1][k-1];
                                mx=max(mx,tmp);
                            }
                        }
                    }
                }
            }
        }
        cout<<mx<<endl;
        if(t)cout<<endl;

    }





}