#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vi dp;
void solve(int n, const vi& p) {
	for (auto i = 1; i <= n; ++i) {
		for (auto j = 1; j <= i; ++j) {
			const auto& c2 = dp[i - j] + p[j];
			if (dp[i] < c2) {
				dp[i] = c2;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	auto p = vi(n + 1);
	p[0] = 0;
	for (auto i = 1; i <= n; ++i) {
		cin >> p[i];
	}

	dp = vi(n + 1, -1);
	dp[0] = 0;
	solve(n, p);

	cout << dp[n];

	return 0;
}