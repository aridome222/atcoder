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
    string s;
    cin >> s;

    // 配列の各要素を0で初期化
    // vector<int> x(26);と宣言すれば、{0}で初期化せずとも初期化してくれるから、こっちを使ったほうがいい
    int x[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
#if 0
        char c = s[i];
        // cがDの場合、c-'A'は3になる
        // 0番目がA、1番目がB、...に対応している
        if (x[c - 'A'] == 0) // 0だった時、つまり、今見ているアルファベットの位置をメモしていない時
        {
            x[c - 'A'] = i + 1; // 文字列の何番目にあったかを記録
        }
#endif
#if 1
        x[s[i] - 'A'] = i + 1; // 文字列の何番目にあったかを記録
#endif
    }

    int ans = 0;
    rep(i, 25)
    {
        ans += abs(x[i + 1] - x[i]); // AからZまで、差を昇順に取っていく
    }

    mPrint(ans);

    return 0;
}
