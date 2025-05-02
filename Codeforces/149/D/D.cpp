#include <bits/stdc++.h>

#define int long long

constexpr int N = 807;
constexpr int P = 1000000007;

int n, ans;
int rgt[N], f[N][N][5][5];

std::string s;
std::stack<int> stc;

void dfs(int l, int r) {
	if (r == l + 1) {
		f[l][r][0][1] = f[l][r][0][2] = f[l][r][1][0] = f[l][r][2][0] = 1;
	}
	else if (rgt[l] == r) {
		dfs(l + 1, r - 1);
		for (int i = 0; i <= 2; i++) {
			for (int j = 0; j <= 2; j++) {
				if (i != 1) { f[l][r][1][0] += f[l + 1][r - 1][i][j]; f[l][r][1][0] %= P; }
				if (j != 1) { f[l][r][0][1] += f[l + 1][r - 1][i][j]; f[l][r][0][1] %= P; }
				if (i != 2) { f[l][r][2][0] += f[l + 1][r - 1][i][j]; f[l][r][2][0] %= P; }
				if (j != 2) { f[l][r][0][2] += f[l + 1][r - 1][i][j]; f[l][r][0][2] %= P; }
			}
		}
	}
	else {
		dfs(l, rgt[l]);
		dfs(rgt[l] + 1, r);
		for (int i = 0; i <= 2; i++) {
			for (int j = 0; j <= 2; j++) {
				for (int p = 0; p <= 2; p++) {
					for (int q = 0; q <= 2; q++) {
						if ((j == 1 && p == 1) || (j == 2 && p == 2))
							continue;
						f[l][r][i][q] += (f[l][rgt[l]][i][j] * f[rgt[l] + 1][r][p][q] % P);
						f[l][r][i][q] %= P;
					}
				}
			}
		}
	}
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> s;
	n = s.size();
	s = '$' + s;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '(') stc.push(i);
		else {
			rgt[stc.top()] = i;
			rgt[i] = stc.top();
			stc.pop();
		}
	}
	dfs(1, n);
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			ans += f[1][n][i][j];
			ans %= P;
		}
	}
	std::cout << ans << "\n";
	return 0;
}
