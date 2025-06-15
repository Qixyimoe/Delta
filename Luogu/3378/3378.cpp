#include <bits/stdc++.h>

using i64 = long long;

int n;

std::priority_queue<int, std::vector<int>, std::greater<int>> q;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n;
	for (int i = 1, op, x; i <= n; i++) {
		std::cin >> op;
		if (op == 1) { std::cin >> x; q.push(x); }
		if (op == 2) { std::cout << q.top() << "\n"; }
		if (op == 3) { q.pop(); }
	}
	return 0;
}
