#include <bits/stdc++.h>

using namespace std;
const int inf = 1e8;
int main(){
    int t; cin >> t; while (t--){
        int n; cin >> n; vector<int> arr(n + 1); for (int i = 1; i <= n; i++) cin >> arr[i];
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, inf));
        dp[0] = vector<int> (n + 1, 0);
        dp[1] = vector<int> (n + 1, 0);
        for (int i = 2; i <= n; i++){
            int cnt = 0;
            for (int j = i - 1; j >= 1; j--){
                if (arr[j] + j >= i){
                    dp[i][j + arr[j]] = min(dp[i][j + arr[j]], dp[j][i - 1] + cnt++);
                }
            }
            for (int j = i + 1; j <= n; j++){ // we can also begin the loop at i;
                dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            }
        }
        cout << dp[n][n] << endl;
    }
    return 0;
}
