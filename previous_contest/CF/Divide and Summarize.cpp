#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<ll> arr(n + 1); for (int i = 1; i <= n; i++) cin >> arr[i];
        sort(all(arr));
        vector<ll> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] + arr[i];
        set<ll> seen;
        function<void(int, int)> find = [&](int l, int r){
            if (l == r){
                seen.insert(arr[l]);
                return ;
            }
            seen.insert(prefix[r] - prefix[l - 1]);
            ll mid = (arr[l] + arr[r]) >> 1;
            int mid_ind = upper_bound(all(arr), mid) - arr.begin();
            if (mid_ind > r){
                return ;
            }
            ll left_sum = prefix[mid_ind - 1] - prefix[l - 1];
            seen.insert(left_sum);
            ll right_sum = prefix[r] - prefix[mid_ind - 1];
            seen.insert(right_sum);
            if (l <= mid_ind - 1)
                find(l, mid_ind - 1);
            if (mid_ind <= r)
                find(mid_ind, r);
        };
        find(1, n);
        for (int i = 0; i < q; i++){
            ll v; cin >> v; if (seen.count(v)){
                cout << "yes" << endl;
            }else{
                cout << "no" << endl;
            }
        }
    }
    return 0;
}
