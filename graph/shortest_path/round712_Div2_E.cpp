#define LOCAL
#include <bits/stdc++.h>
#include <assert.h>
// #include "debug.hpp"
using namespace std;
void solve()
{
  int n; cin >> n;
  long long ans = 0;
  vector<pair<long long, long long>> nodes(n);
  for (int i = 0; i < n; i++){
    cin >> nodes[i].first >> nodes[i].second;
    ans += nodes[i].second;
  }
  // trace(a)
  sort(nodes.begin(), nodes.end());
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<> > pq;
  pq.push({0ll, 0});
  vector<int> vis(n, 0);
  while (pq.size()){
    long long d;
    int i;
    tie(d, i) = pq.top(); pq.pop();
    if (vis[i]) continue;
    vis[i] = 1;
    if (i == n - 1){
      cout << ans + d << endl;
      return ;
    }

    int j = lower_bound(nodes.begin(), nodes.end(), 
      make_pair(nodes[i].first + nodes[i].second, LLONG_MAX / 2)) - nodes.begin() - 1;
    // j >= i
    if (i > 0) pq.push({d, i - 1});
    pq.push({d, j});
    if (j + 1 < n){
      pq.push({d + nodes[j + 1].first - nodes[i].first - nodes[i].second, j + 1});
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  //int nofcase;
  // cin >> nofcase;
  // for (int tt = 1; tt <= nofcase; tt++)
  {
    // cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}