#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef int64_t ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll k, l, r, t, x, y; cin >> k >> l >> r >> t >> x >> y;
    // cout << k << endl;
    auto solve = [&](){
        if (k < l || k > r) return false;
        if (x > y){
            if (k + y > r){
                k -= x;
                t--;
            }
            if (k < l)
                return false;
            // cout << k << " " << l << endl;
            ll canalive = (k - l) / (x - y);
            return canalive >= t;
        }else{
            vector<int> seen(x, 0);
            while (t > 0){
                if (seen[k % x]) return true;
                seen[k % x] = 1;

                ll canmove = min(t, (k - l) / x);
                k -= canmove * x;
                t -= canmove;
                if (t == 0)
                    return true;
                t --;
                if (k + y <= r) k += y;
                k -= x;
                if (k < l || k > r)
                    return false;
            }
            return true;
        }
    };

    cout << ((solve())?"yes":"no") << endl;

    return 0;
}
