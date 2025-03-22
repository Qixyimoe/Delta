#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 3e3 + 7;
constexpr int inf = 0x3f3f3f3f;

int n, m, ecnt;
int h[N], dis[N], d[N], num[N];
bool vis[N];

struct edge {
	int to, w, nxt;
} e[N << 2];

void addedge (int u, int v, int w) {
	e[++ecnt].to = v;
	e[ecnt].w = w;
	e[ecnt].nxt = h[u];
	h[u] = ecnt;
}

bool spfa (int x) {
    std::queue<int> q;
	q.push(x);
    memset(dis, inf, sizeof(dis));
	dis[x] = 0, vis[x] = 1, num[x]++;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = h[u]; i; i = e[i].nxt)
			if (dis[e[i].to] > dis[u] + e[i].w) {
				dis[e[i].to] = dis[u] + e[i].w;
				if (!vis[e[i].to]) {
					q.push(e[i].to);
					vis[e[i].to] = 1;
					num[e[i].to]++;
					if (num[e[i].to] == n + 1)
						return 0;
				}
			}
	}
	return 1;
}

struct element {
	int dis, id;

    friend bool operator < (element x, element y) {
        return x.dis > y.dis;
    }
};

void dijkstra (int x) {
	std::priority_queue<element> q;
    memset(d, inf, sizeof(d));
	memset(vis, 0, sizeof(vis));
	d[x] = 0;
	q.push({0, x});
	while (!q.empty()) {
		element u = q.top();
		q.pop();
		if (vis[u.id])
			continue;
		vis[u.id] = true;
		for (int i = h[u.id]; i; i = e[i].nxt) {
			if (d[e[i].to] > d[u.id] + e[i].w) {
				d[e[i].to] = d[u.id] + e[i].w;
				q.push({d[e[i].to], e[i].to});
			}
        }
	}
}

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	std::cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;
		addedge(u, v, w);
	}
	for (int i = 1; i <= n; i++)
		addedge(n + 1, i, 0);
	bool flag = spfa(n + 1);
	if (!flag) {
		std::cout << "-1\n";
		exit(0);
	}
	for (int i = 1; i <= n; i++)
		for (int j = h[i]; j != 0; j = e[j].nxt)
			e[j].w += dis[i] - dis[e[j].to];
	for (int i = 1; i <= n; i++) {
		dijkstra(i);
		i64 ans = 0;
		for (int j = 1; j <= n; j++) {
			if (d[j] == inf)
				ans += 1ll * 1e9 * j;
			else
				ans += 1ll * (d[j] - dis[i] + dis[j]) * j;
		}
		std::cout << ans << "\n";
	}
	return 0;
}
