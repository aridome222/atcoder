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
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    rep(i, n)
    {
        a[i].resize(i + 1);
        rep(j, i + 1)
        {
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    int x = 0, y = 0;
    rep(i, n)
    {
        if (x >= i)
        {
            x = a[x][i];
        }
        else
        {
            x = a[i][x];
        }
    }

    mPrint(x + 1);

    return 0;
}
