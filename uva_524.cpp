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

const int Max=1000;
int prime[Max];
void sieve(){
    memset(prime,1);
    prime[0]=prime[1]=0;
    for(long i = 2; i <=sqrt(Max)+1 ; ++i){
        if(prime[i])
            for(long j = i+i; j <=Max ; j+=i){
                prime[j]=0;
            }
    }
}
int n,m,mx;
void cal(int vis,vector<int> track){
    //cout<<-1<<endl;
    if(track.size()==n){
        if(prime[track.back()+1]){
            for(int i = 0; i < track.size(); ++i){
                if(i)cout<<" "<<track[i];
                else cout<<track[i];
            }
            cout<<endl;
        }
        return ;
    }
    for(int i = 2; i <=n; ++i){
        if(!(vis&(1<<(i-1)))){
            if(prime[track.back()+i]){
                track.push_back(i);
                cal(vis|(1<<(i-1)),track);
                track.pop_back();
            }
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
    sieve();
    while (cin>>n){
        if(in!=1)cout<<endl;
        cout<<"Case "<<in++<<":"<<endl;
        vector<int> v;
        v.push_back(1);
        cal(1,v);

    }




}
