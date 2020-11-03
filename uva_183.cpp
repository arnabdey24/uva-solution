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
char v[300][300];
string d;
int indx=0;

void btod(int a,int b,int r,int c){
    //cout<<d<<endl;
    int zero=0,one=0;
    for(int i = a; i <=r ; ++i){
        for(int j = b; j <=c ; ++j){
            if(v[i][j]=='1')one++;
            else zero++;
        }
    }
    //cout<<zero<<" "<<one<<endl;
    //if(zero==0 && one==0)return;
    if(zero==0 || one==0){
        //cout<<-1<<endl;
        if(!one)d+='0';
        else d+='1';
        return;
    }
    d+='D';
    /*int s1i=a,s1j=b,e1i=r/2,e1j=c/2;
    int s2i=a,s2j=e1j+1,e2i=r/2,e2j=c/2;*/
    btod(a,b,(a+r)/2,(b+c)/2);
    if((b+c)/2+1<=c)btod(a,(b+c)/2+1,(a+r)/2,c);
    if((a+r)/2+1<=r)btod((a+r)/2+1,b,r,(b+c)/2);
    if((a+r)/2+1<=r && (b+c)/2+1<=c)btod((a+r)/2+1,(b+c)/2+1,r,c);
}
void dtob(int a,int b,int r,int c){
        if(d[indx]=='D'){
            indx++;
            dtob(a,b,(a+r)/2,(b+c)/2);
            if((b+c)/2+1<=c){
                indx++;
                dtob(a,(b+c)/2+1,(a+r)/2,c);
            }
            if((a+r)/2+1<=r){
                indx++;
                dtob((a+r)/2+1,b,r,(b+c)/2);
            }
            if((a+r)/2+1<=r && (b+c)/2+1<=c){
                indx++;
                dtob((a+r)/2+1,(b+c)/2+1,r,c);
            }
        }
        else{
            //cout<<a<<","<<b<<" "<<r<<","<<c<<endl;
            for(int j = a; j <=r ; ++j){
                for(int k = b; k <=c ; ++k){
                    v[j][k]=d[indx];
                }
            }
            return;
        }


}

int main() {
///<editor-fold desc="ios">
    IOS
#ifdef _AD_
    filein fileout
#endif
///</editor-fold>
    int in=1,o;
    int t,n,m,q,tmp;
    char x,z;
    while (cin>>x && x!='#'){
        cin>>n>>m;
        if(x=='B'){
            d="";
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < m; ++j){
                    cin>>v[i][j];
                }
            }
            btod(0,0,n-1,m-1);
            printf("D%4d%4d\n",n,m);
            int count=0;
            for(int i = 0; i < d.size(); ++i){
                printf("%c",d[i]);
                count++;
                if(count%50==0)printf("\n");
            }
            if(count%50!=0)printf("\n");
        }
        else{
            indx=0;
            cin>>d;
            dtob(0,0,n-1,m-1);
            printf("B%4d%4d\n",n,m);
            int count=0;
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < m; ++j){
                    printf("%c",v[i][j]);
                    count++;
                    if(count%50==0)printf("\n");
                }
            }
            if(count%50!=0)printf("\n");
        }


    }




}
