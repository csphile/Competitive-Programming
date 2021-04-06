#include <iostream>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
long long t, N, P, res;

int main() {
  cin >> t;
  for (int t_ = 1; t_ <= t; ++t_) {
    cin >> N >> P;
    vector<int> players(N);
    for (int j = 0; j < N; ++j){
      cin >> players[j];
    }
    sort(players.begin(), players.end());
    res = 0;
    long long training_time = 0;
    for (int j = 0; j < P; ++j) training_time += players[P - 1] - players[j];
    res = training_time;
    for (int j = 0; j < N - P; ++j){
      training_time += P * (players[j + P] - players[j + P - 1]);
      training_time -= players[j + P] - players[j];
      res = min(res, training_time);
    }
    cout << "Case #" << t_ << ": " << res << endl;
  }
  return 0;
}
