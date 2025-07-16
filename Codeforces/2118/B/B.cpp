#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::cout << (n << 1) - 2 << "\n";
    for (int i = 1; i <= n; i++) {
        if (i > 1)
            std::cout << i << " 1 " << i << "\n";
        if (n > i)
            std::cout << i << " " << i + 1 << " " << n << "\n";
    }
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
