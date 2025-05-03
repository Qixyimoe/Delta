#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 57;
constexpr int M = 4e3 + 7;

int n, m;
int a[M], b[M], c[M], d[M];
int ans[N], f[N][N][M], cnt[N][N];

std::pair<int, int> t[N][N][M];

void dfs(int l, int r, int p) {
	if (l > r) return;
	auto it = t[l][r][p];
	ans[it.second] = d[it.first];
	dfs(l, it.second - 1, it.first);
	dfs(it.second + 1, r, it.first);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		std::cin >> a[i] >> b[i] >> c[i];
		d[i] = c[i];
	}
	std::sort(d + 1, d + m + 1);
	for (int i = 1; i <= m; i++) {
		c[i] = std::lower_bound(d + 1, d + m + 1, c[i]) - d;
	}
	for (int i = m; i; i--) {
		for (int j = 1; j <= m; j++) {
			if (c[j] == i) {
				for (int l = 1; l <= a[j]; l++)
					for (int r = b[j]; r <= n; r++)
						cnt[l][r]++;
			}
		}
		for (int len = 1; len <= n; len++) {
			for (int l = 1, r = len; r <= n; l++, r++) {
				f[l][r][i] = f[l][r][i + 1];
				t[l][r][i] = t[l][r][i + 1];
				for (int k = l; k <= r; k++) {
					int dlt = cnt[l][r] - cnt[l][k - 1] - cnt[k + 1][r],
						v = f[l][k - 1][i] + f[k + 1][r][i] + dlt * d[i];
					if (v > f[l][r][i]) {
						f[l][r][i] = v;
						t[l][r][i] = {i, k};
					}
				}
				if (t[l][r][i].first == 0)
					t[l][r][i] = {i, l};
			}
		}
	}
	std::cout << f[1][n][1] << "\n";
	dfs(1, n, 1);
	for (int i = 1; i <= n; i++)
		std::cout << ans[i] << " ";
	std::cout << "\n";
	return 0;
}
