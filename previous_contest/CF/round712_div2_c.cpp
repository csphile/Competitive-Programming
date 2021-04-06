#define LOCAL
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define trav(a, x) for (auto &a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &out, const pair<A, B> &a)
{
  out << "(" << a.first << "," << a.second << ")";
  return out;
}
template <typename T, size_t N>
ostream &operator<<(ostream &out, const array<T, N> &a)
{
  out << "[";
  bool first = true;
  for (auto &v : a)
  {
    out << (first ? "" : ", ");
    out << v;
    first = 0;
  }
  out << "]";
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &a)
{
  out << "[";
  bool first = true;
  for (auto &v : a)
  {
    out << (first ? "" : ", ");
    out << v;
    first = 0;
  }
  out << "]";
  return out;
}
template <typename T, class Cmp>
ostream &operator<<(ostream &out, const set<T, Cmp> &a)
{
  out << "{";
  bool first = true;
  for (auto &v : a)
  {
    out << (first ? "" : ", ");
    out << v;
    first = 0;
  }
  out << "}";
  return out;
}
template <typename U, typename T, class Cmp>
ostream &operator<<(ostream &out, const map<U, T, Cmp> &a)
{
  out << "{";
  bool first = true;
  for (auto &p : a)
  {
    out << (first ? "" : ", ");
    out << p.first << ":" << p.second;
    first = 0;
  }
  out << "}";
  return out;
}
#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
  const char *comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
void solve()
{
  int n; cin >> n; string s; cin >> s;
  int tot = 0;
  for (int i = 0; i < n; i++){
    tot += s[i] - '0'; 
  }
  // trace(tot, n);
  if (tot&1 || s[0] != '1' || s[n - 1] != '1') {
    cout << "NO\n";
    return ;
  }
  int alt = 1, cnt = 0;
  string s1(n, ' '), s2(n, ' ');
  for (int i = 0; i < n; i++){
    cnt += s[i] - '0'; 
    if (s[i] == '1'){
      if (cnt * 2 > tot){
        s1[i] = s2[i] = ')';
      }
      else{
        s1[i] = s2[i] = '(';
      }
    }else{
      if (alt > 0){
        s1[i] = ')'; s2[i] = '(';
      }else{
        s1[i] = '('; s2[i] = ')';
      }
      alt *= -1;
    }
  }
  // trace(s1, s2);
  cout << "YES\n" + s1 + "\n" + s2 + "\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int nofcase;
  cin >> nofcase;
  for (int tt = 1; tt <= nofcase; tt++)
  {
    // cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}