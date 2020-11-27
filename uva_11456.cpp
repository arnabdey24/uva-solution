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
vector<int> v;
int memo1[2005],memo2[2005],m;
int lis(int n){
    if(memo1[n]!=0)return memo1[n];
    int mx=1;
    for(int i = n+1; i <m ; ++i){
        if(v[i]>v[n])mx=max(mx,lis(i)+1);
    }
    return memo1[n]=mx;
}
int lds(int n){
    if(memo2[n]!=0)return memo2[n];
    int mx=1;
    for(int i = n+1; i <m ; ++i){
        if(v[n]>v[i])mx=max(mx,lds(i)+1);
    }
    return memo2[n]=mx;
}
int main() {
///<editor-fold desc="ios">
    // IOS
#ifdef _AD_
    filein //fileout
#endif
///</editor-fold>
    long t,q,tmp;
    int in=1,o;
    cin>>t;
    while (t--){
        memset(memo1,0);
        memset(memo2,0);
        v.clear();
        cin>>m;
        for(int i = 0; i < m; ++i){
            cin>>tmp;
            v.push_back(tmp);
        }
        int mx=0;
        for(int i = m-1; i >=0; --i){
            mx=max(mx,lis(i)+lds(i)-1);
        }
        cout<<mx<<endl;


    }





}