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

int n,t,m,mx,a,b,ans=0;
int v[101];
int p[]={63,6,91,79,102,109,125,7,127,111};
void cal(int cur,int count,int bad){
    if(count==n){
        ans=1;
        return;
    }

    if(count==0){
        for(int i = 9; i >=0 ; i--){
            if((p[i]&v[count])==v[count])cal(i,count+1,bad|(p[i]^v[count]));
        }
    }
    else{
        if(cur==0)return;
        if(bad&v[count])return;
        if(((p[cur-1])&v[count])==v[count]){
            cal(cur-1,count+1,bad|(p[cur-1]^v[count]));
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
    while (cin>>n,n){
        ans=0;
        string s;
        for(int i = 0; i < n; ++i){
            cin>>s;
            int x=0;
            for(int j = 0; j < s.size(); ++j){
                if(s[j]=='Y')x|=(1<<j);
            }
            v[i]=x;
        }
        cal(0,0,0);
        printf(ans?"MATCH\n":"MISMATCH\n");
    }




}
