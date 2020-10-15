#include <iostream>
#include <vector>
#include <iomanip>
#include <unordered_map>
#include <cstring>
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



long long memo[1010][1010];

vector<pair<long long, long long> > F;
vector<pair<long long, long long> > B;
map<char,int> dx,dy;
long long solve(int t1, int t2) {
  /* The energy cost of the radio for this timestep. */
  long long base = (F[t1].first - B[t2].first) * (F[t1].first - B[t2].first) +
             (F[t1].second - B[t2].second) * (F[t1].second - B[t2].second);
  if (t1 + 1 == F.size() && t2 + 1 == B.size()) {
    return base;
  }

  long long& ref = memo[t1][t2];
  if (ref != -1) return ref;

  /* Don't include the cost of the first timestep. */
  if (t1 == 0 && t2 == 0) base = 0;

  ref = 1e9;
  if (t1 + 1 < F.size()) {
    /* Step FJ forward. */
    ref = min(ref, base + solve(t1 + 1, t2));
  }
  if (t2 + 1 < B.size()) {
    /* Step Bessie forward. */
    ref = min(ref, base + solve(t1, t2 + 1));
  }
  if (t1 + 1 < F.size() && t2 + 1 < B.size()) {
    /* Step both forward. */
    ref = min(ref, base + solve(t1 + 1, t2 + 1));
  }
  return ref;
}

int main(){
   freopen("radio.in","r",stdin);
   freopen("radio.out","w",stdout);
     map<char, int> dx, dy;
     dx['E'] = 1; dx['W'] = -1;
     dy['N'] = 1; dy['S'] = -1;

     int N, M;
     cin >> N >> M;
     int fx, fy, bx, by;
     cin >> fx >> fy >> bx >> by;
     
    
     F.push_back(make_pair(fx, fy));
     REP(i,N){
         char c; cin >> c;
       fx += dx[c];
       fy += dy[c];
       F.push_back(make_pair(fx, fy));
     }

     /* Compute Bessie's path. */
     B.push_back(make_pair(bx, by));
     REP(i,M) {
         char c; cin >> c;
       bx += dx[c];
       by += dy[c];
       B.push_back(make_pair(bx, by));
     }

     memset(memo, -1, sizeof(memo));
     cout << solve(0, 0) << endl;
       return 0;
    }
