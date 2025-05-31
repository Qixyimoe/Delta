#include <bits/stdc++.h>

#define int long long

constexpr int N = 2e5 + 7;

int n;
int a[N];
int c[N], dp[N], siz[N];

std::vector<int> G[N];

void clear() {
	for (int i = 1; i <= n; i++) {
		dp[i] = c[i] = siz[i] = 0;
		G[i].clear();
	}
}

void dfs1(int u, int fa) {
	siz[u] = 1;
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs1(v, u);
		siz[u] += siz[v];
		dp[u] += dp[v] + siz[v] * (a[u] ^ a[v]);
	}
	c[u] = dp[u];
}

void dfs2(int u, int fa) {
	for (auto v : G[u]) {
		if (v == fa) continue;
		c[v] += c[u] - (dp[v] + siz[v] * (a[u] ^ a[v])) + (n - siz[v]) * (a[u] ^ a[v]);
		dfs2(v, u);
	}
}

void solve() {
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1, u, v; i < n; i++) {
		std::cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	for (int i = 1; i <= n; i++) {
		std::cout << c[i] << " ";
	}
	std::cout << "\n";
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	while (t--) {
		solve();
		clear();
	}
	return 0;
}
