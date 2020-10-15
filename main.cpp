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



int p[2002*2002+1];int VA[2003],HA[2003];



int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
        int x = findSet(i), y = findSet(j);
        // rank is used to keep the tree short
        p[x]=y;}
    }

int main(){
        freopen("fencedin.in","r",stdin);
        freopen("fencedin.out","w",stdout);

       int a, b, n, m; cin >> a >> b >> n >> m;
      
    long long cost=0;
        FOR(i, n) cin >> VA[i]; FOR(i, m) cin >> HA[i];
    sort(VA, VA+n); sort(HA, HA+m);
       vector<pair<int, pair<bool, int>>> lines;
       FOR(i, n) {
           lines.push_back(mp(VA[i] - (i-1>=0?VA[i-1]:0), mp(true, i)));
       }
       lines.push_back(mp(b-VA[n-1], mp(true, n)));
    
        FOR(i, m) {
            lines.push_back(mp(HA[i] - (i-1>=0?HA[i-1]:0), mp(false, i)));}
       
            lines.push_back(mp(a-HA[m-1], mp(false, m)));
            
    sort(all(lines));
    int si=2002*2002+1;
    FOR(i,si) p[i]=i;
   
       for (pair<int, pair<bool, int>> line : lines) {
           if (line.se.fi) {
               // vertical
               FOR(i, m) {
                   int node1=line.se.se*(m+1)+i;
                   int node2=node1+1;
                   if (!isSameSet(node1,node2))  {unionSet(node1,node2);cost += line.fi;}
               }
               
           }
           
               else {
               // horizontal
               FOR(i, n) {
                   int node1 = i*(m+1)+line.se.se;
                   int node2 = node1+(m+1);
                   if (!isSameSet(node1, node2)) {unionSet(node1, node2);cost += line.fi;}
                   }
                   
               }
           }
       
       cout << cost << endl;

       return 0;
   
        
      
    }
