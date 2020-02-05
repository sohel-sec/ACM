/*
    problem : lightoj : http://lightoj.com/volume_showproblem.php?problem=1063

*/


#include <bits/stdc++.h>
#define debug(...)
#include <complex.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

struct Edge {
    int to, next;
    Edge (int _to = 0, int _next = -1) :to (_to), next (_next) {}
};
const int N = 1e5;
Edge e[N * 2];
int head[N], tin[N], low[N], timer, tot ;
int n, m, ans;
bool vis[N] ;

void add_edge (int from, int to) {
    e[tot] = Edge (to, head[from]);
    head[from] = tot++;
    e[tot] = Edge (from, head[to]);
    head[to] = tot++;
}

void all_clear() {
    timer = tot = ans = 0;
    for (int i = 0; i< N; ++i) {
        tin[i] = low[i] = vis[i] = 0;
        head[i] = -1;
    }

}

void Dfs (int u, int par) {
    tin[u] = low[u] = ++timer;
    int bacca = 0;
    for (int i = head[u]; ~i; i = e[i].next) {
        int to = e[i].to;
        if (tin[to] == 0) {
            Dfs (to, u);
            low[u] = min (low[u], low[to]);
            bacca++;
            if (!vis[u] && ( (par==-1 && bacca > 1) || (par != -1 && tin[u] <= low[to]))) {
                vis[u] = 1;
                ans++;
            }
        } else
            low[u] = min (low[u], tin[to]);
    }

}

void test_case (int kase) {
    cout << "Case " << kase << ": ";


    cin >> n >> m;
    all_clear();
    for (int i = 0; i < m; ++i) {
        int from, to ;
        cin >> from >> to;
        add_edge (from, to);
    }
    Dfs (1, -1);
    cout<< ans << '\n';
}
int main() {
#ifdef LOCAL
    freopen ("input.txt", "r",  stdin);
//   freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio (false);
    cin.tie (0);
    int tt;
    cin >> tt;
    for (int t = 1; t<=tt; t++)
        test_case (t);
    return 0;
}











