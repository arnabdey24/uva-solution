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


int main() {
///<editor-fold desc="ios">
    IOS
#ifdef _AD_
    filein //fileout
#endif
///</editor-fold>
    long in=1,o;
    long t,n,m;
    while (cin>>n,n){
        cout<<"Case "<<in++<<":"<<endl;
        int a[n],b=0;
        for(int i = 0; i < n; ++i){
            cin>>a[i];
        }
        //print1d(a)
        cin>>m;
        for(int i = 0; i < m; ++i){
            cin>>t;
            int tmp=INT32_MAX;
            int ans=0;
            for(int j = 0; j < n; ++j){
                for(int k = j+1; k <n ; ++k){
                    //cout<<a[j]<<" "<<a[k]<<endl;
                    if(abs(a[j]+a[k]-t)<tmp){
                        tmp=abs(a[j]+a[k]-t);
                        ans=a[j]+a[k];
                    }
                }
            }
            cout<<"Closest sum to "<<t<<" is "<<ans<<"."<<endl;
        }
    }

}
