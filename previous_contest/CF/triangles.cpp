#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n; vector<string> mat(n); for (auto& arr: mat){ cin >> arr; }
    unordered_map<int, vector<pair<int, int>>> rec;
    for (int i = 0; i < mat.size(); i++){
        for (int j = 0; j < mat[i].size(); j++) {
            rec[mat[i][j] - '0'].push_back({i, j});
        }
    }

    for (int i = 0; i <= 9; i++){
        if (rec[i].size() <= 1){
            cout << 0 << " ";
        }
        else{
            sort(rec[i].begin(), rec[i].end(), [](auto& l, auto& r){
                return l.second < r.second;
            });
            int ans = 0, m = rec[i][0].second, M = rec[i].back().second;
            for (int j = 0; j < rec[i].size(); j++){
                ans = max(ans, max(n - 1 - rec[i][j].first, rec[i][j].first)*max(rec[i][j].second - m, M - rec[i][j].second));
            }
            sort(rec[i].begin(), rec[i].end(), [](auto& l, auto& r){
                return l.first < r.first;
            });
            m = rec[i][0].first, M = rec[i].back().first;
            for (int j = 0; j < rec[i].size(); j++){
                ans = max(ans, max(n - 1 - rec[i][j].second, rec[i][j].second)*max(rec[i][j].first - m, M - rec[i][j].first));
            }
            cout << ans << " ";
        }
    }
    cout << endl;
}

int main(){
    int t; cin >> t; while (t--){
        solve();
    }
    return 0;
}
