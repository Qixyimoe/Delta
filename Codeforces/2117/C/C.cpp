#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::set<int> s, g;
    int ans = 0;
    for (int i = 1, x; i <= n; i++) {
        std::cin >> x;
        g.insert(x);
        s.insert(x);
        if (g.size() == s.size()) {
            ans++;
            s.clear();
        }
    }
    std::cout << ans << "\n";
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
