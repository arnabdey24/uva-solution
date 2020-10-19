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
    long in=1,o;
    long t,n,m,d;
    cin>>t;
    while (t--){
        int a[5][5];
        memset(a,0);
        cin>>n;
        for(int i = 0; i < n; ++i){
            int x,y,z;
            cin>>x>>y>>z;
            a[x][y]=z;
        }
        vector<int> v;
        vector<pair<int,int>> pos;
        for(int i = 0; i < 5; ++i){
            for(int j = 0; j < 5; ++j){
                v.push_back(a[i][j]);
                pos.emplace_back(i,j);
            }
        }
        int p1=0,p2=1,p3=2,p4=3,p5=4,cal=INT32_MAX;
        for(int i = 0; i < 25; ++i){
            for(int j = i+1; j < 25; ++j){
                for(int k = j+1; k < 25; ++k){
                    for(int l = k+1; l < 25; ++l){
                        for(int p = l+1; p < 25; ++p){
                            int dis=0;
                            for(int x = 0; x < 25; ++x){
                                int tmp=(abs(pos[p].first-pos[x].first)+abs(pos[p].second-pos[x].second))*v[x];
                                tmp=min(tmp,(abs(pos[l].first-pos[x].first)+abs(pos[l].second-pos[x].second))*v[x]);
                                tmp=min(tmp,(abs(pos[k].first-pos[x].first)+abs(pos[k].second-pos[x].second))*v[x]);
                                tmp=min(tmp,(abs(pos[j].first-pos[x].first)+abs(pos[j].second-pos[x].second))*v[x]);
                                tmp=min(tmp,(abs(pos[i].first-pos[x].first)+abs(pos[i].second-pos[x].second))*v[x]);
                                dis+=tmp;
                            }
                            if(dis<cal){
                                p1=i;
                                p2=j;
                                p3=k;
                                p4=l;
                                p5=p;
                                cal=dis;
                            }
                        }
                    }
                }
            }
        }
        printf("%d %d %d %d %d\n",p1,p2,p3,p4,p5);
    }



}
