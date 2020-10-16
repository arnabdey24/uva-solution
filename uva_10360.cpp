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

int k[1025][1025];

int main() {
///<editor-fold desc="ios">
    IOS
#ifdef _AD_
    filein //fileout
#endif
///</editor-fold>
    long in=1,o;
    long t,d,m,a,b,x,mxa=0,mxb=0;
    cin>>t;
    while (t--){
        memset(k,0);
        cin>>d>>m;
        for(long i = 0; i < m; ++i){
            cin>>a>>b>>x;
            mxa=max(a,mxa);
            mxb=max(b,mxb);
            a-=d;
            b-=d;
            for(long j = a; j <a+2*d+1 ; ++j){
                for(long l = b; l <b+2*d+1 ; ++l){
                    if(j<1025&&j>=0&&l<1025&&l>=0)k[j][l]+=x;
                }
            }
        }
        //print2d(k);
        a=0,b=0;
        long max=0;
        for(long i = 0; i <=mxa; ++i){
            for(long j = 0; j <=mxb; ++j){
                if(k[i][j]>max){
                    max=k[i][j];
                    a=i;
                    b=j;
                }
            }
        }
        cout<<a<<" "<<b<<" "<<max<<endl;

    }

}
