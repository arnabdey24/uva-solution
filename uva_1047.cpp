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
    int in=1,o;
    int t,n,m,d,tmp;
    while (cin>>n>>t && (n||t)){
        int val[n];
        for(int i = 0; i < n; ++i){
            cin>>val[i];
        }
        cin>>m;
        map<int,int> mp;
        for(int i = 0; i < m; ++i){
            cin>>d;
            int a=0;
            for(int j = 0; j < d; ++j){
                cin>>tmp;
                tmp--;
                a|=(1<<tmp);
            }
            cin>>o;
            mp[a]=o;
        }
        int mx=-1e9,ans=0;
        for(int i = 0; i <(1<<n) ; ++i){
            if(__builtin_popcount(i)==t){
                int sum=0;
                for(int j = 0; j < n; ++j){
                    if(i&(1<<j)){
                        sum+=val[j];
                    }
                }
                for(auto x : mp){
                    tmp=__builtin_popcount(i&x.first);
                    if(tmp>=2)sum-=x.second*(tmp-1);
                }
                if(mx<sum){
                    mx=sum;
                    ans=i;
                }
            }
        }
        cout<<"Case Number  "<<in++<<endl;
        cout<<"Number of Customers: "<<mx<<endl;
        cout<<"Locations recommended:";
        for(int i = 0; i < n; ++i){
            if(ans&(1<<i)){
                cout<<" "<<i+1;
            }
        }
        cout<<endl<<endl;
    }



}
