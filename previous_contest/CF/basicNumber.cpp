// k-th basic number
#include <bits/stdc++.h>

#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPR(i, a, b) for (int i = a; i > b; i--)

using namespace std;

int modpow(int x, int n, int m) {
  if (n == 0) return 1%m;
  long long u = modpow(x, n/2, m);
  u = (u*u)%m;
  if (n%2 == 1) u = (u*x)%m;
  return u;
}

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

ll m[10000];
int sg[10000];
int p[13] = {2,3,5,7,11,13,17,19,23,29,31,37,41};
ll k, lo, hi, mi, k0;
void init()
{
  int i;
  for(int s=1;s<(1<<13);s++)
  {
    m[s]=1; sg[s]=-1;
    for(i=0;i<13;i++) {
      if(s&(1<<i))
      {
        sg[s]=-sg[s];
        m[s]=m[s]*p[i];
      }
    }
  }
  //cout<<m[(1<<13)-1]<<endl;
}

ll play(ll wk){
  long long pt, cnt=0;
  for(int s=1;s<(1<<13);s++)
  {
    pt=wk/m[s];
    cnt=cnt+pt*sg[s];
  }
  return(cnt);
}

void solve(){
  init();
  cin >> k;
  lo=1; hi=m[(1<<13)-1]+1;
  // assertion: from 1 to lo there will be less than k
  // from 1 to hi there will be no less than k
  while(lo+1<hi)
  {
    mi=(lo+hi)/2;
    k0=play(mi);
    if(k0 < k) lo=mi; else hi=mi;
  }
  cout << hi;
  
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  REP(t_, 1, t + 1)
  {
    cout << "Case #" << t_ << ": ";
    solve();
    cout << endl;
  }
  return 0;
}

// if file is used:
/*
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
*/
// g++ B.cpp -o temp -Wall && ./temp < input.in
// ios::sync_with_stdio(false);
// cin.tie(0);