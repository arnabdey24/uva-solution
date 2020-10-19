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
    for(int e1 = 1; e1 <=2000 ; ++e1){
        for(int e2 = e1; e2 <=2000-e1 ; ++e2){
            for(int e3 = e2; e3 <=2000-e1-e2 ; ++e3){
                int c=1000000,b=e1+e2+e3,a=e1*e2*e3;
                if (a!=c){
                    if(a>c&&(b*c)%(a-c)==0){
                        int e4=(b*c)/(a-c);
                        if(e4>=e3&& (e1+e2+e3+e4)<=2000)cout<<e1/100<<"."<<setfill('0')<<setw(2)<<e1%100<<" "<<e2/100<<"."<<setfill('0')<<setw(2)<<e2%100<<" "<<e3/100<<"."<<setfill('0')<<setw(2)<<e3%100<<" "<<e4/100<<"."<<setfill('0')<<setw(2)<<e4%100<<endl;
                        //printf("%d.%d %d.%d %d.d% %d.%d",e1/100,e1%100,e2/100,e2%100,e3/100,e3%100,e4/100,e4%100);
                    }
                }
            }
        }
    }



}
