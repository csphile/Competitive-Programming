#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 7;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while (t--){

        int n; cin >> n;
        vector<int> arr(n), dists(n + 1, 0), r(n, 1), l(n, 1);
        for (auto& v: arr) cin >> v;

        for (int i = n - 2; i >= 0; i--){
            int j = i + 1;
            for (; j < n;){
                if (arr[j] >= arr[i]){
                    j += r[j];
                }
                else{
                    break;
                }
            }
            r[i] = j - i;
        }

        for (int i = 1; i < n; i++){
            int j = i - 1;
            for (; j >= 0;){
                if (arr[j] >= arr[i]){
                    j -= l[j];
                }
                else{
                    break;
                }
            }
            l[i] = i - j;
        }

        for (int i = 0; i < arr.size(); i++){
            dists[arr[i]] = max(dists[arr[i]], l[i] + r[i] - 1);
        }

        vector<int> res;
        int cum = n;
        for (int cur = 1; cur <= n; cur ++){
            if (dists[cur] == 0)
                break;
            cum = min(dists[cur], cum);
            if (cum >= n - cur + 1)
                res.push_back(1);
            else
                res.push_back(0);
        }

        while (res.size() < n){
            res.push_back(0);
        }

        reverse(res.begin(), res.end());
        for (auto& v: res) cout << v;
        cout << endl;
    }
    return 0;
}
