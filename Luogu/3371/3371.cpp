#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 7;
constexpr int M = 2e5 + 7;
constexpr int inf = 2147483647;

int n, m, s;
int dis[N];
bool vis[N];

struct edge {
	int to, val;
};

std::vector<edge> G[N];

struct node {
	int id, w;

	bool operator < (const node &rhs) const {
		return w > rhs.w;
	}
};

void dij() {
	for (int i = 1; i <= n; i++) {
		dis[i] = inf;
	}
	std::priority_queue<node> q;

	dis[s] = 0;
	q.push({s, 0});
	while (q.size()) {
		int u = q.top().id;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto i : G[u]) {
			auto [v, w] = i;
			if (dis[v] > dis[u] + w) {
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
	dij();
	for (int i = 1; i <= n; i++)
		std::cout << dis[i] << " ";
	std::cout << "\n";
	return 0;
}
