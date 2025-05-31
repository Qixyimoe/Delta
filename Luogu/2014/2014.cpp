#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 307;

int n, m;
int f[N][N];

std::vector<int> G[N << 1];

void dfs(int u) {
	for (auto v : G[u])
		dfs(v);
	for (auto v : G[u]) {
		for (int i = m; i; i--)
			for (int j = 0; j < i; j++)
				f[u][i] = std::max(f[u][i], f[u][i - j] + f[v][j]);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> m;
	m++;
	for (int i = 1, x; i <= n; i++) {
		std::cin >> x >> f[i][1];
		G[x].push_back(i);
	}
	dfs(0);
	std::cout << f[0][m] << "\n";
	return 0;
}
