#include <bits/stdc++.h>

#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPR(i, a, b) for (int i = a; i > b; i--)

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int maxN = 2e5;
ll K, N;
int arr[maxN];
void solve(){
	cin >> N >> K;
	REP(i, 0, N)
		cin >> arr[i];
	int ans = 0;
	REP(i, 0, N)
		if (arr[i] == K){
			int j, k;
			for (j = i + 1, k = K - 1; j < N && k >= 1;k--, j++){
				if (arr[j] != k)
					break;
			}
			if (k == 0)
				ans ++;
		}
	cout << ans;
}

int main()
{
	int t;
	cin >> t;
	REP(t_, 1, t + 1)
	{
		cout << "Case #" << t_ << ": ";
		solve();
		cout << endl;
	}
	return 0;
}

// if file is used:
/*
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
*/
// g++ A.cpp -o temp -Wall && ./temp < input.in
// ios::sync_with_stdio(false);
// cin.tie(0);