#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2007;
constexpr int inf = 0x7f7f7f7f;

int n, m;
int dis[N], cnt[N], vis[N];
int ok[N][N];

std::vector<std::pair<int, int>> G[N << 1];

struct node {
    int id, val;
    
    bool operator < (const node &rhs) const {
        return val > rhs.val;
    }
};

void Dij(int s) {
    std::priority_queue<node> q;
    std::memset(dis, 0x7f, sizeof(dis));
    dis[s] = 0, cnt[s] = 1;
    q.push({s, 0});

    while (q.size()) {
        auto [u, ow] = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto i : G[u]) {
            auto [v, w] = i;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u];
                q.push({v, dis[v]});
            } else if (dis[v] == dis[u] + w) {
                cnt[v] += cnt[u];
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for (int i = 1, u, v, w; i <= m; i++) {
        std::cin >> u >> v >> w;
        if (ok[u][v] == w)
            continue;
        G[u].push_back({v, w});
        ok[u][v] = w;
    }
    Dij(1);
    if (dis[n] == inf)
        std::cout << "No answer\n";
    else
        std::cout << dis[n] << " " << cnt[n] << "\n";
    return 0;
}
