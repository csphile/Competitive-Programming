// #define LOCAL
#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.hpp"
#else
#define trace(...) 42
#endif

using namespace std;

long long p[100], n[100];
int M;
bool isok(long long sum, long long diff){
  int used = 0;
  for (int i = 0; i < M; i++){
    int cnt = 0;
    while (cnt < n[i] && sum%p[i] == 0){
      sum /= p[i];
      used += p[i];
      cnt ++;
    }
    if (sum%p[i] == 0) 
      return false;
  }
  // trace(sum, diff);
  return sum == 1 && used == diff;
}
void solve()
{
  long long sum = 0; cin >> M; 
  for (int i = 0; i < M; i++){ 
    cin >> p[i] >> n[i];
    sum += p[i]*n[i];
  }
  for (int diff = 0; sum >= 2 && diff <= 4000; sum--, diff++){
    if (isok(sum, diff)){
      cout << sum << endl;
      return ;
    }
  }
  cout << 0 << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  for (int _ = 1; _ <= T; _++)
  {
    cout << "Case #" << _ << ": ";
    solve();
  }
  return 0;
}
