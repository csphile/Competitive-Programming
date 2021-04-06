#include <bits/stdc++.h>

using namespace std;

using LL =  long long;
using LD = long double;
using LLI = long long int;

LLI t, X, Y, X_c, Y_c;
string ans;
bool isplus = false;
/*
(7, 10) -> (3, 5) ->...
(7, 10) -> 7 + 1-> (4, 5) ->...
*/

//think clearly

void compute(LLI& X, LLI& Y){
  if ((((X - 1) / 2 ) & 1) + ((Y / 2) & 1) != 1) {
    X = (X + 1) / 2;
    Y /= 2;
    isplus = true;
  }
  else{
    X = (X - 1) / 2;
    Y /= 2;
    isplus = false;
  }
}

void solve(){
  cin >> X >> Y;
  ans = "";
  while ( abs(X) + abs(Y) > 1 ) {
    //cout << X << " " << Y << endl; 
    if ((X & 1) && ( Y & 1)) {
      cout << "IMPOSSIBLE" << endl;
      return ;
    }
    else if (X & 1) {
      isplus = false;
      compute(X, Y);
      if (isplus)
        ans += 'W';
      else
        ans += 'E';
    }
    else if (Y & 1){
      isplus = false;
      compute(Y, X);
      if (isplus)
        ans += 'S';
      else 
        ans += 'N';
    }
    else{
      cout << "IMPOSSIBLE" << endl;
      return ;
    }
  }
  if (X == 1){
    ans += 'E';
  }
  else if (X == -1){
    ans += 'W';
  }
  if (Y == 1){
    ans += 'N';
  }
  else if (Y == -1){
    ans += 'S';
  }
  cout << ans << endl;
}


int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  for (int t_ = 1; t_ <= t; ++t_) {
    cout << "Case #" << t_ << ": ";
    solve();
  }
  return 0;
}
