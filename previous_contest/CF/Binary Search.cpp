#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, val, pos; cin >> n >> val >> pos;
    {
        vector<vector<ll>> comb(n + 1, vector<ll>(n + 1, 1));
        for (int i = 2; i <= n; i ++){
            for (int j = 1; j < i; j++){
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1])%mod;
            }
        }
        // cout << comb[4][1] << endl;
        vector<ll> fact(n + 1, 1);
        for (int i = 2; i <= n; i++){
            fact[i] = (i*fact[i - 1])%mod;
        }

        int left = 0, right = n;
        int cntBig = 0, cntsmall = 0;
        while (left < right){
            int mid = (left + right) / 2;
            if (mid <= pos){
                left = mid + 1;
                if (mid != pos) cntsmall ++;
            }
            else{
                right = mid;
                cntBig++;
            }
        }
        auto C = [&](int n, int k){
            if (k > n || k < 0) return 0ll;
            return comb[n][k];
        };

        ll p1 = (fact[cntBig] * C(n - val, cntBig))%mod;
        ll p2 = (fact[cntsmall] * C(val - 1, cntsmall))%mod;
        cout << ((p1*p2)%mod * fact[n - 1 - cntBig - cntsmall])%mod << endl;
    }
    return 0;
}
