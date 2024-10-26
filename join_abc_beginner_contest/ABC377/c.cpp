#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define repR(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rep3R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define all(x) std::begin(x), std::end(x)
#define rAll(x) std::rbegin(x), std::rend(x)
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
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    string s[8];
    rep(i, 8)
    {
        cin >> s[i];
    }
    int r[8];
    int c[8];

    rep(i, 8)
    {
        r[i] = 0;
        c[i] = 0;
    }

    rep(i, 8)
    {
        int j = 0;
        for (auto &&ch : s[i])
        {
            if (ch == '#')
            {
                r[i]++;
                c[j]++;
            }
            j++;
        }
    }

    int ans = 0;
    rep(i, 8)
    {
        rep(j, 8)
        {
            if (r[i] == 0 && c[j] == 0)
            {
                ans++;
            }
        }
    }

    mPrint(ans);

    return 0;
}
