#include <bits/stdc++.h>

#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using pq_vi_g = priority_queue<int, vector<int>, greater<int>>;

int t, a, b;
const int MX = 2e9;

string qry(int x, int y)
{
  x -= MX / 2;
  y -= MX / 2;
  cout << x << " " << y << endl;
  string s;
  cin >> s;
  return s;
}

void solve()
{
  ll cx = -1, cy = 0;
  REP(i, 1, 5)
  {
    REP(j, 1, 5)
    {
      ll x = MX / 5 * i, y = MX / 5 * j;
      if (qry(x, y) != "MISS")
      {
        cx = x, cy = y;
        break;
      }
    }
    if (cx != -1)
      break;
  }
  assert(cx != -1);

  ll mnx, mny, mxx, mxy;

  //binary searches:
  {
    ll ls = 0, rs = cx;
    while (ls < rs){
      ll mid = (ls + rs) / 2;
      if (qry(mid, cy)[0] != 'M')
        rs = mid;
      else 
        ls = mid + 1;
    }
    mnx = ls;
  }
  
  {
    ll ls = cx, rs = MX;
    while (ls < rs){
      ll mid = (ls + rs + 1) / 2;
      if (qry(mid, cy)[0] != 'M')
        ls = mid;
      else 
        rs = mid - 1;
    }
    mxx = ls;
  }

  {
    ll ls = 0, rs = cy;
    while (ls < rs){
      ll mid = (ls + rs) / 2;
      if (qry(cx, mid)[0] != 'M')
        rs = mid;
      else 
        ls = mid + 1;
    }
    mny = ls;
  }

  {
    ll ls = cy, rs = MX;
    while (ls < rs){
      ll mid = (ls + rs + 1) / 2;
      if (qry(cx, mid)[0] != 'M')
        ls = mid;
      else 
        rs = mid - 1;
    }
    mxy = ls;
  }

  string ans = qry((mnx + mxx) / 2, (mny + mxy) / 2);
  assert(ans == "CENTER");
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  cin >> a >> b;
  for (int t_ = 1; t_ <= t; ++t_)
  {
    //cout << "Case #" << t_ << ": ";
    solve();
  }
  return 0;
}

// if file is used:
/*
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
*/