#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2.5e5 + 7;
constexpr int P = 998244353;

// retarded retarded retarded

// #define DEBUG 1  // 调试开关
struct IO {
#define MAXSIZE (1 << 20)
#define isdigit(x) (x >= '0' && x <= '9')
    char buf[MAXSIZE], *p1, *p2;
    char pbuf[MAXSIZE], *pp;
#if DEBUG
#else
    IO() : p1(buf), p2(buf), pp(pbuf) {}

    ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
#endif
    char gc() {
#if DEBUG // 调试，可显示字符
        return getchar();
#endif
        if (p1 == p2)
            p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
        return p1 == p2 ? ' ' : *p1++;
    }

    bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }

    template <class T>
    void read(T &x) {
        double tmp = 1;
        bool sign = false;
        x = 0;
        char ch = gc();
        for (; !isdigit(ch); ch = gc())
            if (ch == '-')
                sign = 1;
        for (; isdigit(ch); ch = gc())
            x = x * 10 + (ch - '0');
        if (ch == '.')
            for (ch = gc(); isdigit(ch); ch = gc())
                tmp /= 10.0, x += tmp * (ch - '0');
        if (sign)
            x = -x;
    }

    void read(char *s) {
        char ch = gc();
        for (; blank(ch); ch = gc())
            ;
        for (; !blank(ch); ch = gc())
            *s++ = ch;
        *s = 0;
    }

    void read(char &c) {
        for (c = gc(); blank(c); c = gc())
            ;
    }

    void push(const char &c) {
#if DEBUG // 调试，可显示字符
        putchar(c);
#else
        if (pp - pbuf == MAXSIZE)
            fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
        *pp++ = c;
#endif
    }

    template <class T>
    void write(T x) {
        if (x < 0)
            x = -x, push('-'); // 负数输出
        static T sta[35];
        T top = 0;
        do {
            sta[top++] = x % 10, x /= 10;
        } while (x);
        while (top)
            push(sta[--top] + '0');
    }

    template <class T>
    void write(T x, char lastChar) {
        write(x), push(lastChar);
    }
} io;

int n, m;
int a[N], b[N], c[N];

struct Matrix {
    int a[4][4];

    Matrix(int v = 1) {
        memset(a, 0, sizeof(a));
        if (v == 1) {
            for (int i = 0; i < 4; i++)
                a[i][i] = 1;
        }
    }

    Matrix operator * (const Matrix &rhs) const {
        Matrix res(0);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++) {
                    res.a[i][j] += (1ll * a[i][k] * rhs.a[k][j]) % P;
                    res.a[i][j] %= P;
                }
        }
        return res;
    }
} t1, t2, t3, t4, t5, t6;

struct node {
    int v[4];

    node() { memset(v, 0, sizeof(v)); }

    node(int a, int b, int c) { v[0] = a; v[1] = b; v[2] = c; v[3] = 1; }

    node operator + (const node &rhs) const {
        node res;
        res.v[0] = (v[0] + rhs.v[0]) % P;
        res.v[1] = (v[1] + rhs.v[1]) % P;
        res.v[2] = (v[2] + rhs.v[2]) % P;
        res.v[3] = (v[3] + rhs.v[3]);
        return res;
    }

    node operator * (const Matrix &rhs) const {
        node res;
        for (int j = 0; j < 4; j++) {
            for (int i = 0; i < 4; i++) {
                res.v[j] += (1ll * v[i] * rhs.a[i][j]) % P;
                res.v[j] %= P;
            }
        }
        return res;
    }
};

struct SegTree {
    node tr[N << 2];
    Matrix tg[N << 2];

    #define ls(o) (o << 1)
    #define rs(o) (o << 1 | 1)

    void pushup(const int o) {
        tr[o] = tr[ls(o)] + tr[rs(o)];
    }

    void build(int o, int l, int r) {
        if (l == r) {
            tr[o] = node(a[l], b[l], c[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(o), l, mid);
        build(rs(o), mid + 1, r);
        pushup(o);
    }

    void maketag(int o, Matrix t) {
        tg[o] = tg[o] * t;
        tr[o] = tr[o] * t;
    }

    void pushdown(int o) {
        maketag(ls(o), tg[o]);
        maketag(rs(o), tg[o]);
        tg[o] = Matrix();
    }

    void update(int o, int l, int r, int ql, int qr, Matrix t) {
        if (ql <= l && r <= qr) {
            maketag(o, t);
            return;
        }
        pushdown(o);
        int mid = (l + r) >> 1;
        if (ql <= mid)
            update(ls(o), l, mid, ql, qr, t);
        if (qr > mid)
            update(rs(o), mid + 1, r, ql, qr, t);
        pushup(o);
    }

    node query(int o, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return tr[o];
        pushdown(o);
        int mid = (l + r) >> 1;
        if (qr <= mid)
            return query(ls(o), l, mid, ql, qr);
        if (ql > mid)
            return query(rs(o), mid + 1, r, ql, qr);
        return query(ls(o), l, mid, ql, qr) + query(rs(o), mid + 1, r, ql, qr);
    }
} seg;

void init() {
    t1.a[1][0] = t2.a[2][1] = t3.a[0][2] = 1;
    t6.a[2][2] = 0;
}

int main() {
    init();
    io.read(n);
    for (int i = 1; i <= n; i++) {
        io.read(a[i]), io.read(b[i]), io.read(c[i]);
    }
    seg.build(1, 1, n);
    io.read(m);
    for (int i = 1, opt, l, r, v; i <= m; i++) {
        io.read(opt), io.read(l), io.read(r);
        if (opt == 1) {
            seg.update(1, 1, n, l, r, t1);
        } else if (opt == 2) {
            seg.update(1, 1, n, l, r, t2);
        } else if (opt == 3) {
            seg.update(1, 1, n, l, r, t3);
        } else if (opt == 7) {
            node res = seg.query(1, 1, n, l, r);
            io.write(res.v[0], ' ');
            io.write(res.v[1], ' ');
            io.write(res.v[2], '\n');
        } else {
            io.read(v);
            if (opt == 4) {
                t4.a[3][0] = v;
                seg.update(1, 1, n, l, r, t4);
            } else if (opt == 5) {
                t5.a[1][1] = v;
                seg.update(1, 1, n, l, r, t5);
            } else if (opt == 6) {
                t6.a[3][2] = v;
                seg.update(1, 1, n, l, r, t6);
            }
        }
    }
    return 0;
}
