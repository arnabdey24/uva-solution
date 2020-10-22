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

int n,m,mx;
int a[20];
set<string,greater<string>> st;
void cal(int vis,int sum,int k){
    if(sum>n)return;
    if(sum==n){
        string tmp;
        for(int i = 0; i < m; ++i){
            if(vis&(1<<i)){
                if(tmp.empty())tmp+=to_string(a[i]);
                else {
                    tmp+='+';
                    tmp+=to_string(a[i]);
                }
            }
        }
        //cout<<tmp<<endl;
        st.insert(tmp);
        return;
    }
    for(int i = k; i <m; ++i){
        if(!(vis&(1<<i))){
            cal(vis|(1<<i),sum+a[i],k+1);
        }
    }
}


int main() {
///<editor-fold desc="ios">
    //IOS
#ifdef _AD_
    filein //fileout
#endif
///</editor-fold>
    int in=1,o;
    //int t,n,m,d;
    while (cin>>n>>m && (n||m)){
        memset(a,0);
        st.clear();
        for(int i = 0; i < m; ++i){
            cin>>a[i];
        }
        cal(0,0,0);
        cout<<"Sums of "<<n<<":"<<endl;
        if(st.empty())cout<<"NONE"<<endl;
        else{
            for(auto x : st){
                cout<<x<<endl;
            }
        }

    }




}
