#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

int r, c, t, board[401], ans[401][2];
//ll ans;

bool canjump(int cur, int next){
  if (board[next] > 0) return false;

  int x_cur = cur / c;
  int y_cur = cur % c;
  int x_next = next / c;
  int y_next = next % c;

  if (x_next == x_cur || y_next == y_cur) return false;
  if (x_next + y_next == x_cur + y_cur) return false;
  if (x_next - y_next == x_cur - y_cur) return false;
  return true;
}

bool dfs(int cur, int num){
  cout << cur << endl;
  board[cur] = num;
  if (num == r * c) {
    return true;
  }
  int ty = 0;
  while (ty < 50) {
    int i;
    for (int _ = 0; _ < 50; _++){
      i = rand() % (r * c);
      cout << i << endl;
      if (canjump(cur, i)) break;
    }
    if (dfs(i, num + 1)) return true;
    ty++;
  }
  board[cur] = -1;
  return false;
}

void solve(){
  cin >> r >> c;
  memset(board, -1, 20*sizeof(board[0]));
  if (dfs(0, 1)){
    cout << "POSSIBLE" << endl;
    for (int i = 0; i < r * c; i++){
      int x_cur = i / c;
      int y_cur = i % c;
      ans[board[i]][0] = x_cur + 1;
      ans[board[i]][1] = y_cur + 1;
    }
    for (int i = 1; i < r * c + 1; i++){
      cout << ans[i][0] << " " << ans[i][1] << endl;
    }
  }
  else  cout << "IMPOSSIBLE" << endl;
}


int main() {
  cin >> t;
  for (int t_ = 1; t_ <= t; ++t_) {
    cout << "Case #" << t_ << ": ";
    solve();
  }
  return 0;
}
