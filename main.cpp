#include <iostream>
#include <vector>
#include <iomanip>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <random>
#include <chrono>
#include <fstream>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef map<int,int>  mii;
typedef unordered_map<int, int> umii;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;
         
#define randomize mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//use rng() for random

#define fi first
#define se second
#define pb push_back
#define mp make_pair
         
#define cntbit(x) __builtin_popcount(x)
#define cntBitll(x) __builtin_popcountll(x)
#define all(x) x.begin(),x.end()


#define  FOR(i,n) for (int i=0;i< int(n);i++)
#define  REP(i,n) for (int i=1;i<=int(n);i++)
#define FORR(i,n) for (int i=(int)(n)-1;i>=0;i--)
#define RREP(i,n) for (int i= int(n)   ;i>0 ;i--)

const long long INF=2e18;
const int MAXN=200010;
long long DP[2000][2000];
vector<int> adj[MAXN];
long long A[1001];



int main(){
    freopen("cbarn2.in","r",stdin);
    freopen("cbarn2.out","w",stdout);
    int N,K;cin >> N >> K;
    for (int i = 1; i <= N; i++) {
       cin >> A[i];
     }

     long long result = INF;
       
    
         
    REP(asd,N){
        FOR(i,N+1) FOR(j,K+1) DP[i][j]=INF;
        DP[N+1][0]=0;
        //REP(i,N) cout << A[i] << ' ' ; cout << '\n';
    for (int k=1 ; k<=K;k++){
              for (int i=1;i<=N;i++){
                 long long val=0;
                 for (int d=i;d<=N;d++){
                     val+=A[d]*(d-i);
                     DP[i][k]=min(DP[i][k],DP[d+1][k-1]+val);
                     //cout << "PROCESSING " << i <<   ' ' << d+1  << '\n'<< "GOT " << DP[i][k] << '\n';
                 }
                  
             }
   
         
    }
        result=min(result,DP[1][K]);
     //   cout << "RESULT: " <<  DP[1][K];//
    
    ;rotate(A+1,A+2,A+N+1);}
       
      
       //  REP(i,N) cout << A[i] << ' ';
      
       // REP(i,N) cout << A[i] << ' ';     cout << DP[1][K] << endl;

         
    cout << result << '\n';
        return 0;
    }
