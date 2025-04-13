#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 47007;

int n, d;
int usx[10], val[N], to[N];
int f[105][N][6];

std::string opt;

int inbit(int n, int b) { return n / usx[b] % 6; }

void chkmax(int &a, int b) { a = std::max(a, b); }

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    std::cin >> n >> d;
    std::cin >> opt;
    opt = '$' + opt;
    for (int i = 1; i <= d; i++)
        opt[i] -= '0';

    usx[0] = 1;
    for (int i = 1; i <= n; i++)
        usx[i] = usx[i - 1] * 6;

    for (int i = 0; i < usx[n]; i++) {
        int cnt = 0;
        for (int j = 0; j < n - 1; j++) {
            int u = inbit(i, j), k = 2, s = 0;
            if (u == 0 || u != inbit(i, j + 1))
                continue;
            cnt++, s = u * usx[j] + u * usx[j + 1], j++;
            if (cnt > 1) {
                val[i] = -1;
                break;
            }
            while (inbit(i, j + 1) == u)
                j++, k++, s += u * usx[j];
            val[i] = k * (1 << u), to[i] = i - s;
        }
        if (cnt == 0)
            val[i] = 0, to[i] = i;
    }

    memset(f, -0x3f, sizeof(f));
    f[0][0][0] = 0;
    for (int i = 1; i <= d; i++) {
        for (int j = 0; j < usx[n]; j++) {
            if (val[j] != 0)
                continue;
            chkmax(f[i][j][opt[i]], f[i - 1][j][0]);
            for (int k = 0; k < n; k++) {
                if (inbit(j, k) != 0)
                    continue;
                for (int st = 0; st < 6; st++) {
                    int nxt = j + usx[k] * opt[i], v = 0, t = 1;
                    while (val[nxt] != 0) {
                        v += val[nxt];
                        nxt = to[nxt] + (opt[i] + t) % 6 * usx[k];
                        t++;
                    }
                    chkmax(f[i][nxt][st], f[i - 1][j][st] + v);
                }
            }
        }
        for (int j = 0; j < usx[n]; j++) {
            if (val[j] != 0)
                continue;
            for (int k = 0; k < n; k++) {
                if (inbit(j, k))
                    continue;
                for (int st = 1; st < 6; st++) {
                    int nxt = j + usx[k] * st, v = 0, t = 1;
                    while (val[nxt] != 0) {
                        v += val[nxt];
                        nxt = to[nxt] + (st + t) % 6 * usx[k];
                        t++;
                    }
                    chkmax(f[i][nxt][0], f[i][j][st] + v);
                }
            }
        }
    }

    int ans = 0;
    for (int a = 1; a <= d; a++)
        for (int i = 0; i < usx[n]; i++) {
            if (val[i] != 0)
                continue;
            for (int st = 0; st < 6; st++)
                ans = std::max(ans, f[a][i][st]);
        }
    std::cout << ans << "\n";
    return 0;
}
