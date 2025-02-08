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
#if 0
    // 配列の要素数を指定しない（動的）にする場合、s[i]にアクセスできない。
    // そのため、s.push_back(入れたい値)のようにする必要がある
    // 動的配列を用いる場合は、ループ変数とは添え字が異なる場合があるため、配列のどこに今アクセスしているのか注意する
    vector<string> s;
    int ans = 0;
    for (int i = 1; i <= 12; i++)
    {
        string t;
        cin >> t;
        // cin >> s[i];はできない
        s.push_back(t);
        if (s[i - 1].size() == i)
        {
            ans++;
        }
    }
#else
    // 配列の要素数を指定する場合、s[i]にアクセスできる
    // vector<string> s[13];のように、[]と()の違いに気を付ける
    // []の場合だと、vector<string>型の配列sになってしまう
    vector<string> s(13);
    int ans = 0;
    for (int i = 1; i <= 12; i++)
    {
        cin >> s[i];
        if (s[i].size() == i)
        {
            ans++;
        }
    }
#endif

    mPrint(ans);

    return 0;
}
