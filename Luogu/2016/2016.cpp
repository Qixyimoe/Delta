#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1500 + 7;

int n;
int f[N][2];

std::vector<int> G[N << 1];

void dfs(int u, int fa) {
	f[u][1] = 1, f[u][0] = 0;
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs(v, u);
		f[u][0] += f[v][1];
		f[u][1] += std::min(f[v][1], f[v][0]);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n;
	for (int i = 1, x, y, k; i <= n; i++) {
		std::cin >> x >> k;
		for (int j = 1; j <= k; j++) {
			std::cin >> y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
	}
	dfs(0, 0);
	std::cout << std::min(f[0][0], f[0][1]) << "\n";
	return 0;
}
