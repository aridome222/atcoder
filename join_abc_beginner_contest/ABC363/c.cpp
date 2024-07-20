#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define repR(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rep3R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define all(x) std::begin(x), std::end(x)
#define mprint(msg) cout << msg << endl;
#define dprint(msg) cout << "-----\n" \
                         << msg << "\n-----\n";
#define repE(arr)                    \
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int numPermutation = 0; // 重複なしで並び替えてできる文字列の数を保持
    vector<string> permulations;
    sort(all(s));
    do
    {
        permulations.push_back(s);
        numPermutation++;
    } while (next_permutation(all(s)));

    int ans = numPermutation;
    // 重複なしで並び替えてできる文字列の数だけ回す
    rep(i, numPermutation)
    {
        // 長さnの文字列に対して、長さkの回文が存在するか調べる
        // n-k+1個の部分文字列のうち、1個でも部分文字列が存在すれば、回文と判定する
        rep(j, n - k + 1)
        {
            bool ispalindrome = false; // 回文であるかどうかのフラグ
            // 部分文字列の両端から内側に向かって文字を比較し、全て一致すれば回文と判定する
            rep(p, k / 2)
            {
                // 文字が一致しない場合、ループから抜ける
                if (permulations[i][j + p] != permulations[i][(k + j - 1) - p])
                {
                    break;
                }
                // 文字が全て一致した場合、回文と判定
                if (p + 1 == k / 2)
                {
                    ispalindrome = true;
                }
            }
            // 回文の場合
            if (ispalindrome == true)
            {
                ans--;
                break; // 回文である部分文字列が1つ見つかったため、ループを抜ける
            }
        }
    }

    mprint(ans);

    return 0;
}
