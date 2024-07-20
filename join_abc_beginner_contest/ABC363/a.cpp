#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define repR(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rep3R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define all(x) std::begin(x), std::end(x)
#define mprint(msg) cout << msg << endl;
#define repE(arr)                    \
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
    int r;
    cin >> r;

    if (1 <= r && r <= 99)
    {
        mprint(100 - r);
    }
    else if (100 <= r && r <= 199)
    {
        mprint(200 - r);
    }
    else if (200 <= r && r <= 299)
    {
        mprint(300 - r);
    }

    return 0;
}
