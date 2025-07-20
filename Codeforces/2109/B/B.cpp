#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, a, b;
    std::cin >> n >> m >> a >> b;
    int ans1 = std::ceil(std::log2(m)) + std::ceil(std::log2(std::min(n - a + 1, a))),
        ans2 = std::ceil(std::log2(n)) + std::ceil(std::log2(std::min(m - b + 1, b)));
    std::cout << std::min(ans1, ans2) + 1 << "\n";
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
