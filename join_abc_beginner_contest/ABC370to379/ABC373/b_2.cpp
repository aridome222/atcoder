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
    unordered_map<char, int> x;
    for (int i = 0; i < s.size(); i++)
    {
        // x['A']にアクセスした段階でデフォルト値として0が入る
        // そのため、xの宣言時に初期化してなくても、範囲外アクセスエラーにならない
        x[s[i]] = i;
    }

    int ans = 0;
    for (char c = 'A'; c < 'Z'; c++)
    {
        ans += abs(x[c + 1] - x[c]); // AからZまで、差を昇順に取っていく
    }

    mPrint(ans);

    return 0;
}
