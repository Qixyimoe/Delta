#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::pair<int, int>> G[n << 1];
	for (int i = 1, u, v, w; i <= m; i++) {
		std::cin >> u >> v >> w;
		G[u].push_back({v, w});
		if (w >= 0)
			G[v].push_back({u, w});
	}


	std::vector<int> dis(n + 1, 1e9), vis(n + 1), cnt(n + 1);
	auto spfa = [&]() -> bool {
		std::queue<int> q;
		q.push(1);
		dis[1] = 0, vis[1] = 1, cnt[1]++;
		
		while (q.size()) {
			int u = q.front();
			q.pop();
			vis[u] = 0;
			for (auto i : G[u]) {
				auto [v, w] = i;
				if (dis[v] > (i64) dis[u] + w) {
					dis[v] = (i64) dis[u] + w;
					if (!vis[v]) {
						vis[v] = 1;
						q.push(v);
						cnt[v]++;
						if (cnt[v] > n)
							return 1;
					}
				}
			}
		}
		return 0;
	};

	std::cout << (spfa() ? "YES" : "NO") << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
