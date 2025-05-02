#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e6 + 7;

int n, m, k;
int _n, _k;
int ans1, ans2;
int p[N], a[N], b[N], c[N];
int cnt[N], vis[N];

std::bitset<N> f;

void dfs(int u, int i) {
	if (vis[u]) { a[++m] = i; return; }
	vis[u] = 1;
	dfs(p[u], i + 1);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> k;
	for (int i = 1; i <= n; i++)
		std::cin >> p[i];
	for (int i = 1; i <= n; i++) {
		if (!vis[i])
			dfs(i, 0);
	}
	_n = n, n = m, _k = k;
	
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (!_k) break;
		int t = std::min(a[i] / 2, _k);
		ans2 += 2 * t;
		_k -= t;
	}
	for (int i = 1; i <= n; i++) {
		if ((a[i] & 1) && _k) {
			ans2++;
			_k--;
		}
	}

	for (int i = 1; i <= _n; i++)
		cnt[a[i]]++;
	m = 0;
	for (int i = 1; i <= _n; i++) {
		if (cnt[i]) {
			b[++m] = i;
			c[m] = cnt[i];
		}
	}
	f[0] = 1;
	for (int i = 1; i <= m; i++) {
		int _c = c[i];
		for (int j = 1; _c; j <<= 1) {
			int t = std::min(j, _c);
			f |= f << (b[i] * t);
			_c -= t;
		}
	}
	if (f[k]) ans1 = k;
	else ans1 = k + 1;
	std::cout << ans1 << " " << ans2 << "\n";
	return 0;
}
