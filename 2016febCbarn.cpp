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



int cow[1000001];




int main(){
        freopen("cbarn.in","r",stdin);
        freopen("cbarn.out","w",stdout);
    int n; cin >> n;
    REP(i,n) cin >> cow[i];
    int drop=0;
    REP(i,n) drop=max(0,drop+cow[i]-1);
    REP(i,n) {
        if (drop==0) {rotate(cow+1,cow+i,cow+n+1);break;}
        drop=max(0,drop+cow[i]-1);
    }
    queue<int> q; long long res=0;
    REP(i,n){
        REP(j,cow[i]) q.push(i);
        int now=q.front();q.pop();
        res+=(i-now)*(i-now);
    }
    cout << res << '\n';
       return 0;
   
        
      
    }
