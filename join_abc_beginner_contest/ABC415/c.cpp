#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define repR(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rep3R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define all(x) std::begin(x), std::end(x)
#define rAll(x) std::rbegin(x), std::rend(x)
#define contain(str, ch) (str.find(ch) != string::npos)
#define mPrint(msg) cout << msg << endl;
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
#define dump(x) cout << #x << " = " << (x) << endl;
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
template <class T>
bool isOK(const vector<T> &a, size_t index, T key)
{
    if (a[index] >= key)
        return true;
    else
        return false;
}
template <class T>
int binary_search(const vector<T> &a, T key)
{
    size_t left = 0;
    size_t right = a.size();

    while (right - left > 1)
    {
        size_t mid = left + (right - left) / 2;

        if (isOK(a, mid, key))
            right = mid;
        else
            left = mid;
    }

    return right;
}

// maskはどの薬品を入れたかを表す整数（13なら2進数で1101で、薬品1,3,4が混ざった状態を表す）
// maskという変数名なのは、プログラミングの世界ではビットごとに意味を持たせて管理する整数のことを、ビットマスクと呼ぶから。
bool dfs(int mask, int n, const string &s, vector<bool> &visited)
{
    // 状態2^n -1、つまり全ての薬品を混ぜることができた時、処理を終了する
    // (1 << n - 1)としないように気をつける
    if (mask == (1 << n) - 1)
        return true;

    // すでに調べた状態はスキップ
    if (visited[mask])
        return false;

    visited[mask] = true;

    // 薬品1から順に入れてない薬品があれば入れる
    for (int i = 0; i < n; i++)
    {
        // 薬品iを入れているかどうかを判定
        // && と & の区別をする. & は論理演算子.
        if (!(mask & (1 << i)))
        {
            int next = mask | (1 << i);
            // もし、先ほど入れた薬品を入れて危険な状態になるならば、その薬品をスキップする
            // sは文字列であるため、-1にする。
            if (s[next - 1] == '1')
                continue;
            // 遷移先で全ての薬品を混ぜ合わせることができれば、trueを返す
            if (dfs(next, n, s, visited))
                return true;
        }
    }

    // どの状態でも、つまり、どの薬品の入れ方をしても全ての薬品を混ぜ合わせることができない(危険な状態になる)場合、falseを返す
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // t個のテストケース
    int t;
    cin >> t;
    // dump(t);
    rep(i, t)
    {
        // dump(i);
        // n種類の薬品
        int n;
        cin >> n;
        // 0,1からなる長さ2^n -1の文字列S(状態13なら1101. 薬品1,3,4が混ざった状態を表現.)
        string s;
        cin >> s;

        // 1種類以上の薬品が混ざった状態 i（n種類の薬品がある時、2^n -1の状態数を持つ. 1 <= i <= 2^n -1）
        vector<bool> visited(1 << n, false);

        bool ok = true;
        // 状態0から始める（つまり、何も薬品を入れていない状態から始める）
        ok = dfs(0, n, s, visited);
        if (ok)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
