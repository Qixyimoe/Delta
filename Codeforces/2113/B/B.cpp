#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int w, h, a, b;
    std::cin >> w >> h >> a >> b;
    int xa, xb, ya, yb;
    std::cin >> xa >> ya >> xb >> yb;
    if (xa == xb)
        std::cout << (std::abs(yb - ya) % b ? "NO" : "YES") << "\n";
    else if (ya == yb)
        std::cout << (std::abs(xa - xb) % a ? "NO" : "YES") << "\n";
    else
        std::cout << ((std::abs(xa - xb) % a && std::abs(ya - yb) % b) ? "NO" : "YES") << "\n";
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
