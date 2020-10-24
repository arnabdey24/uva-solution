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

int n,t,m,mx;
vector<string> a,b;
vector<string> st1,st2;
vector<string> ans;
void cal1(int count,string s){
    if(count==5){
        st1.push_back(s);
        return;
    }
    for(int i = 0; i < 6; ++i){
        cal1(count+1,s+a[i][count]);
    }
}
void cal2(int count,string s){
    if(count==5){
        st2.push_back(s);
        return;
    }
    for(int i = 0; i < 6; ++i){
        cal2(count+1,s+b[i][count]);
    }
}

string gen(){
    int x=0;
    for(int i = 0; i < st1.size(); ++i){
        if(binary_search(all(st2),st1[i])){
            //cout<<st1[i]<<endl;
            x++;
        }
        if(x==n)return st1[i];
    }
    return "NO";
}


int main() {
///<editor-fold desc="ios">
    IOS
#ifdef _AD_
    filein //fileout
#endif
///</editor-fold>
    int in=1,o;
    //int t,n,m,d;
    cin>>t;
    while (t--){
        a.clear();
        b.clear();
        st1.clear();
        st2.clear();
        //ans.clear();
        cin>>n;
        string s;
        for(int i = 0; i <6 ; ++i){
            cin>>s;
            a.push_back(s);
        }
        cal1(0,"");
        for(int i = 0; i <6 ; ++i){
            cin>>s;
            b.push_back(s);
        }
        cal2(0,"");
        sort(all(st1));
        sort(all(st2));
        makeset(st1);
        makeset(st2);


        cout<<gen()<<endl;
        /*gen();
        if(n<=ans.size())cout<<ans[n-1]<<endl;
        else cout<<"NO"<<endl;*/
    }




}
