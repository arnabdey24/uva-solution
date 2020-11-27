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
    vector<int> v;
    while (cin>>tmp){
        v.push_back(tmp);
    }
    vector<int> lis,ans;
    int a[v.size()];
    for(int i = 0; i < v.size(); ++i){
        auto it=lower_bound(all(lis),v[i]);
        tmp=it-lis.begin();
        if(it==lis.end())lis.push_back(v[i]);
        else lis[tmp]=v[i];
        a[i]=tmp+1;
    }
    cout<<lis.size()<<endl;
    cout<<'-'<<endl;
    int cur=INT32_MAX,mx=lis.size();
    for(int i = v.size()-1; i >=0 ; --i){
        if(v[i]<cur&&a[i]==mx)ans.push_back(v[i]),mx--;
    }
    for(int i = ans.size()-1; i >=0 ; --i){
        cout<<ans[i]<<endl;
    }

}