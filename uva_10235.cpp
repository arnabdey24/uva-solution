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
    if(y == 0)
        return 1;
    if(y&1)
        return x*Pow(x*x, y/2);
    else
        return Pow(x*x, y/2);
}
#define printcase(x)  cout<<"Case "<<in++<<": "<<x<<endl
#define memset(a,b) memset(a,b,sizeof(a))
#define print1d(ary) cout<<"[";for(auto x:(ary)){cout<<x<<",";}cout<<"]"<<endl;
#define print2d(x) for(int m = 0; m <sizeof(x)/sizeof(x[0]) ; ++m){for(int l = 0; l <sizeof(x[0])/sizeof(x[0][0]) ; ++l){cout<<x[m][l]<<" ";}cout<<endl;}
#define pi acos(-1)
////////////////////////////////////////////////////////////////////////////</editor-fold>

vector<int> primes;
const int Max=1000005;
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
void getPrime(){
    for(long i = 2; i <Max ; ++i){
        if(prime[i])primes.push_back(i);
    }
}

int main() {
///<editor-fold desc="ios">
    IOS
#ifdef _AD_
    filein //fileout
#endif
///</editor-fold>
    long in=1,o;
    long n;
    sieve();
    while (cin>>n){
        string s=to_string(n);
        reverse(all(s));
        int x=stoi(s);
        if(prime[n]&&prime[x]&&n!=x)cout<<n<<" is emirp."<<endl;
        else if(prime[n])cout<<n<<" is prime."<<endl;
        else cout<<n<<" is not prime."<<endl;

    }



}