#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(2 * n + 1), c(2 * n + 1);
    for (int i = 1, x; i <= n; i++) {
        std::cin >> x;
        a[x]++;
    }
    for (int i = 0; i <= n; i++) {
        c[a[i]]++, c[n - i + 1]--;
        if (!a[i]) break;
    }
    std::cout << c[0] << " ";
    for (int i = 1; i <= n; i++) {
        c[i] += c[i - 1];
        std::cout << c[i] << " ";
    }
    std::cout << "\n";
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
