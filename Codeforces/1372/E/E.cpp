#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 107;

int n, m;
i64 c[N][N][N], f[N][N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> m;
	for (int i = 1, x; i <= n; i++) {
		std::cin >> x;
		for (int j = 1, la, lb, ra, rb; j <= x; j++) {
			std::cin >> la >> ra;
			for (int lb = la; lb; lb--) {
				for (int rb = ra; rb <= m; rb++)
					for (int k = la; k <= ra; k++)
						c[lb][rb][k]++;
			}
		}
	}
	for (int i = 1; i <= m; i++)
		f[i][i] = c[i][i][i] * c[i][i][i];
	for (int i = 1; i <= m; i++)
		f[i][i - 1] = 0;
	for (int len = 2; len <= m; len++) {
		for (int l = 1; l + len - 1 <= m; l++) {
			int r = l + len - 1;
			for (int i = l; i <= r; i++)
				f[l][r] = std::max(f[l][r], c[l][r][i] * c[l][r][i] + f[l][i - 1] + f[i + 1][r]);
		}
	}
	std::cout << f[1][m] << "\n";
	return 0;
}
