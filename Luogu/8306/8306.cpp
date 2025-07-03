#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 3e6 + 7;

int n, q;

struct TrieTree {
	int idx;
	int cnt[N], tr[N][65];

	void init(const int _n) {
		for (int i = 0; i < idx; i++) {
			for (int j = 0; j < 120; j++)
				tr[i][j] = 0;
		}
		for (int i = 0; i <= idx; i++) {
			cnt[i] = 0;
		}
		idx = 0;
	}

	int rewrite(char x) {
		if (x >= 'A' && x <= 'Z') return (x - 'A');
		if (x >= 'a' && x <= 'z') return (x - 'a' + 26);
		return x - '0' + 52;
	}

	void insert(std::string s) {
		int u = 0;
		for (int i = 0; i < s.size(); i++) {
			int v = rewrite(s[i]);
			if (!tr[u][v]) tr[u][v] = ++idx;
			u = tr[u][v];
			cnt[u]++;
		}
	}

	int find(std::string s) {
		int u = 0;
		for (int i = 0; i < s.size(); i++) {
			int v = rewrite(s[i]);
			if (!tr[u][v]) return 0;
			u = tr[u][v];
		}
		return cnt[u];
	}
} trie;

void solve() {
	std::cin >> n >> q;
	trie.init(n);
	for (int i = 1; i <= n; i++) {
		std::string s;
		std::cin >> s;
		trie.insert(s);
	}
	for (int i = 1; i <= q; i++) {
		std::string s;
		std::cin >> s;
		std::cout << trie.find(s) << "\n";
	}
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
