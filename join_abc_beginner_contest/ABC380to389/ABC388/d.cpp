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
// 二分探索
/*
vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};
bool isOK(int index, int key) {
    if (a[index] >= key) return true;
    else return false;
}
int binary_search(int key) {
    long long left = -1;
    long long right = (int)a.size();

    while (right - left > 1) {
        long long mid = left + (right - left) / 2;

        if (isOK(mid, key)) right = mid;
        else left = mid;
    }

    return right;
}
*/

int main()
{
    int N;
    cin >> N;

    vector<int> a(N);
    rep(i, N)
    {
        cin >> a[i];
    }

    vector<int> pay_num(N, 0);
    int cnt = 0;
    rep(i, N)
    {
        // 次以降に渡す石を全て持ってなければ
        if (a[i] < N - (i + 1))
        {
            // 前のやつから貰ったやつで払えるか確認する
            // 払えるなら何もしない。
            // それでも払えない場合、負債者リストに入り、後の人の石を-1する
            // ただし、払える分だけ払ってもらう
            if (a[i] + (i - cnt) < N - (i + 1))
            {
                int res = N - (i + 1) - (a[i] + (i - cnt));
                pay_num[i + res + 1] += 1;
                cnt++;
            }
        }
    }

    int pay = 0;
    rep(i, N)
    {
        pay += pay_num[i];
        // 最終的な石の増減値を足す
        a[i] += (i - (N - (i + 1))) - pay;
        a[i] = max(0, a[i]);
        dump((i - (N - (i + 1))));
        dump(pay);
        dump(a[i]);
    }

    arrPrint(a);

    return 0;
}
