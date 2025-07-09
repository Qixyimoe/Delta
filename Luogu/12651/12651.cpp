#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::string s, t;
	std::cin >> s;
	s = '$' + s;
	t.resize(s.size());

	int l = 0, p = 0;
	for (l = 1; l <= n; l++) {
		if (s[l] == '1')
			break;
	}
	if (l > n) { std::cout << "0\n"; return; }
	for (p = l + 1; p <= n; p++) {
		if (s[p] == '0')
			break;
	}
	if (p > n) {
		for (int i = l; i < n; i++)
			std::cout << s[i];
		std::cout << (l > 1 ? 1 : 0) << "\n";
		return;
	}
	int k = 0;
	for (k = p; k <= n; k++) {
		if (s[k] == '1')
			break;
	}

	int cnt = std::min(k - p, p - l);
	auto calc = [&](int l1, int r1, int l2, int r2) -> void {
		int i, j;
		for (i = r1, j = r2; j >= l2; i--, j--)
			t[i - l1 + 1] = (s[i] == s[j] ? '0' : '1');
		for (; i >= l1; i--)
			t[i - l1 + 1] = s[i];
	};
	calc(l, n, p - cnt, n - cnt);
	for (int i = 1; i <= n - l + 1; i++)
		std::cout << t[i];
	std::cout << "\n";
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
