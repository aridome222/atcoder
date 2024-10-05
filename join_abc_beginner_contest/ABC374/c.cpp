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
    int n;
    cin >> n;
    vector<int> k(n);
    rep(i, n)
    {
        cin >> k[i];
    }

    long long ans = 1LL << 60;

    rep(i, 1 << n)
    {
        if (i == 0)
        {
            continue;
        }

        long long sum_a = 0;
        long long sum_b = 0;
        rep(j, n)
        {
            if (i & (1 << j))
            {
                sum_a += k[j];
            }
            else
            {
                sum_b += k[j];
            }
        }

        long long sum = max(sum_a, sum_b);

        ans = min(ans, sum);
    }

    mPrint(ans);

    return 0;
}
