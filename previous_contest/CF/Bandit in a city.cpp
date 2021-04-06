#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 2e5 + 3;
vector<int> graph[N];

ll cnt[N];
int cum[N];
ll ans = 0;

void dfs(int cur) {
    cum[cur] = (graph[cur].size() == 0)?1:0;
    for (auto &v: graph[cur]) {
        dfs(v);
        cnt[cur] += cnt[v];
        cum[cur] += cum[v];
    }
    ans = max(ans, (ll) ceil((double) cnt[cur] / cum[cur]));
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 2; i <= n; i++){
        int v; cin >> v;
        graph[v].push_back(i);
    }

    for (int i = 1; i <= n; i++)
        cin >> cnt[i];

    dfs(1);

    cout << ans << endl;
    return 0;
}
