#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    ifstream read_in("sudoku.txt");
    // assert(read_in.is_open());
    int n;
    read_in >> n;
    vector<string> board(n);
    for(int i = 0; i < n; i++)
        read_in >> board[i];
    // cout << board[0].size() << endl;
    auto rang = [&](int i){
        return i / n;
    };

    auto col = [&](int i){
        return i % n;
    };

    vector<vi> inconf(n*n);
    for (int i = 0; i < n*n; i++){
        for (int j = i + 1; j < n*n; j++){
            if (rang(i) == rang(j) || col(i) == col(j)){
                inconf[i].push_back(j);
                inconf[j].push_back(i);
            }
        }
    }

    function<bool(int)> solve = [&](int i){
        if (i >= n*n) return true;
        // cout << i << endl;
        int r = rang(i), c = col(i);
        if (board[r][c] != '0'){
            for (auto v: inconf[i]) {
                if (board[rang(v)][col(v)] == board[r][c]) {
                    return false;
                }
            }
            return solve(i + 1);
        }else {
            vector<int> totry(n + 1, 1);
            for (auto j: inconf[i]){
                auto tmp = board[rang(j)][col(j)];
                if (tmp != '0'){
                    totry[tmp - '0'] = 0;
                }
            }
            for (int num = 1; num <= n; num++){
                if (totry[num]){
                    board[r][c] = num + '0';
                    if (solve(i + 1))
                        return true;
                    board[r][c] = '0';
                }
            }
            return false;
        }
    };
    solve(0);
    for (int i = 0; i < n; i++){
        cout << board[i] << endl;
    }
    return 0;
}
