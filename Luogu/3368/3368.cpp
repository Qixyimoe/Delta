#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 5e5 + 7;

int n, m;
int a[N], b[N];

struct Fenwick {
	int tr[N << 1];

	#define lowbit(x) (x & (-x))

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
		b[i] = a[i] - a[i - 1];
		bit.add(i, b[i]);
	}
	for (int i = 1, opt, x, y, k; i <= m; i++) {
		std::cin >> opt;
		if (opt == 1) {
			std::cin >> x >> y >> k;
			bit.add(x, k);
			bit.add(y + 1, -k);
		} else {
			std::cin >> x;
			std::cout << bit.sum(x) << "\n";
		}
	}
	return 0;
}
