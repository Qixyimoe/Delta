#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 3007;

int n, m;
int a[N][N], b[N][N], v[N][N];
int ul[N][N], ur[N][N], lv[N][N], rv[N][N];
int pl[N << 1], pr[N << 1], fl[N << 1], fr[N << 1];

std::string s[N];

template <typename T>
void chkmax(T &x, T y) { if (x < y) x = y; }

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> s[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			a[i][j] = s[i][j - 1] - '0';
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j]) {
				ul[i][j] = ul[i - 1][j - 1] + 1;
				ur[i][j] = ur[i - 1][j + 1] + 1;
				v[i][j] = ul[i][j] + ur[i][j] - 1;
			}
			b[i][j] = std::max({b[i - 1][j - 1], b[i - 1][j], b[i - 1][j + 1], v[i][j]});
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j]) {
				lv[i][j] = std::max(ul[i][j], lv[i + 1][j - 1] + 1);
				rv[i][j] = std::max(ur[i][j], rv[i + 1][j + 1] + 1);
				chkmax(pl[j + n - i + 1], lv[i][j]);
				chkmax(pr[i + j], rv[i][j]);
				chkmax(fl[j + n - i + 1], v[i][j]);
				chkmax(fr[i + j], v[i][j]);
			}
		}
	}
	for (int i = 1; i <= n + m; i++) {
		chkmax(pl[i], pl[i - 1]);
		chkmax(fr[i], fr[i - 1]);
	}
	for (int i = n + m; i >= 1; i--) {
		chkmax(pr[i], pr[i + 1]);
		chkmax(fl[i], fl[i + 1]);
	}
	int bm = 0, em = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if ((i + j) & 1)
				chkmax(bm, v[i][j]);
			else
				chkmax(em, v[i][j]);
		}
	}
	int ans = bm + em;
	for (int i = 1; i <= n + m - 1; i++) {
		chkmax(ans, pl[i] + fl[i + 1]);
		chkmax(ans, fr[i] + pr[i + 1]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			chkmax(ans, v[i][j] + b[i - 1][j]);
	}
	std::cout << ans << "\n";
	return 0;
}
