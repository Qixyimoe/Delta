#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e6 + 7;

int n, m, l, v;
int _l, _r, _l1, _r1, _l2, _r2;
int ans1, ans2;
int p[N];

struct node {
    int d, v, a;    // D.V.A 爱你哦
} a[N];

struct elem {
    int l, r;
} b[N];

int check(int i, int p) {
    if (a[i].d > p)
        return -1e9;
    return 2 * a[i].a * (p - a[i].d) + a[i].v * a[i].v;
}

bool cmp(const elem &x, const elem &y) {
    return x.r < y.r;
}

void solve() {
    std::cin >> n >> m >> l >> v;
    ans1 = ans2 = 0;
    for (int i = 1, _d, _v, _a; i <= n; i++) {
        std::cin >> _d >> _v >> _a;
        a[i] = {_d, _v, _a};
    }
    for (int i = 1; i <= m; i++)
        std::cin >> p[i];
    for (int i = 1; i <= n; i++) {
        if (a[i].a >= 0) {
            _l = 1, _r = m + 1;
            while (_l < _r) {
                int mid = (_l + _r) >> 1;
                if (check(i, p[mid]) > v * v)
                    _r = mid;
                else
                    _l = mid + 1;
            }
            if (_l != m + 1) {
                b[++ans1] = {_l, m};
            }
            continue;
        }
        _l1 = 0, _r1 = m;
        while (_l1 < _r1) {
            int mid = (_l1 + _r1 + 1) >> 1;
            if (2ll * p[mid] * a[i].a >= 2ll * a[i].d * a[i].a - a[i].v * a[i].v)
                _l1 = mid;
            else
                _r1 = mid - 1;
        }
        if (!_l1)
            continue;
        _l2 = 1, _r2 = m + 1;
        while (_l2 < _r2) {
            int mid = (_l2 + _r2) >> 1;
            if (p[mid] < a[i].d)
                _l2 = mid + 1;
            else
                _r2 = mid;
        }
        if (_l2 == m + 1)
            continue;
        _l = _l2 - 1, _r = _l1;
        while (_l < _r) {
            int mid = (_l + _r + 1) >> 1;
            if (check(i, p[mid]) > v * v)
                _l = mid;
            else
                _r = mid - 1;
        }
        if (_l == _l2 - 1)
            continue;
        b[++ans1] = {_l2, _l};
    }
    std::cout << ans1 << " ";
    _r = 0;
    std::sort(b + 1, b + ans1 + 1, cmp);
    for (int i = 1; i <= ans1; i++) {
        if (_r >= b[i].l)
            continue;
        ans2++, _r = b[i].r;
    }
    std::cout << m - ans2 << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
