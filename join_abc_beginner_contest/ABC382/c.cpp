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
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> ai(n);
    rep(i, n)
    {
        cin >> ai[i].first;
        ai[i].second = i+1;
    }
    sort(all(ai));

    rep(i, m)
    {
        int b;
        cin >> b;

        auto it = lower_bound(all(ai), make_pair(b, 0));
         // itはbより大きい値の最初の位置を指しているので、前の要素を選べばb以下の最大の値
        if (it == ai.end()) {
            // b以下の値がなければ -1 を出力
            cout << -1 << endl;
        } else {
            // itの1つ前の要素がb以下の最大の値なので、そのpairのsecondを出力
            cout << prev(it)->second << endl;
        }
    }
    return 0;
}
