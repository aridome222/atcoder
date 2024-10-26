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
    long long int n, k;
    cin >> n >> k;

    vector<long long int> p(n);
    rep(i, n)
    {
        cin >> p[i];
    }

    vector<long long int> t = p;
    sort(all(t));
    if (t == p)
    {
        arrPrint(p);
        return 0;
    }

    vector<long long int> ans = p;
    vector<long long int> map[n + 1];
    map[0] = p;
    long long int cnt = 1;
    rep(i, n)
    {
        vector<long long int> tmp = ans;
        rep(j, n)
        {
            ans[j] = tmp[tmp[j]];
        }
        map[i + 1] = ans;
        if (p == ans)
        {
            cnt = i + 1;
        }
    }

    vector<long long int> tmp = ans;
    sort(all(tmp));

    if (ans == tmp)
    {
        arrPrint(ans);
        return 0;
    }

    long long int ex = k % cnt;
    arrPrint(map[ex]);

    return 0;
}
