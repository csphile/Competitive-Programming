#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 1e4 + 1;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n; vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        a[i] -= b[i];
    }
    int B = accumulate(all(b), 0);
    vector<vi> dp(n + 1, vi(B + 1, -1));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++){
        for (int k = i; k >= 0; k--){
            for (int A = 0; A <= B; A++){
                if (dp[k][A] != -1) {
                    int ns = min(A + 2 * a[i] + b[i], B);
                    dp[k + 1][ns] = max(dp[k + 1][ns], dp[k][A] + b[i]);
                }
            }
        }
    }
    for (int k = 1; k <= n; k++){
        double ans = 0;
        for (int A = 0; A <= B; A++)
            if (dp[k][A] != -1)
                ans = max(ans, (double) dp[k][A] + A);
        cout << ans*0.5 << " ";
    }
    cout << endl;
    return 0;
}
