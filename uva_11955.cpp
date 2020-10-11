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
    //IOS
#ifdef _AD_
    filein //fileout
#endif
///</editor-fold>

    long in=1,o;
    long n,t;
    long bc[51][51];
    for(long i = 0; i < 51; ++i){
        for(long j = 0; j <=i; ++j){
            if(j==0)bc[i][j]=1LL;
            else if(i==j)bc[i][j]=1LL;
            else bc[i][j]=bc[i-1][j-1]+bc[i-1][j];
        }
    }

    cin>>n;
    while (n--){
        string s,a,b;
        cin>>s;
        stringstream ss(s);
        char x;
        ss>>x;
        while (ss>>x && x!='+')a+=x;
        while (ss>>x && x!=')')b+=x;
        ss>>x;
        int k;
        ss>>k;

        int i=k-1,j=1;
        string ans=a;
        if(k!=1)ans+="^"+to_string(k);
        ans+="+";
        for(long l = 1; l <k ; ++l){
            ans+=to_string(bc[k][l])+"*"+a;
            if(i!=1)ans+="^"+to_string(i);
            ans+="*"+b;
            if(j!=1)ans+="^"+to_string(j);
            ans+="+";
            i--,j++;
        }
        ans+=b;
        if(k!=1)ans+="^"+to_string(k);

        printcase(ans);



    }
}
