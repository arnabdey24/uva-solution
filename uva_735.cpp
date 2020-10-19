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
    long t,n,m;
    vector<int> v;
    v.push_back(0);
    for(int i = 1; i <= 20; ++i){
        v.push_back(i);
        v.push_back(i*2);
        v.push_back(i*3);
    }
    v.push_back(50);
    sort(all(v));
    makeset(v);
    //print1d(v)
    while (cin>>m,m>0){
        int pre=0,com=0;
        for(int i = 0; i < v.size(); ++i){
            for(int j = 0; j < v.size(); ++j){
                for(int k = 0; k < v.size(); ++k){
                    if(v[i] + v[j] + v[k] == m){
                        //cout<<v[i]<<" "<<v[j]<<" "<<v[k]<<endl;
                        pre++;
                        if(j>=i && k>=j)com++;
                    }
                }
            }
        }
        if(pre==0)printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",m);
        else{
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n",m,com);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",m,pre);
        }

        printf("**********************************************************************\n");
    }
printf("END OF OUTPUT\n");
}
