#include <bits/stdc++.h>

#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPR(i, a, b) for (int i = a; i > b; i--)

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int maxN = 50;
string p[maxN], pre[maxN], suf[maxN];
int n;

void solve(){
  cin >> n;
  int lp = 0, ls = 0;
  REP(i, 0, n){
    cin >> p[i];
    pre[i] = suf[i] = "";
    // techniques to loop over a string
    for(; p[i][0] != '*'; p[i].erase(p[i].begin()))
      pre[i] += p[i][0];
    for (; p[i].back() != '*'; p[i].pop_back())
      suf[i] = p[i].back() + suf[i];
    if (pre[i].size() > pre[lp].size())
      lp = i;
    if (suf[i].size() > suf[ls].size())
      ls = i;
  }
  REP(i, 0, n){
    if (pre[lp].substr(0, pre[i].size()) != pre[i]){
      cout << "*";
      return ;
    }
    if (suf[ls].substr(suf[ls].size() - suf[i].size()) != suf[i]){
      cout << "*";
      return ;
    }
  }
  string ans = pre[lp];
  REP(i, 0, n)
    for(char c: p[i])
      if (c != '*') ans += c;
  ans += suf[ls];
  cout << ans;
}

int main()
{
  // ios::sync_with_stdio(false);
  // cin.tie(0);
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