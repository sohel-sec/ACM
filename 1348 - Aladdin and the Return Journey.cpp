#include <bits/stdc++.h>
#define debug(...)
#include <complex.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;

vector<int>order;
int n, l;
vector<vector<int>> g;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;
void dfs(int v, int p)
{
    order.push_back(v);
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : g[v]) {
        if (u != p)
            dfs(u, v);
    }
    order.push_back(v);

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n) + 1);
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}



template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;

  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }

  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }

  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};


void test_case() {
    scanf("%d", &n);
    vl a(n);
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
    }
    g.assign(n , vector<int>{ });
    for(int i = 0 ; i + 1 < n; i++){
        int from , to;
        scanf("%d%d", &from , &to);
        g[from].push_back(to); g[to].push_back(from);
    }

    order.clear();
    preprocess(0);
    vector<int>first(n , -1) , last(n , -1);
    for(int i = 0; i < order.size(); i++){
        int c = order[i];
        if(first[c] == -1){
            first[c] = i;
        }
        last[c] = i;
    }
    fenwick<long long>fen(order.size() + 1);
    for(int i = 0; i < n; i++){
        fen.modify(first[i] , a[i]);
        fen.modify(last[i] , -a[i]);
    }
    int q;
    scanf("%d", &q);
    while(q--){
        int cmd ;
        scanf("%d" , &cmd);
        if(cmd == 0){
            int from , to;
            scanf("%d%d", &from , &to);
            int parent = lca(from , to);
            long long answer = fen.get(first[from]) + fen.get(first[to]) - 2 * fen.get(first[parent]) + a[parent];
            printf("%lld\n", answer);
        }
        else{
            int node ;
            long long values;
            scanf("%d %lld", &node , &values);
            long long diff = values - a[node];
            fen.modify(first[node] , diff);
            fen.modify(last[node] , -diff);
            a[node] = values;
        }
    }

}

int main() {
    #ifdef LOCAL
       // freopen("input.txt", "r",  stdin);
     //  freopen("output.txt", "w", stdout);
    #endif

    int T;
    scanf("%d", &T);
    for(int t = 1; t<=T; t++) {
        printf("Case %d:\n", t);
        test_case();
    }
    return 0;
}








