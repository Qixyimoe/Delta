#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 8e4 + 7;
constexpr int R = 4e4;

int n, ans;
int f[N << 1];

std::pair<int, int> a[N << 1];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i].first >> a[i].second;
	memset(f, -0x3f, sizeof(f));
	f[R] = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i].first >= 0)
			for (int j = (R << 1); j >= a[i].first; j--)
				f[j] = std::max(f[j], f[j - a[i].first] + a[i].second);
		else
			for (int j = 0; j <= (R << 1) + a[i].first; j++)
				f[j] = std::max(f[j], f[j - a[i].first] + a[i].second);
	}
	for (int i = R; i <= (R << 1); i++)
		if (f[i] > 0)
			ans = std::max(ans, i + f[i] - R);
	std::cout << ans << "\n";
	return 0;
}
