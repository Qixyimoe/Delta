#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 7;
constexpr int P = 1e9 + 7;

int n, m;
int a[N];

struct Matrix {
    int m[4][4];

    void clear() {
        memset(m, 0, sizeof(m));
    }

    void init() {
        for (int i = 0; i < 4; i++) {
            m[i][i] = 1;
        }
    }

    bool empty() {
        if (m[1][1] != 1) return 0;
        if (m[1][2] != 0) return 0;
        if (m[2][1] != 0) return 0;
        if (m[2][2] != 1) return 0;
        return 1;
    }

    Matrix operator * (const Matrix &rhs) const {
        Matrix res;
        res.clear();
        for (int i = 1; i <= 2; i++) {
            for (int k = 1; k <= 2; k++)
                for (int j = 1; j <= 2; j++)
                    res.m[i][j] = (res.m[i][j] + 1ll * m[i][k] * rhs.m[k][j]) % P;
        }
        return res;
    }

    Matrix operator + (const Matrix &rhs) const {
        Matrix res;
        res.clear();
        for (int i = 1; i <= 2; i++) {
            for (int j = 1; j <= 2; j++)
                res.m[i][j] = (m[i][j] + rhs.m[i][j]) % P;
        }
        return res;
    }
} im, fr;

Matrix expow(Matrix a, int b) {
    Matrix res;
    res.clear(), res.init();
    for (; b; b >>= 1) {
        if (b & 1)
            res = res * a;
        a = a * a;
    }
    return res;
}

struct SegTree {
    struct node {
        Matrix mat, lzy;
    } tr[N << 2];

    #define ls(o) (o << 1)
    #define rs(o) (o << 1 | 1)

    void pushup(const int o) {
        tr[o].mat = tr[ls(o)].mat + tr[rs(o)].mat;
    }

    void pushdown(int o) {
        if (tr[o].lzy.empty()) return;
        tr[ls(o)] = {tr[ls(o)].mat * tr[o].lzy, tr[ls(o)].lzy * tr[o].lzy};
        tr[rs(o)] = {tr[rs(o)].mat * tr[o].lzy, tr[rs(o)].lzy * tr[o].lzy};
        tr[o].lzy.clear(), tr[o].lzy.init();
    }

    void build(int o, int l, int r) {
        tr[o].mat.clear();
        tr[o].lzy.clear(), tr[o].lzy.init();
        if (l == r) {
            tr[o].mat = fr * expow(im, a[l] - 1);
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(o), l, mid);
        build(rs(o), mid + 1, r);
        pushup(o);
    }

    void modify(int o, int l, int r, int ql, int qr, Matrix x) {
        if (ql <= l && r <= qr) {
            tr[o] = {tr[o].mat * x, tr[o].lzy * x};
            return;
        }
        pushdown(o);
        int mid = (l + r) >> 1;
        if (ql <= mid)
            modify(ls(o), l, mid, ql, qr, x);
        if (qr > mid)
            modify(rs(o), mid + 1, r, ql, qr, x);
        pushup(o);
    }

    Matrix query(int o, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return tr[o].mat;
        pushdown(o);
        Matrix res;
        res.clear();
        int mid = (l + r) >> 1;
        if (ql <= mid)
            res = res + query(ls(o), l, mid, ql, qr);
        if (qr > mid)
            res = res + query(rs(o), mid + 1, r, ql, qr);
        return res;
    }
} seg;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    im.clear(), fr.clear();
    im.m[1][1] = 1, im.m[1][2] = 1, im.m[2][1] = 1, im.m[2][2] = 0;
    fr.m[1][1] = 1, fr.m[1][2] = 1, fr.m[2][1] = 0, fr.m[2][2] = 0;
    seg.build(1, 1, n);
    for (int i = 1, opt, l, r, x; i <= m; i++) {
        std::cin >> opt;
        if (opt == 1) {
            std::cin >> l >> r >> x;
            seg.modify(1, 1, n, l, r, expow(im, x));
        } else {
            std::cin >> l >> r;
            std::cout << (seg.query(1, 1, n, l, r).m[1][2] % P) << "\n";
        }
    }
    return 0;
}
