#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e3 + 7;

int n, len, pos;
int l[N], r[N];
char s[N];

int dfs(int u) {
	s[++len] = '(';
	int v = 0;
	while (v < l[u] - 1 && ++pos <= n)
		v += dfs(pos);
	if (v > r[u] - 1 || v < l[u] - 1) {
		std::cout << "IMPOSSIBLE\n";
		exit(0);
	}
	s[++len] = ')';
	return v + 2;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n;
	for (int i = 1; i <= n; i++)
		std::cin >> l[i] >> r[i];
	while (++pos <= n)
		dfs(pos);
	for (int i = 1; i <= len; i++)
		std::cout << s[i];
	std::cout << "\n";
	return 0;
}
