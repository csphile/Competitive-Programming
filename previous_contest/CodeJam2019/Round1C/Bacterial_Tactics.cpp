#include <bits/stdc++.h>

#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPR(i, a, b) for (int i = a; i > b; i--)

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int LEFT = 0, RIGHT = 1, UP = 2, DOWN = 3;
int t, R, C;
char board[17][17];
int lookup[4][17][17], memo[17][17][17][17];
int res;

int mex(set<int> s){
  int exlu = 0;
  while (s.count(exlu))
    exlu += 1;
  return exlu;
}

int grundy(int r0, int c0, int r1, int c1){

  if (r0 == r1 || c0 == c1)
    return 0;
  
  if (memo[r0][c0][r1][c1] != -1)
    return memo[r0][c0][r1][c1];  

  //res = 0;
  set<int> sub;
  int g = 0;
  REP(r, r0, r1){
    if (c0 <= lookup[LEFT][r][c0] || lookup[RIGHT][r][c0] < c1)
      continue;
    g = (grundy(r0, c0, r, c1) ^ grundy(r+1, c0, r1, c1));
    sub.insert(g);
    if (g == 0 && r0 == 0 && c0 == 0 && r1 == R && c1 == C)
      res += (c1 - c0);
  }
  REP(c, c0, c1){
    if (r0 <= lookup[UP][r0][c] || lookup[DOWN][r0][c] < r1)
      continue;
    g = (grundy(r0, c0, r1, c) ^ grundy(r0, c + 1, r1, c1));
    sub.insert(g);
    if (g == 0 && r0 == 0 && c0 == 0 && r1 == R && c1 == C)
      res += (r1 - r0);
  }
  memo[r0][c0][r1][c1] = mex(sub);
  return mex(sub);
}

void solve()
{
  cin >> R >> C;
  memset(memo, -1, sizeof(memo));
  REP(i, 0, R)
    REP(j, 0, C){
      cin >> board[i][j];
    }
  REP(r, 0, R){
    int left_radio = -1;
    REP(c, 0, C){
      if (board[r][c] == '#')
        left_radio = c;
      lookup[LEFT][r][c] = left_radio;
    }
    int right_radio = C;
    REPR(c, C - 1, -1){
      if (board[r][c] == '#')
        right_radio = c;
      lookup[RIGHT][r][c] = right_radio;
    }
  }

  REP(c, 0, C){
    int up_radio = -1;
    REP(r, 0, R){
      if (board[r][c] == '#')
        up_radio = r;
      lookup[UP][r][c] = up_radio;
    }
    int down_radio = R;
    REPR(r, R - 1, -1){
      if (board[r][c] == '#')
        down_radio = r;
      lookup[DOWN][r][c] = down_radio;
    }
  }
  res = 0;
  int g = grundy(0, 0, R, C);
  if (g)
    cout << res << endl;
  else 
    cout << 0 << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  REP(t_, 1, t + 1)
  {
    cout << "Case #" << t_ << ": ";
    solve();
  }
  return 0;
}

// if file is used:
/*
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
*/
// g++ B.cpp -o temp -Wall && ./temp < input.in