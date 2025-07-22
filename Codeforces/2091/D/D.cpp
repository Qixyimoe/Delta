#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 n, m, k;
    std::cin >> n >> m >> k;
    i64 l = 1, r = 1e10, ans = 0;
    auto calc = [&](i64 x) -> i64 {
        return n * (m - (i64) (m / x));
    };
    while (l <= r) {
        i64 mid = (l + r) / 2;
        if (calc(mid) >= k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    std::cout << ans - 1 << "\n";   // space
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
