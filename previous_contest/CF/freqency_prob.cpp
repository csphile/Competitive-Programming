#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 7;

int process(int v, int d, vector<int>& arr){
    int ans = 0, cum = 0;
    unordered_map<int, int> ind;
    ind[0] = 0;
    for (int i = 0; i < arr.size(); i++){
        int x = arr[i];
        if (x == d)
            cum += 1;
        else if (x == v)
            cum -= 1;
        if (ind.count(cum)){
            ans = max(ans, i + 1 - ind[cum]);
        }
        else{
            ind[cum] = i + 1;
        }
    }
    return ans;
}

void solve(){
    int n; cin >> n; vector<int> arr(n); for (auto& v: arr) cin >> v;
    // for (auto v: arr) cout << v;
    unordered_map<int, int> freq_a;
    for (auto v: arr) freq_a[v]++;
    map<int, vector<int>> freq_rev;
    for (auto p: freq_a){
        freq_rev[p.second].push_back(p.first);
    }
    auto it = freq_rev.rbegin(); // most frequent elements
    if (it -> second.size() > 1){
        cout << n << endl;
        return ;
    }
    if (freq_a.size() <= 1) {
        cout << 0 << endl;
        return ;
    }
    int d = it -> second[0], ans = 0; // only one element;
    // cout << d << endl;
    for (auto it: freq_a){
        int v = it.first;
        if (v != d) ans = max(ans, process(v, d, arr));
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; t = 1; while(t--){
        solve();
    }
    return 0;
}
