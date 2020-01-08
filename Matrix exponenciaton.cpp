using namespace std;
#include <bits/stdc++.h>

typedef unsigned long long ull;


const int MN  = 2;
struct Matrix {
    int r, c;
    ull mat[MN][MN];

    Matrix (int _r, int _c) : r (_r), c (_c) {
        memset (mat, 0, sizeof mat);
    }

    ull x[MN][MN];
    Matrix & operator *= (const Matrix &o) {
        memset (x, 0, sizeof x);
        for (int i = 0; i < r; ++i)
            for (int k = 0; k < c; ++k)
                if (mat[i][k] != 0)
                    for (int j = 0; j < c; ++j)
                        x[i][j] += mat[i][k] * o.mat[k][j];
        memcpy (mat, x, sizeof (mat));
        return *this;
    }
};

void power (Matrix b, long long e, Matrix &res) {
    memset (res.mat, 0, sizeof res.mat);
    for (int i = 0; i < b.r; ++i)
        res.mat[i][i] = 1;

    while (e > 0) {
        if (e & 1)
            res *= b;
        b *= b;
        e >>= 1;
    }
}

void solve() {
    ull p, q, n;
    scanf ("%llu%llu%llu", &p, &q, &n);
    if (n == 0) {
        printf ("2\n");
        return;
    }
    Matrix mat (2, 2);
    mat.mat[0][0] = p;
    mat.mat[0][1] = -q;
    mat.mat[1][0] = 1;
    mat.mat[1][1] = 0;

    Matrix ans (2, 2);
    power (mat, n - 1, ans);

    printf ("%llu\n", ans.mat[0][0] * p + ans.mat[0][1] * 2);
}

int main() {
#ifdef LOCAL
    freopen ("f.txt", "r", stdin);
    // freopen("g.txt", "w", stdout);
#endif

    int tc;
    scanf ("%d", &tc);
    for (int i = 0; i < tc; ++i) {
        printf ("Case %d: ", i + 1);
        solve();
    }
    return 0;
}
