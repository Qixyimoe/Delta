#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 6e3 + 7;

int n, rt;
int h[N], t[N], f[N][2];

std::vector<int> G[N];

void dfs(int u) {
	f[u][0] = 0;
	f[u][1] = h[u];
	for (auto v : G[u]) {
		dfs(v);
		f[u][0] += std::max(f[v][0], f[v][1]);
		f[u][1] += f[v][0];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n;
	for (int i = 1; i <= n; i++)
		std::cin >> h[i];
	for (int i = 1, u, v; i < n; i++) {
		std::cin >> u >> v;
		G[v].push_back(u);
		t[u] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (!t[i]) {
			rt = i;
			break;
		}
	}
	dfs(rt);
	std::cout << std::max(f[rt][0], f[rt][1]) << "\n";
	return 0;
}
