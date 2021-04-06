#include <bits/stdc++.h>

#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPR(i, a, b) for (int i = a; i > b; i--)

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int maxN = 1e4;
string R[maxN];
ll freq[26];
ll U, M;

void solve(){
  cin >> U;
  memset(freq, 0, sizeof(freq));
  set<char> all;
  for(int i = 0; i< maxN; i++){
    cin >> M;
    cin >> R[i];
    for (char c: R[i])
      all.insert(c);
    freq[R[i][0] - 'A'] ++;
  }
  vector<pair<int, char>> vp;
  for (char c:all){
    vp.push_back(make_pair(freq[c - 'A'], c));
  }
  sort(vp.begin(), vp.end());
  string ans = "";
  for (int i = 1; i <= 9; i++){
    ans += vp[i].second;
  }
  reverse(ans.begin(), ans.end());
  ans = vp[0].second + ans;
  cout << ans;
}

int main()
{
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
// g++ A.cpp -o temp -Wall && ./temp < input.in
// ios::sync_with_stdio(false);
// cin.tie(0);