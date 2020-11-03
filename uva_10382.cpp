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
    long t,n,m,q,tmp;
    long x,z,l,w,p,r;
    while (cin>>t>>l>>w){
        vector<pair<double,double>> v;
        for(int i = 0; i < t; ++i){
            cin>>p>>r;
            if(r*2<w)continue;
            double d=sqrt((r*r)-((double)w/2)*((double )w/2));
            v.emplace_back(p-d,(p+d)*-1);
        }
        sort(all(v));
        /*for(int i = 0; i < v.size(); ++i){
            cout<<v[i].first<<" "<<v[i].second*-1<<endl;
        }*/
        if(v.size()==0 || v[0].first>0){
            cout<<-1<<endl;
            continue;
        }
        int idx=0;
        for(int i = 0; i <v.size()&&v[i].first<=0 ; ++i){
            if(v[i].second*-1>v[idx].second*-1){
                idx=i;
            }
        }
        double mx=-v[idx].second,cur=-v[idx].second;
        int mxi=idx,f=0,count=1;
        while (cur<l){
            int found=0;
            for(int i = mxi+1; i <v.size()&&v[i].first<=cur ; ++i){
                if(v[i].second*-1>mx){
                    mx=-v[i].second;
                    found=i;
                }
            }
            if(!found){
                f=1;
                break;
            }
            else{
                count++;
                mxi=found;
                cur=mx;
            }
        }
        if(f)cout<<-1<<endl;
        else cout<<count<<endl;
    }
}
