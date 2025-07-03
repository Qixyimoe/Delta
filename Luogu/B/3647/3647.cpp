#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 107;
constexpr int M = 4507;

int n, m;
int f[N][N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> m;
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= n; i++)
		f[i][i] = 0;
	for (int i = 1, u, v, w; i <= m; i++) {
		std::cin >> u >> v >> w;
		f[u][v] = f[v][u] = std::min(f[u][v], w);
	}
	for (int k = 1; k <= n; k++) {
		for (int u = 1; u <= n; u++) {
			for (int v = 1; v <= n; v++)
				f[u][v] = std::min(f[u][v], f[u][k] + f[k][v]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			std::cout << f[i][j] << " ";
		std::cout << "\n";
	}
	return 0;
}
