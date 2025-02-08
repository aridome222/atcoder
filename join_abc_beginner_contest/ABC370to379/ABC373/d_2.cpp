#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define repR(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rep3R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define all(x) std::begin(x), std::end(x)
#define mPrint(msg) cout << msg << endl;
#define dPrint(msg) cout << "-----\n" \
                         << msg << "\n-----\n";
#define arrPrint(arr)                \
    {                                \
        bool first = true;           \
        for (const auto &elem : arr) \
        {                            \
            if (!first)              \
                cout << " ";         \
            cout << elem;            \
            first = false;           \
        }                            \
        cout << endl;                \
    }

int main()
{
    int n, m; // nは頂点、mは辺
    cin >> n >> m;

    vector<int> u(m), v(m), w(m);
    rep(i, m)
    {
        cin >> u[i] >> v[i] >> w[i];
    }

    vector<int> x(n);
    x[0] = 0;
    x[1] = w[0];

    for (int i = 2; i < m - 2; i++)
    {
        x[i] = x[i - 1] - w[i];
    }

    arrPrint(x);

    return 0;
}
