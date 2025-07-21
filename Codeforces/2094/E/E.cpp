#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    auto exc = [&](int x) -> std::string {
        std::string s = "";
        while (x) {
            s = std::to_string(x % 2) + s;
            x >>= 1;
        }
        while (s.size() < 31)
            s = '0' + s;
        return s;
    };
    
    std::vector<std::vector<int>> cnt(50, std::vector<int>(2));
    auto cot = [&](std::string s) -> void {
        for (auto i = 0; i < s.size(); i++) {
            int p = (s[i] == '0') ? 0 : 1;
            cnt[s.size() - i][p]++;
        }
    };
    
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        cot(exc(a[i]));
    }
    
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        i64 res = 0;
        std::string s = exc(a[i]);
        while (s.size() < 31) {
            s = '0' + s;
        }
        for (auto j = 0; j < s.size(); j++) {
            int p = (s[j] - '0') ? 0 : 1;
            res += (cnt[s.size() - j][p] * std::pow(2, 31 - j - 1));
        }
        ans = std::max(ans, res);
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
