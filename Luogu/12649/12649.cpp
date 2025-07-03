#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 7;

int n, ans;
int ncnt, ocnt;
int otd[N];
bool vis[N];

std::vector<int> G[N];

int dfs(int u) {
	vis[u] = 1, ncnt++;
	if (!otd[u]) ocnt++;
	for (auto v : G[u]) {
		if (!vis[v])
			dfs(v);
	}
	return ncnt;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n;
	for (int i = 1, u, v; i <= n; i++) {
		std::cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		otd[u]++;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			ncnt = ocnt = 0;
			int res = dfs(i);
			if (res == 1) continue;
			if (ocnt >= 2) { std::cout << "-1\n"; exit(0); }
			ans += (res + 1);
		}
	}
	std::cout << ans << "\n";
	return 0;
}
