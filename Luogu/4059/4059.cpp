#include <bits/stdc++.h>

#define int long long

constexpr int N = 2e3 + 7;
constexpr int inf = 1e18;

int n, m, a, b;
int x[N], y[N], d[N][N];
int f[N][N][3];

std::string s1, s2;

int rewrite(char x) {
    if (x == 'A') return 1;
    if (x == 'T') return 2;
    if (x == 'G') return 3;
    if (x == 'C') return 4;
} 

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> s1 >> s2;
    n = s1.size(), m = s2.size();
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++)
            std::cin >> d[i][j];
    }
    std::cin >> a >> b;
    for (int i = 1; i <= n; i++)
        x[i] = rewrite(s1[i - 1]);
    for (int i = 1; i <= m; i++)
        y[i] = rewrite(s2[i - 1]);
    for (int i = std::max(n, m); i; i--) {
        f[0][i][0] = f[i][0][0] = f[0][i][2] = f[i][0][1] = -inf;
        f[0][i][1] = f[i][0][2] = -a - b * (i - 1);
    }
    f[0][0][1] = f[0][0][2] = -inf;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j][0] = std::max({f[i - 1][j - 1][0], f[i - 1][j - 1][1], f[i - 1][j - 1][2]}) + d[x[i]][y[j]];
            f[i][j][1] = std::max({f[i][j - 1][1] - b, f[i][j - 1][0] - a, f[i][j - 1][2] - a});
            f[i][j][2] = std::max({f[i - 1][j][2] - b, f[i - 1][j][0] - a, f[i - 1][j][1] - a});
        }
    }
    std::cout << std::max({f[n][m][0], f[n][m][1], f[n][m][2]}) << "\n";
    return 0;
}
