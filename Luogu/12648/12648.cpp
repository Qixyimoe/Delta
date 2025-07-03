#include <bits/stdc++.h>

#define int long long

constexpr int N = 1e6 + 7;

int n, l, k, cnt;
int a[N], b[N], s[N];
bool flg[N];

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> l >> n >> k;
	if (k <= n) { for (int i = 1; i <= k; i++) std::cout << "0\n"; exit(0); }
	a[0] = -1;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		b[i] = a[i] - a[i - 1] - 1;
	}
	b[n + 1] = l - a[n];

	int idx = 1;
	for (int i = 1; i <= n; i++)
		s[++cnt] = 0;
	k -= n;
	while (k) {
		if (b[1] >= idx) { s[++cnt] = idx; k--; }
		if (!k) break;
		if (b[n + 1] >= idx) { s[++cnt] = idx; k--; }
		if (!k) break;
		for (int i = 2; i <= n; i++) {
			if (flg[i]) continue;
			if (b[i] / 2 >= idx) {
				s[++cnt] = idx, k--;
				if (!k) break;
				s[++cnt] = idx, k--;
				if (!k) break;
			} else if (idx * 2 - 1 == b[i]) {
				s[++cnt] = idx, k--;
			} else {
				flg[i] = 1;
			}
			if (!k) break;
		}
		idx++;
	}
	for (int i = 1; i <= cnt; i++) {
		std::cout << s[i] << "\n";
	}
	return 0;
}
