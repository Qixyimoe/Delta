#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    auto check = [&](int l, int r) -> bool {
        for (int i = l; i <= r; i++) {
            if (!a[i])
                return 1;
        }
        return 0;
    };
    if (check(n - 1, n) && check(1, n - 2)) {
        std::cout << "3\n";
        std::cout << n - 1 << " " << n << "\n";
        std::cout << "1 " << n - 2 << "\n";
        std::cout << "1 2\n";
    } else if (check(n - 1, n) && !check(1, n - 2)) {
        std::cout << "2\n";
        std::cout << n - 1 << " " << n << "\n";
        std::cout << "1 " << n - 1 << "\n";
    } else if (!check(n - 1, n) && check(1, n - 2)) {
        std::cout << "2\n";
        std::cout << "1 " << n - 2 << "\n";
        std::cout << "1 3\n";
    } else {
        std::cout << "1\n";
        std::cout << "1 " << n << "\n";
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
