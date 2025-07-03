#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e3 + 7;
constexpr int M = 3e3 + 7;
constexpr int inf = 1e9;

int n, m;
int dis[N], cnt[N];
bool vis[N];

std::vector<std::pair<int, int>> G[N];

void init() {
	for (int i = 1; i <= n; i++) {
		G[i].clear();
	}
}

bool spfa() {
	for (int i = 1; i <= n; i++) { dis[i] = inf, cnt[i] = 0, vis[i] = 0; }
	std::queue<int> q;
	q.push(1);
	dis[1] = 0, vis[1] = 1, cnt[1]++;
	while (q.size()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (auto i : G[u]) {
			auto [v, w] = i;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
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
}

void solve() {
	std::cin >> n >> m;
	for (int i = 1, u, v, w; i <= m; i++) {
		std::cin >> u >> v >> w;
		G[u].push_back({v, w});
		if (w >= 0)
			G[v].push_back({u, w});
	}
	std::cout << (spfa() ? "YES" : "NO") << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	while (t--) {
		init();
		solve();
	}
	return 0;
}
