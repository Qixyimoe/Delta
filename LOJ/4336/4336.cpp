#include <bits/stdc++.h>

#define int long long

constexpr int N = 1e6 + 7;

int n;
int a[N], s[N], lst[N];
int f[N];

void init() {
    memset(a, 0, sizeof(a));
    memset(s, 0, sizeof(s));
    memset(f, 0, sizeof(f));
    memset(lst, 0, sizeof(lst));
}

void solve() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 2; i <= n; i++) {
        s[i] = (a[i] == a[i - 1] ? s[i - 1] + a[i] : s[i - 1]);
    }
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        if (lst[a[i]])
            f[i] = std::max(f[i], f[lst[a[i]] + 1] + a[i] + s[i] - s[lst[a[i]] + 1]);
        lst[a[i]] = i;
    }
    std::cout << f[n] << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    int t;
    std::cin >> t;
    while (t--) {
        init();
        solve();
    }
    return 0;
}
