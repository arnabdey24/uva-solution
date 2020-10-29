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
   // IOS
#ifdef _AD_
    filein //fileout
#endif
///</editor-fold>
    int in=1,o;
    int t,n,m;
    while (cin>>n){
        //int a[n],b[n];
        vector<int> a,b;
        for(int i = 0; i < n; ++i){
            cin>>t;
            a.push_back(t);
            b.push_back(t);
        }
        sort(all(a));
        sort(all(b));
        cin>>t;
        int l=0,r=INT32_MAX;
        for(int i = 0; i < n; ++i){
            //cout<<i<<endl;
            int tmp=a[i];
            a[i]=-INT32_MAX;
            //cout<<binary_search(all(a),t-tmp)<<endl;
            if(!binary_search(all(a),t-tmp))continue;
            int x=lower_bound(all(a),t-tmp)-a.begin();
            //cout<<x<<endl;
            //cout<<r-l<<" "<<x-i<<endl;
            if(abs(r-l)>abs(x-i)){
                l=i;
                r=x;
                //cout<<l<<" "<<r<<endl;
            }
        }
        cout<<"Peter should buy books whose prices are "<<b[l]<<" and "<<b[r]<<"."<<endl<<endl;
    }




}
