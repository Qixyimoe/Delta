#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 7;

int n;
int a[N], cnt[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        cnt[a[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = std::max(ans, cnt[a[i]]);
    }
    std::cout << ans << "\n";
    return 0;
}
