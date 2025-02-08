#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define repR(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rep3R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define all(x) std::begin(x), std::end(x)
#define rAll(x) std::rbegin(x), std::rend(x)
#define contain(str, ch) (str.find(ch) != string::npos)
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
    int N;
    cin >> N;
    vector<int> q(N), r(N);
    rep(i, N)
    {
        cin >> q[i] >> r[i];
    }

    int Q;
    cin >> Q;
    vector<int> t(Q), d(Q);
    rep(i, Q)
    {
        cin >> t[i] >> d[i];
    }

    vector<int> ans(Q);
    rep(i, Q)
    {
        while (true)
        {
            int ex = d[i] % q[t[i - 1]];
            if (r[t[i - 1]] == ex)
            {
                ans[i] = d[i];
                break;
            }
            d[i]++;
        }
    }

    arrPrint(ans);

    return 0;
}
