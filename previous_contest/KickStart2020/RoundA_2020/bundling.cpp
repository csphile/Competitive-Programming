#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

int u, t, n, k, c[2000001][26], cnt[2000001];
ll ans;

void dfs(int u, int d){
  for (int v = 0; v<26; v++){
    if (c[u][v]) dfs(c[u][v], d + 1), cnt[u] += cnt[c[u][v]];
  }
  while (cnt[u] >= k){
    cnt[u] -= k;
    ans += d;
  }
}

void solve(){
  ans = 0;
  cin >> n >> k;
  ll m = 1;
  for (int i = 0; i<n; i++){
    string s;
    cin >> s;
    u = 0;
    for(char s_: s){
      int ind = s_ - 'A';
      if (!c[u][ind])
        c[u][ind] = m++;
      u = c[u][ind];
    }
    cnt[u] += 1;
  }
  dfs(0, 0);
  cout << ans << endl;
  memset(c, 0, m*sizeof(c[0]));
  memset(cnt, 0, m*sizeof(cnt[0]));
}


int main() {
  cin >> t;
  for (int t_ = 1; t_ <= t; ++t_) {
    cout << "Case #" << t_ << ": ";
    solve();
  }
  return 0;
}
