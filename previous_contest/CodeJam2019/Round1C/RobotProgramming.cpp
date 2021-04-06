#include <bits/stdc++.h>

#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

int t, a;
// R:0, P:1, S:2;
char judge(char r){
  if (r == 'R')
    return 'P';
  if (r == 'P')
    return 'S';
  else 
    return 'R';
}

char move(string& s){
  // char temp;
  if (s.length() == 1)
    return judge(s[0]);

  if (judge(s[0]) == s[1])
    return s[1];
  else
    return s[0];
}

void solve() {
  cin >> a;
  vector<string> rob;
  vector<int> mask;
  //int maxl = 0;
  for (int _ = 0; _ < a; _++){
    string s;
    cin >> s;
    // maxl = max(maxl, (int) s.length());
    rob.push_back(s);
    mask.push_back(1);
  }
  string ans;
  int temp = a;
  int j = 0;
  while (temp){
    // cout << mask[0] << " " << endl;
    // cout << "number : " << temp;
    
    string s;
    for (int i = 0; i < a; i++) {
      if (mask[i] == 0)
        continue;
      // cout << j << " ";
      int j_ = j % rob[i].length();
      char c_ = rob[i][j_];
      if (s.length() == 0)
        s += c_;
      bool notequal = true;
      for (char& c: s)
        if (c == c_)
          notequal = false;
      if (notequal)
        s += c_;
    }
    if (s.length() > 2){
      cout << "IMPOSSIBLE" << endl;
      return ;
    }
    ans += move(s);
    for (int i = 0; i < a; i++) {
      if (mask[i] == 0)
        continue;
      int j_ = j % rob[i].length();
      if (judge(rob[i][j_]) == ans[ans.size() - 1] )
        mask[i] = 0;
    }
    temp = 0;
    for (auto & i: mask)
      temp += i;
    j++;
  }
  cout << ans << "\0" << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  REP(t_, 1, t)
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
// g++ A.cpp -o temp -Wall