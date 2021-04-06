#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int t, W, H, L, U, R, D;

ld ans;
constexpr int maxn = 200001;
ld f[maxn], p[maxn];

ld C(int m, int n){
    return f[m + n] - f[m] - f[n];
}

void solve(){
    cout << setprecision(20);
    cin >> W >> H >> L >> U >> R >> D;
    for (int i = 1; i < maxn; i++){
        f[i] = f[i - 1] + log((ld)i);
    }
    for (int i = 1; i < maxn; i++){
        p[i] = p[i - 1] + log((ld)2);
    }
    ans = 0;
    if(R < W) 
        for(int i = 1; i < U; i += 1)
            ans += exp(C(i - 1, R - 1) - p[i + R - 1]);

    if(D < H) 
        for(int i = 1; i < L; i += 1)
            ans += exp(C(i - 1, D - 1) - p[i + D - 1]); 

    cout << ans << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    for (int t_ = 1; t_ <= t; ++t_) {
        cout << "Case #" << t_ << ": ";
        solve();
    }
    return 0;
}
