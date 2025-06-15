#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 5e5 + 7;

int n, m;
int a[N], s[N];

struct Fenwick {
	int tr[N << 1];

	#define lowbit(x) (x & (-x))

	void init() {
		for (int i = 1; i <= n; i++)
			tr[i] = s[i] - s[i - lowbit(i)];
	}

	void add(int i, int x) {
		for (; i <= n; i += lowbit(i))
			tr[i] += x;
	}

	int sum(int i) {
		int res = 0;
		for (; i; i -= lowbit(i))
			res += tr[i];
		return res;
	}
} bit;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	bit.init();
	for (int i = 1, opt, x, y; i <= m; i++) {
		std::cin >> opt >> x >> y;
		if (opt == 1) { bit.add(x, y); }
		else { std::cout << (bit.sum(y) - bit.sum(x - 1)) << "\n"; }
	}
	return 0;
}
