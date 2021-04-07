# Brute Force    
又名朴素算法    
## Bitwise Operations 
[POJ1995 Raising Modulo Numbers](http://poj.org/problem?id=1995): Compute a^b mod p, with constraints 1 <= a, b, p <= 1e9    
**Sol**    
let $$b = c_k 2^{k} + c_{k - 1}2^{k - 1} + ... + c_0 2^0$$   
then $$a^b = a^{c_k 2^k} * a^{c_{k - 1} 2^{k - 1}} * ... * a^{c_0 2^0}$$   
since $$a^{2^i} = (a^{2^{i - 1}})^2$$   
Compute all such terms and multiple to answer only when $$c_i = 1$$    
Time Complexity: O(log2 b)
```c++
#include <iostream>
using namespace std;
int modpow(int a, int b, int mod){
  int ans = 1%mod;
  for (; b; b >>= 1){
    if (b&1) 
      ans = (long long) ans * a % mod;
    a = (long long) a * a % mod;
  }
  return ans;
}

void solve()
{
  int M; cin >> M; int H; cin >> H;
  int ans = 0;
  for (int i = 0; i < H; i++){
    int a, b; cin >> a >> b; 
    ans = (long long) (ans + modpow(a, b, M))%M;
  }
  cout << ans << endl;
}

int main()
{
  int nofcase;
  cin >> nofcase;
  for (int tt = 1; tt <= nofcase; tt++)
  {
    solve();
  }
  return 0;
}
```
## State Compression 
[Hamilton path](https://en.wikipedia.org/wiki/Hamiltonian_path): Given n (n <= 20), compute the shortest Hamilton path from 0 to n - 1.    
**Sol**      
Let F[s, c] (0 <= s < 2^n) the shortest path that already visited all points in s, if the i-th bit in s is one, then that means we have already visited the point i, and c is the last point visited. The answer would be F[(1 << n) - 1, n - 1]    
**State transition**    
F[s, c] = min{F[s xor (1 << c), k] + weight(k, c)} where 0 <= k < n and (s >> c & 1) = 1. (c is in the set s).    
Time complexity: O(n^2 2^n)    
```c++
int n = 20; 
vector<vector<int>> f(1 << 20, vector<int>(20, INT_MAX / 2));
f[1][0] = 0;
for (int i = 0; i < 1 << n; i++){
  for (int j = 0; j < n; j++) if (i >> j & 1)
    for (int k = 0; k < n; k++) if (i >> k & 1)
      f[i][j] = min(f[i][j], f[i^(1 << j)][k] + weight[k][j]);
}
return f[(1 << n) - 1][n - 1];
```
**Extension**: [POJ2288 Islands and Bridges](https://vjudge.net/problem/POJ-2288)     
**Sol**  
Use two arrays f(s, i, j) and g(s, i, j) to represent respectively the maximum and number of different optimal paths.    
**State transition**    
`f(s, i, j) = min(f(s, i, j), f[s^(1 << i)][j][k] + arr[i] + arr[i]*arr[j] + inedge[i][k]*arr[i]*arr[j]*arr[k])` minimum for all possible k    
Time complexity: O(n^3 2^n)
```c++
#define LOCAL
#include <iostream>
#include <cstring>
#include <assert.h>
// #include "debug.hpp"
using namespace std;
const int maxn = 13;
int n, m; 
int arr[maxn]; 
int inedge[maxn][maxn];
int f[1 << maxn][maxn][maxn]; 
long long g[1 << maxn][maxn][maxn];
void solve()
{
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  memset(inedge, 0, sizeof(inedge));
  memset(f, 0, sizeof(f));
  memset(g, 0, sizeof(g));
  for (int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    --a, --b;
    inedge[a][b] = inedge[b][a] = 1;
    int s = (1 << a) | (1 << b);
    f[s][a][b] = f[s][b][a] = arr[a]*arr[b] + arr[a] + arr[b];
    g[s][a][b] = g[s][b][a] = 1;
  }
  if (n == 1){
    cout << arr[0] << " " << 1 << endl;
    return ;
  }
  for (int s = 0; s < 1 << n; ++s){
    for (int i = 0; i < n; i++) if (s >> i & 1)
      for (int j = 0; j < n; j++) if ((s >> j & 1) && (j^i) && inedge[i][j])
        for (int k = 0; k < n; k++) if ((s >> k & 1) && (k^i) && (k^j) && f[s^(1 << i)][j][k] > 0) {
          int w = f[s^(1 << i)][j][k] + arr[i] + arr[i]*arr[j] + inedge[i][k]*arr[i]*arr[j]*arr[k];
          if (w > f[s][i][j]){
            g[s][i][j] = g[s^(1 << i)][j][k];
            f[s][i][j] = w;
          }else if (w == f[s][i][j]){
            g[s][i][j] += g[s^(1 << i)][j][k];
          }
        }
  }
  long long cnt = 0, best = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (f[(1 << n) - 1][i][j] > best){
        cnt = g[(1 << n) - 1][i][j];
        best = f[(1 << n) - 1][i][j];
      }else if (f[(1 << n) - 1][i][j] == best){
        cnt += g[(1 << n) - 1][i][j];
      }
    }
  }
  cout << best << " "  << cnt / 2 << endl; 
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
```