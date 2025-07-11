#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e6 + 7;

int n, t0t;
i64 sum;
int lsh[N];

struct ques {
    int opt;
    int k, t, x, y;
} a[N];

struct Fenwick {
    int n;
    i64 tr[N];

    int lowbit(int x) { return (x & -x); }

    void init(const int _n) { n = _n; }

    void modify(int i, int x) {
        for (; i <= n; i += lowbit(i))
            tr[i] += x;
    }

    i64 ask(int i) { return tr[i]; }

    i64 query(int i) {
        i64 res = 0;
        for (; i; i -= lowbit(i))
            res += tr[i];
        return res;
    }
} bit[2];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i].opt;
        if (a[i].opt == 1) {
            std::cin >> a[i].t >> a[i].x >> a[i].y;
            lsh[++t0t] = a[i].x;
        } else {
            std::cin >> a[i].k;
        }
    }
    std::sort(lsh + 1, lsh + t0t + 1);
    t0t = std::unique(lsh + 1, lsh + t0t + 1) - lsh - 1;
    for (int i = 1; i <= n; i++) {
        if (a[i].opt == 1)
            a[i].x = std::lower_bound(lsh + 1, lsh + t0t + 1, a[i].x) - lsh;
    }
    bit[0].init(t0t);
    bit[1].init(t0t);
    for (int i = 1; i <= n; i++) {
        if (a[i].opt == 1) {
            if (!a[i].t)
                bit[0].modify(a[i].x, a[i].y);
            else {
                bit[1].modify(a[i].x + 1, a[i].y);
                sum += a[i].y;
            }
        } else {
            int k = a[i].k;
            if (!a[k].t)
                bit[0].modify(a[k].x, -a[k].y);
            else {
                bit[1].modify(a[k].x + 1, -a[k].y);
                sum -= a[k].y;
            }
        }
        int p1 = 0, p2 = 0;
        i64 s0 = 0, f1 = 0,
            s1 = sum, f2 = 0;
        for (int i = 20; i >= 0; i--) {
            int pt = p1 + (1 << i),
                n0 = s0 + bit[0].ask(pt),
                n1 = s1 - bit[1].ask(pt);
            if (pt > t0t) continue;
            if (n0 < n1) { p1 = pt; s0 = n0; s1 = n1; }
        }
        f1 = s0, s0 = 0, s1 = sum;
        if (p1 < t0t) {
            f2 = std::min(bit[0].query(p1 + 1), sum - bit[1].query(p1 + 1));
            for (int i = 20; i >= 0; i--) {
                int pt = p2 + (1 << i), n0 = s0 + bit[0].ask(pt), n1 = s1 - bit[1].ask(pt);
                if (pt > t0t) continue;
                if (n0 < n1) { p2 = pt; s0 = n0; s1 = n1; }
                else if (std::min(n0, n1) == f2) { p2 = pt; s0 = n0; s1 = n1; }
            }
        }
        if (std::max(f1, f2) == 0) { std::cout << "Peace\n"; }
        else if (f1 > f2) { std::cout << lsh[p1] << " " << f1 * 2 << "\n"; }
        else { std::cout << lsh[p2] << " " << f2 * 2 << "\n";  }
    }
    return 0;
}
