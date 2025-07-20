#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    int y = (2 * a[1] - a[2]) / (n + 1),
        x = (a[2] - a[1] + y),
        flg = 1;
    if (y < 0 || x < 0) {
        std::cout << "NO\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        flg &= (a[i] == (x * i + y * (n - i + 1)));
    }
    std::cout << (flg ? "YES" : "NO") << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
