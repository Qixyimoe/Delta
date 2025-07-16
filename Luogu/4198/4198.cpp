#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 7;

int n, m;
double a[N];

struct SegTree {
    struct node {
        int len;
        double mx;
    } tr[N << 2];

    #define ls(o) (o << 1)
    #define rs(o) (o << 1 | 1)

    void pushup(int o) {
        tr[o].mx = std::max(tr[ls(o)].mx, tr[rs(o)].mx);
    }

    int maintain(int o, int l, int r, double k) {
        if (tr[o].mx <= k) return 0;
        if (a[l] > k) return tr[o].len;
        if (l == r) return (a[l] > k);
        int mid = (l + r) >> 1;
        if (tr[ls(o)].mx <= k) return maintain(rs(o), mid + 1, r, k);
        return maintain(ls(o), l, mid, k) + tr[o].len - tr[ls(o)].len;
    }

    void modify(int o, int l, int r, int t, int c) {
        if (l == r && l == t) {
            tr[o] = {1, 1.0 * c / t};
            return;
        }
        int mid = (l + r) >> 1;
        if (t <= mid) modify(ls(o), l, mid, t, c);
        if (t > mid) modify(rs(o), mid + 1, r, t, c);
        pushup(o);
        tr[o].len = tr[ls(o)].len + maintain(rs(o), mid + 1, r, tr[ls(o)].mx);
    }
} seg;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for (int i = 1, x, y; i <= m; i++) {
        std::cin >> x >> y;
        a[x] = 1.0 * y / x;
        seg.modify(1, 1, n, x, y);
        std::cout << seg.tr[1].len << "\n";
    }
    return 0;
}
