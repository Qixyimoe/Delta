#include <bits/stdc++.h>

#define int __int128

constexpr int N = 1e5 + 7;

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

int n;
int a[N], b[N], c[N], p[N], t[N];
int fa[N], vis[N], stc[N];

std::vector<int> G[N];

void dfs(int u, int pa) {
    fa[u] = pa;
    for (auto v : G[u]) {
        if (v != pa)
            dfs(v, u);
    }
}

int calc(int u, int l, int r) {
    if (c[u] >= 0)
        return (r - l + 1) * b[u] + (r - l + 1) * (l + r) / 2 * c[u];
    int o = (1 - b[u]) / c[u];
    if (o < l)
        return r - l + 1;
    if (o > r)
        return (r - l + 1) * b[u] + (r - l + 1) * (l + r) / 2 * c[u];
    return (o - l + 1) * b[u] + (o - l + 1) * (l + o) / 2 * c[u] + r - o;
}

bool check(int r) {
    for (int i = 1; i <= n; i++) {
        if (calc(i, 1, r) < a[i])
            return 0;
        int _l = 1, _r = n;
        while (_l < _r) {
            int mid = (_l + _r + 1) >> 1;
            if (calc(i, mid, r) >= a[i])
                _l = mid;
            else
                _r = mid - 1;
        }
        p[i] = i, t[i] = _l, vis[i] = 0;
    }
    std::sort(p + 1, p + n + 1, [](int x, int y) { return t[x] < t[y]; });
    for (int i = 1, cnt = 0; i <= n; i++) {
        int u = p[i], top = 0;
        for (; !vis[u]; u = fa[u])
            vis[stc[++top] = u] = 1;
        while (top) {
            if (t[stc[top--]] < (++cnt))
                return 0;
        }
    }
    return 1;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    io.read(n);
    for (int i = 1; i <= n; i++) {
        io.read(a[i]), io.read(b[i]), io.read(c[i]);
    }
    for (int i = 1, u, v; i < n; i++) {
        io.read(u), io.read(v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    vis[0] = 1;
    int l = n, r = 1e9;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    io.write(l, '\n');
    return 0;
}
