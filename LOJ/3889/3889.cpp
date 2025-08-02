#include <bits/stdc++.h>

using i64 = long long;

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

constexpr int N = 3e3 + 7;
constexpr int inf = 1e9;

int n, m, k, d[N][N];
i64 ans, w[N];
bool vis[N];

std::vector<int> G[N];
std::set<std::pair<i64, i64>> os[N];

void solve(int s, int l) {
    std::queue<int> q;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
        d[l][i] = inf;
    d[l][s] = 0;
    q.push(s);
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto v : G[u]) {
            if (d[l][v] > d[l][u] + 1) {
                d[l][v] = d[l][u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    // freopen("holiday.in", "r", stdin);
    // freopen("holiday.out", "w", stdout);

    io.read(n), io.read(m), io.read(k);
    for (int i = 2; i <= n; i++) {
        io.read(w[i]);
    }
    for (int i = 1, u, v; i <= m; i++) {
        io.read(u), io.read(v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        solve(i, i);
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            if (j == i) continue;
            if (d[i][j] <= k + 1 && d[1][j] <= k + 1)
                os[i].insert({w[j], j});
            if (os[i].size() > 3)
                os[i].erase(os[i].begin());
        }
    }
    for (int b = 2; b <= n; b++) {
        for (int c = 2; c <= n; c++) {
            if (d[b][c] > k + 1 || b == c)
                continue;
            for (auto a : os[b]) {
                if (a.second == b || a.second == c)
                    continue;
                for (auto d : os[c]) {
                    if (d.second == b || d.second == c || d.second == a.second)
                        continue;
                    ans = std::max(ans, w[b] + w[c] + w[a.second] + w[d.second]);
                }
            }
        }
    }
    io.write(ans, '\n');
    return 0;
}
