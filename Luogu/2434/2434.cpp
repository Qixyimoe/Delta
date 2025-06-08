#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 5e4 + 7;

int n, l, r;

struct node {
	int l, r;
} a[N];

bool cmp(const node &a, const node &b) { return a.l < b.l; }

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i].l >> a[i].r;
	}
	std::sort(a + 1, a + n + 1, cmp);
	l = a[1].l, r = a[1].r;
	for (int i = 2; i <= n; i++) {
		if (r < a[i].l) { std::cout << l << " " << r << "\n"; l = a[i].l; }
		l = std::min(l, a[i].l);
		r = std::max(r, a[i].r);
	}
	std::cout << l << " " << r << "\n";
	return 0;
}
