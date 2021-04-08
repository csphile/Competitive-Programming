# Dynamic Programming

## Usual Practices
**State**, **stage** and **decision** are the three elements that constitute the algorithm, and the overlapping of sub-problems, no aftereffect and optimal sub-structure are the three basic conditions for the problem to be solved by dynamic programming.     
A summary of classical problems       
**Longest increasing sequence(LIS))**: Given a sequence A of length N, find the longest subsequence whose value is monotonically increasing.    
| State description | F[i] represents the length of LIS ending with A[i] |
|--------|-----------|
| Transition |  F[i] = max{F[j] + 1} over j < i and A[j] < A[i]|
| Objective | max F[i] with 1 <= i <= N |
| Complexity        |        O(n^2)    |    

Note that we can optimize by this to O(nlogn) by computing the inverse of F. 

**Longest Common Subsequence (LCS)**: Given two strings A and B with lengths N and M respectively, compute the longest string that is both a subsequence of A and B    
| State description | F[i, j] represents the length of LCS of A[1:i] and B[1:j] |
|--------|-----------|
| Transition |  F[i, j] = max(F[i - 1, j], F[i, j - 1], F[i - 1, j - 1] + 1 if A[i] == B[j])|
| Objective | F[N, M] |
| Complexity        |        O(n^2)    |    
## Applications    
[CF Round 10 D. LCIS](https://codeforces.com/problemset/problem/10/D):     
Give two arrays A and B, find longest common increasing subsequence, i.e. an increasing sequence of maximum length that is the subsequence of both sequences.    
**Sol**   
`dp[i][j]` represents the longest LCIS ending with B[j]. Use `prev` to recover the original array. 
```
  vector<int> dp(m + 1, 0), prev(m + 1, 0);
  int ans = 0, indx;
  for (int i = 1; i <= n; i++){
    int val = 0;
    for (int j = 1; j <= m; j++){
      if (A[i] == B[j]){
        dp[j] = dp[val] + 1;
        prev[j] = val;
      }else if (B[j] < A[i]){
        if (dp[val] < dp[j]) val = j;
      }
    }
  }
  for (int i = 1; i <= m; i++){
    if (dp[i] > ans) {
      ans = dp[i];
      indx = i;
    }
  }
  cout << ans << endl;
  function<void(int)> dfs =[&](int c){
    if (!c) return ;
    dfs(prev[c]);
    cout << B[c] << " ";
  };
  cout << endl;
  dfs(indx);
```
