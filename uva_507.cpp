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
long long t,n,m,q,tmp;


int main() {
///<editor-fold desc="ios">
    IOS
#ifdef _AD_
    filein //fileout
#endif
///</editor-fold>
    int in=1,o;
    cin>>t;
    while (t--){
        vector<int> v;
        cin>>n;
        for(int i = 0; i < n-1; ++i){
            cin>>tmp;
            v.push_back(tmp);
        }
        int maxSoFar=0,l,r;
        int curMax=0,start=-1,end=0,count=0;
        //print1d(v)
        for(int i = 0; i < v.size(); ++i){
            curMax+=v[i];
            if(curMax<0)curMax=0,count=0;
            else{
                count++;
            }
            if(curMax>maxSoFar){
                maxSoFar=curMax;
                start=i-count;
                end=i;
            }
            else if(curMax==maxSoFar ){
                if(count>abs(end-start)){
                    maxSoFar=curMax;
                    start=i-count;
                    end=i;
                }

            }
        }
        //cout<<maxSoFar<<" "<<start+2<<" "<<end+2<<endl;
        if(maxSoFar)printf("The nicest part of route %d is between stops %d and %d\n",in++,start+2,end+2);
        else printf("Route %d has no nice parts\n",in++);


    }





}
