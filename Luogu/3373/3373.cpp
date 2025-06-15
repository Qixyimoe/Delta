#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 7;

int n, m, q;
int a[N];

template <typename T>
struct SegTree {
	struct node {
		T val, add, mul;
	} tr[N << 2];

	#define P m
	#define ls(o) (o << 1)
	#define rs(o) (o << 1 | 1)

	void maketag(T o, T l, T r, T v, T t) {
		if (t == 1) {
			(tr[o].add *= v) %= P;
			(tr[o].mul *= v) %= P;
			(tr[o].val *= v) %= P;
		} else {
			(tr[o].add += v) %= P;
			(tr[o].val += (r - l + 1) * v) %= P;
		}
	}

	void pushup(const T o) {
		tr[o].val = (tr[ls(o)].val + tr[rs(o)].val) % P;
	}

	void pushdown(T o, T l, T r) {
		T mid = (l + r) >> 1;
		maketag(ls(o), l, mid, tr[o].mul, 1);
		maketag(ls(o), l, mid, tr[o].add, 2);
		maketag(rs(o), mid + 1, r, tr[o].mul, 1);
		maketag(rs(o), mid + 1, r, tr[o].add, 2);
		tr[o].mul = 1, tr[o].add = 0;
	}

	void build(T o, T l, T r) {
		if (l == r) { tr[o].val = a[l]; return; }
		T mid = (l + r) >> 1;
		build(ls(o), l, mid);
		build(rs(o), mid + 1, r);
		pushup(o);
		tr[o].mul = 1;
	}

	void update(T o, T l, T r, T ql, T qr, T v, T t) {
		if (t == 1) {
			if (ql <= l && r <= qr) { maketag(o, l, r, v, 1); }
			else if (!((l > qr) || (r < ql))) {
				T mid = (l + r) >> 1;
				pushdown(o, l, r);
				update(ls(o), l, mid, ql, qr, v, t);
				update(rs(o), mid + 1, r, ql, qr, v, t);
				pushup(o);
			}
		} else {
			if (ql <= l && r <= qr) { maketag(o, l, r, v, 2); }
			else if (!((l > qr) || (r < ql))) {
				T mid = (l + r) >> 1;
				pushdown(o, l, r);
				update(ls(o), l, mid, ql, qr, v, t);
				update(rs(o), mid + 1, r, ql, qr, v, t);
				pushup(o);
			}
		}
	}

	T query(T o, T l, T r, T ql, T qr) {
		if (ql <= l && r <= qr) { return tr[o].val; }
		else if (!((l > qr) || (r < ql))) {
			T mid = (l + r) >> 1;
			pushdown(o, l, r);
			return (query(ls(o), l, mid, ql, qr) + query(rs(o), mid + 1, r, ql, qr)) % P;
		}
		return 0;
	}
};

SegTree<i64> seg;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> q >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	seg.build(1, 1, n);
	for (int i = 1, opt, x, y, k; i <= q; i++) {
		std::cin >> opt >> x >> y;
		if (opt == 1) {
			std::cin >> k;
			seg.update(1, 1, n, x, y, k, 1);
		} else if (opt == 2) {
			std::cin >> k;
			seg.update(1, 1, n, x, y, k, 2);
		} else {
			std::cout << seg.query(1, 1, n, x, y) << "\n";
		}
	}
	return 0;
}
