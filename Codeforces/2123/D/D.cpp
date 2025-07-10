#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    s = '$' + s;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1')
                cnt++;
    }
    if (cnt <= k || 2 * k > n) { std::cout << "Alice\n"; }
    else { std::cout << "Bob\n"; }
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
