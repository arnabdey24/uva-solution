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
    int in=1,o;
    int t,n,m,q,tmp;
    char x,z;
    while (cin>>n>>m){
        vector<int> v,c(n),cc[n];
        int sum=0;
        for(int i = 0; i < m; ++i){
            cin>>t;
            sum+=t;
            v.push_back(t);
        }
        sort(all(v),greater<int>());
        double a=(double )sum/n,imp=0;
        for(int i = 0; i < m; ++i){
            int idx,curDif=INT32_MAX;
            for(int j = 0; j < n; ++j){
                if(cc[j].size()==2)continue;
                //int dif=abs(a-(c[j]));
                if(c[j]<curDif){
                    curDif=c[j];
                    idx=j;
                }
            }
            c[idx]+=v[i];
            cc[idx].push_back(v[i]);
        }
        for(int i = 0; i < n; ++i){
            imp+=abs(c[i]-a);
        }
        printf("Set #%d\n",in++);
        for(int i = 0; i < n; ++i){
            printf("%2d:",i);
            for(int j = 0; j <cc[i].size() ; ++j){
                printf(" %d",cc[i][j]);
            }
            printf("\n");
        }
        printf("IMBALANCE = %.5lf\n\n",imp);

    }




}
