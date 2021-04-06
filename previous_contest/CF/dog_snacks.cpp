#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

int main(){
    vector<int> adj[N];
    int t; cin >> t; while (t--){
        int n; cin >> n;
        for (int i = 1; i <= n; i++){
            adj[i].clear();
        }
        for (int i = 0; i < n - 1; i++){
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ans = 0;
        function<int(int, int)> dfs = [&](int cur, int prev){
            // return the k required to visit all nodes under cur and go back to prev
            if (adj[cur].size() == 1 && cur != 1){
                return 1;
            }
            vector<int> dists;
            for (auto c: adj[cur]){
                if (c == prev)
                    continue;
                int tmp = dfs(c, cur);
                dists.push_back(tmp);
            }
            sort(dists.begin(), dists.end());
            if (dists.size() > 1){
                if (cur == 1){
                    ans = max({ans, dists.back(), dists[dists.size() - 2] + 1});
                }
                else ans = max(ans, dists.back() + 1);
            }
            ans = max(ans, dists[0]);
            return dists[0] + 1;
        };
        dfs(1, 0);
        cout << ans << endl;
    }
    return 0;
}
