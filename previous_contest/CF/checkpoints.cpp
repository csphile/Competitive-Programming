#include <bits/stdc++.h>

using namespace std;
const int N = 50;

int main(){
    int t; cin >> t; while (t--){
        unsigned long long k; cin >> k;
        if (k&1){
            cout << -1 << endl;
            continue;
        }
        k >>= 1;
        {
            vector<int> checks;
            int cnt = 0;
            for (int i = 0; i < 61; i++){
                if (k&((unsigned long long)1 << i)){
                    if (i > 0) cnt ++;
                    checks.push_back(1);
                    int tmp = i; while (--tmp > 0){
                        checks.push_back(0);
                    }
                }
            }
            while (cnt--){
                checks.push_back(1);
            }
            cout << checks.size() << endl;
            for(auto v: checks){cout << v << " ";}
            cout << endl;
        }
    }
    return 0;
}
