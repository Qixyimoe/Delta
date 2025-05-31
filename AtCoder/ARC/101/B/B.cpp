#include <bits/stdc++.h>

#define int long long

constexpr int N = 1e5 + 7;

int n;
int a[N], b[N], t[N];
int sum[N];

struct Fenwick {
	int tr[N << 1 | 1];

	int lowbit(int x) { return x & -x; }

	void init() { memset(tr, 0, sizeof(tr)); }

	void add(int i, int x) {
		for (; i < (N << 1); i += lowbit(i))
			tr[i] += x;
	}

	int sum(int i) {
		int res = 0;
		for (; i; i -= lowbit(i))
			res += tr[i];
		return res;
	}
} bit;

int check(int x) {
	int res = 0;
	bit.init();
	for (int i = 1; i <= n; i++) {
		if (a[i] >= x) b[i] = 1;
		else b[i] = -1;
		sum[i] = sum[i - 1] + b[i];
	}
	bit.add(N, 1);
	for (int i = 1; i <= n; i++) {
		res += bit.sum(sum[i] + N);
		bit.add(sum[i] + N, 1);
	}
	if (res * 2 >= n * (n + 1) / 2)
		return 1;
	return 0;
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		t[i] = a[i];
	}
	std::sort(t + 1, t + n + 1);
	int l = 1, r = n, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(t[mid])) {
			l = mid + 1;
			ans = t[mid];
		} else {
			r = mid - 1;
		}
	}
	std::cout << ans << "\n";
	return 0;
}
