#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 7;

int n, m;
i64 a[N];

template <typename T>
struct SegTree {
	struct node {
		T val, lzy;
	} tr[N << 2];

	#define ls(o) (o << 1)
	#define rs(o) (o << 1 | 1)

	void pushup(const T o) {
		tr[o].val = tr[ls(o)].val + tr[rs(o)].val;
	}

	void maketag(T o, T l, T v) {
		tr[o].lzy += v;
		tr[o].val += l * v;
	}

	void pushdown(T o, T l, T r) {
		T mid = (l + r) >> 1;
		maketag(ls(o), mid - l + 1, tr[o].lzy);
		maketag(rs(o), r - mid, tr[o].lzy);
		tr[o].lzy = 0;
	}

	void build(T o, T l, T r) {
		if (l == r) { tr[o].val = a[l]; return; }
		T mid = (l + r) >> 1;
		build(ls(o), l, mid);
		build(rs(o), mid + 1, r);
		pushup(o);
	}

	void update(T o, T l, T r, T ql, T qr, T v) {
		if (ql <= l && r <= qr) { maketag(o, r - l + 1, v); return; }
		if (!((l > qr) || (r < ql))) {
			T mid = (l + r) >> 1;
			pushdown(o, l, r);
			update(ls(o), l, mid, ql, qr, v);
			update(rs(o), mid + 1, r, ql, qr, v);
			pushup(o);
		}
	}

	T query(T o, T l, T r, T ql, T qr) {
		if (ql <= l && r <= qr) { return tr[o].val; }
		if (!((l > qr) || (r < ql))) {
			T mid = (l + r) >> 1;
			pushdown(o, l, r);
			return (query(ls(o), l, mid, ql, qr) + query(rs(o), mid + 1, r, ql, qr));
		}
		return 0;
	}
};

SegTree<i64> seg;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> m;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	seg.build(1, 1, n);
	for (int i = 1, opt, x, y; i <= m; i++) {
		i64 k;
		std::cin >> opt >> x >> y;
		if (opt == 1) { std::cin >> k; seg.update(1, 1, n, x, y, k); }
		else { std::cout << seg.query(1, 1, n, x, y) << "\n"; }
	}
	return 0;
}
