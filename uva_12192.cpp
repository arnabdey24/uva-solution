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
    int t,n,m,q;
    while (cin>>n>>m && (n||m)){
        vector<int> v[n];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin>>t;
                v[i].push_back(t);
            }
        }
        cin>>q;
        int a,b;
        for(int i = 0; i < q; ++i){
            cin>>a>>b;
            int mx=0;
            for(int j = 0; j < n; ++j){
                //cout<<"j "<<j<<endl;
                int x=lower_bound(all(v[j]),a)-v[j].begin();
                //cout<<x<<endl;
                int count=0;
                if(x<m){
                    int c1=j,c2=x;
                    //cout<<c1<<" "<<c2<<endl;
                    if(c1<n&&c2<m&&v[c1][c2]<=b)count=1;
                    while (c1<n&&c2<m&&v[c1][c2]<=b){
                        c1++,c2++;
                        if(c1<n&&c2<m&&v[c1][c2]<=b)count++;
                    }
                    //cout<<c1<<" "<<c2<<endl;
                }
                mx=max(count,mx);
            }
            cout<<mx<<endl;
        }
        cout<<"-"<<endl;
    }




}
