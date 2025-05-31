#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 7;

int n;
int a[N << 1];

int check1(int i, int j, int k) {
	return a[i] <= k && a[j] <= k;
}

int check2(int i, int j, int k) {
	return a[i] > k && a[j] > k;
}

int check(int k) {
	for (int i = 0; i < n - 1; i++) {
		if (check1(n + i, n + i + 1, k) || check1(n - i, n - i - 1, k))
			return 1;
		if (check2(n + i, n + i + 1, k) || check2(n - i, n - i - 1, k))
			return 0;
	}
	return check1(1, 1, k);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n;
	for (int i = 1; i <= 2 * n - 1; i++)
		std::cin >> a[i];
	int l = 1, r = 2 * n - 1;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	std::cout << r << "\n";
	return 0;
}
