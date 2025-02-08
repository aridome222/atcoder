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
    // 入力
    string s, t;
    cin >> s >> t;

    // 処理
    vector<string> x; // イテレーション毎にclearする必要あり
    vector<string> ans;
    while (s != t)
    {
        rep(i, s.size())
        {
            if (s[i] == t[i])
            {
                continue;
            }
            // 文字列sの各一文字ずつをtに書き換えた文字列を要素としてもつ配列xを用意する
            string tmp = s;
            tmp[i] = t[i];
            x.push_back(tmp);
        }

        sort(all(x));
        // アルファベット順にソートした配列xの先頭を取り出す
        string front = x.front();
        // 次のイテレーションのために空にする
        x.clear();
        s = front;
        ans.push_back(s);
    }

    // 出力
    mPrint(ans.size());
    rep(i, ans.size())
    {
        mPrint(ans[i]);
    }

    return 0;
}
