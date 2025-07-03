#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 107;

int n;
int ind[N];

std::vector<int> G[N];

void topo() {
	std::queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!ind[i])
			q.push(i);
	}
	while (q.size()) {
		int u = q.front();
		q.pop();
		std::cout << u << " ";
		for (auto v : G[u]) {
			ind[v]--;
			if (ind[v] == 0)
				q.push(v);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n;
	for (int i = 1, x; i <= n; i++) {
		while (1) {
			std::cin >> x;
			if (x == 0) break;
			G[i].push_back(x);
			ind[x]++;
		}
	}
	topo();
	return 0;
}
