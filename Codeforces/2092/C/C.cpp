#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    i64 sum = 0;
    i64 s1 = 0, s2 = 0, mx = 0;
    for (int i = 1, x; i <= n; i++) {
        std::cin >> x;
        (x & 1) ? s1++ : s2++;
        sum += x;
        mx = std::max(mx, (i64) x);
    }
    std::cout << ((s1 && s2) ? sum - s1 + 1 : mx) << "\n";
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
