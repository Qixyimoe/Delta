#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 107;

int n, c;
int a[N], b[N], sum[N];
int f[N][N][2];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> c;
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i] >> b[i];
		sum[i] = sum[i - 1] + b[i];
	}

	f[c][c][0] = f[c][c][1] = 0;
	for (int l = 2; l <= n; l++) {
		for (int i = 1; i + l - 1 <= n; i++) {
			int j = i + l - 1;
			f[i][j][0] = std::min(
				f[i + 1][j][0] + (a[i + 1] - a[i]) * (sum[i] + sum[n] - sum[j]),
				f[i + 1][j][1] + (a[j] - a[i]) * (sum[i] + sum[n] - sum[j])
			);
			f[i][j][1] = std::min(
				f[i][j - 1][0] + (a[j] - a[i]) * (sum[i - 1] + sum[n] - sum[j - 1]),
				f[i][j - 1][1] + (a[j] - a[j - 1]) * (sum[i - 1] + sum[n] - sum[j - 1])
			);
		}
	}
	std::cout << std::min(f[1][n][0], f[1][n][1]) << "\n";
	return 0;
}
