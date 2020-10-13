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
    long n,t;
    while (cin>>n,n){
        int s[n];
        for(long i = 0; i < n; ++i){
            cin>>s[i];
        }
        if(in++!=1)cout<<endl;

        for(long i = 0; i < n-5; ++i){
            for(long j = i+1; j < n-4; ++j){
                for(long k = j+1; k < n-3; ++k){
                    for(long l = k+1; l < n-2; ++l){
                        for(long m = l+1; m < n-1; ++m){
                            for(long p = m+1; p <n ; ++p){
                                cout<<s[i]<<" "<<s[j]<<" "<<s[k]<<" "<<s[l]<<" "<<s[m]<<" "<<s[p]<<endl;
                            }
                        }
                    }
                }
            }
        }

    }
}
