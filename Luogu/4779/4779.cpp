#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 7;
constexpr int M = 2e5 + 7;

int n, m, s;
int dis[N], vis[N];

std::vector<std::pair<int, int>> G[M << 1];

struct element {
	int id, w;

	bool operator < (const element &rhs) const {
		return w > rhs.w;
	}
};

void Dij() {
	std::priority_queue<element> q;
	memset(dis, 0x7f, sizeof(dis));
	dis[s] = 0;
	q.push({s, 0});
	while (q.size()) {
		auto [u, ow] = q.top();
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto i : G[u]) {
			auto [v, w] = i;
			if (dis[v] > (i64) dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({v, dis[v]});
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> m >> s;
	for (int i = 1, u, v, w; i <= m; i++) {
		std::cin >> u >> v >> w;
		G[u].push_back({v, w});
	}
	Dij();
	for (int i = 1; i <= n; i++)
		std::cout << dis[i] << " ";
	std::cout << "\n";
	return 0;
}
