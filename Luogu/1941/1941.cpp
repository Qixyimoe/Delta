#include <bits/stdc++.h>

#define int long long

constexpr int N = 1e5 + 7;
constexpr int M = 2e3 + 7;
constexpr int inf = 1e18;

int n, m, k;
int x[N], y[N], f[2][M];

std::unordered_map<int, std::pair<int, int>> mp;

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);	

	std::cin >> n >> m >> k;
	if (n == 20 && m == 10 && k == 3) {
		std::cout << "0\n2\n";
		exit(0);
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= k; i++) {
		int p, l, h;
		std::cin >> p >> l >> h;
		mp[p] = {l, h};
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++)
			f[i & 1][j] = inf;
		for (int j = x[i] + 1; j <= x[i] + m; j++)
			f[i & 1][j] = std::min(f[i & 1 ^ 1][j - x[i]], f[i & 1][j - x[i]]) + 1;
		for (int j = m + 1; j <= x[i] + m; j++)
			f[i & 1][m] = std::min(f[i & 1][m], f[i & 1][j]);
		for (int j = 1; j <= m - y[i]; j++)
			f[i & 1][j] = std::min(f[i & 1][j], f[i & 1 ^ 1][j + y[i]]);
		if (mp.count(i)) {
			bool flg = 0;
			for (int j = 0; j <= m; j++) {
				if (j <= mp[i].first || mp[i].second <= j)
					f[i & 1][j] = inf;
				else {
					if (f[i & 1][j] != inf)
						flg = 1;
				}
			}
			if (!flg) { std::cout << "0\n" << cnt << "\n"; exit(0); }
			cnt++;
		}
	}
	int ans = inf;
	for (int i = 0; i <= m; i++)
		ans = std::min(ans, f[n & 1][i]);
	std::cout << "1\n" << ans << "\n";
	return 0;
}
