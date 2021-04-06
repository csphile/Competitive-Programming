#include <bits/stdc++.h>

#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPR(i, a, b) for (int i = a; i > b; i--)

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
const int maxN = 1e5;
int N, arr[maxN], cnt[2*100*maxN + 1];

void solve(){
	memset(cnt, 0, sizeof(cnt));
	ll ans = 0;
	cin >> N;
	ll lower = 0, upper = 0;
	REP(i, 0, N){
		cin >> arr[i];
		if (arr[i] < 0)
			lower -= arr[i];
		else 
			upper += arr[i];
	}
	int cum = 0;
	cnt[lower]++;
	REP(i, 0, N){
		cum += arr[i];
		for (int j = 0; j*j <= upper; j++){
			if (lower + (cum - j*j) >= 0)
				ans += cnt[lower + cum - j*j];
		}
		++cnt[lower + cum];
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