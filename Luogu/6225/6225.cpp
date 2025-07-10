#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 7;

int n, q;
int a[N];

struct Fenwick {
    int tr[N << 1];

    int lowbit(int x) { return (x & -x); }

    void modify(int i, int x) {
        for (; i <= n; i += lowbit(i))
            tr[i] ^= x;
    }

    int query(int i) {
        int res = 0;
        for (; i; i -= lowbit(i))
            res ^= tr[i];
        return res;
    }
} bit[2];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        bit[i & 1].modify(i, a[i]);
    }
    for (int i = 1, opt, x, y; i <= q; i++) {
        std::cin >> opt >> x >> y;
        if (opt == 1) {
            bit[x & 1].modify(x, a[x] ^ y);
            a[x] = y;
        } else {
            int res = 0;
            if (!((x & 1) ^ (y & 1)))
                res += bit[x & 1].query(y) ^ bit[x & 1].query(x - 1);
            std::cout << res << "\n";
        }
    }
    return 0;
}
