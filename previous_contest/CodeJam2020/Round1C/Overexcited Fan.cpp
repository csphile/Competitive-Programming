#include <bits/stdc++.h>

#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPR(i, a, b) for (int i = a; i > b; i--)

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int maxN = 50;
string dirs;
int X, Y;

void solve(){
  cin >> X >> Y;
  cin >> dirs;
  REP(i, 0, dirs.length()){
    if (abs(X) + abs(Y) <= i)
    {
      cout << i;
      return ;
    }
    if (dirs[i] == 'S')
      Y --;
    else if (dirs[i] == 'N')
      Y ++;
    else if (dirs[i] == 'E')
      X ++;
    else 
      X --;
  }
  if (abs(X) + abs(Y) <= dirs.length())
  {
    cout << dirs.length();
    return ;
  }
  cout << "IMPOSSIBLE";
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