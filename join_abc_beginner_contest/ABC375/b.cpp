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

using pi = pair<int, int>;
long double dist(pi l, pi r)
{
    long long v = 0;
    v += (l.first - r.first) * (l.first - r.first);
    v += (l.second - r.second) * (l.second - r.second);
    dPrint(v);
    return sqrtl(((long double)v));
}

int main()
{
    int n;
    cin >> n;
    pi xy[n];
    rep(i, n)
    {
        cin >> xy[i].first >> xy[i].second;
    }

    pi cur = make_pair(0, 0);
    long double v = dist(cur, xy[0]);
    rep(i, n - 1)
    {
        v += dist(xy[i], xy[i + 1]);
    }
    v += dist(xy[n - 1], cur);

    cout << fixed << setprecision(12) << v << "\n";

    return 0;
}
