#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////////////////////////////<editor-fold desc="macros">
#define endl "\n"
//#define long long long
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
    int in=1,o;
    long long t,n,m,q,tmp,mx=0;
    cin>>t;
    char x;
    while (t--){
        mx=0;
        cin>>n>>q;
        vector<long long> a,b;
        a.push_back(0);
        b.push_back(0);
        for(int i = 0; i < n; ++i){
            cin>>x;
            if(x=='B'){
                cin>>x;
                cin>>tmp;
                a.push_back(tmp);
                b.push_back(tmp);
            }
            else{
                cin>>x;
                cin>>tmp;
                long long dis1=abs(a.back()-tmp),dis2=abs(b.back()-tmp);
                if(dis1>=dis2)a.push_back(tmp);
                else b.push_back(tmp);
            }
        }
        a.push_back(q);
        b.push_back(q);
        for(int i = 1; i < a.size(); ++i){
            mx=max(mx,abs(a[i]-a[i-1]));
        }
        for(int i = 1; i < b.size(); ++i){
            mx=max(mx,abs(b[i]-b[i-1]));
        }
        printcase(mx);

    }





}
