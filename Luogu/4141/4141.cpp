#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e3 + 7;

int n, m;
int w[N], f[N], g[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> m;
	for (int i = 1; i <= n; i++)
		std::cin >> w[i];
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= w[i]; j--)
			f[j] = (f[j] + f[j - w[i]]) % 10;
	}
	for (int i = 1; i <= n; i++) {
		g[0] = 1;
		for (int x = 1; x <= m; x++) {
			if (w[i] > x) g[x] = f[x] % 10;
			else g[x] = (f[x] - g[x - w[i]] + 10) % 10;
			std::cout << g[x];
		}
		std::cout << "\n";
	}
	return 0;
}
