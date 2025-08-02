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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a, b;
    rep(i, n)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    // 2^32を超える場合があるので、long longにしておく
    ll ans = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if ((j + 1) - (i + 1) == a[i] + a[j])
    //         {
    //             ans++;
    //         }
    //     }
    // }

    // j - i = a[i] + a[j]の計算式を j - a[j] = i + a[i]に変換する
    // 左側はjだけ、右側はiだけの式にすることで、一方の式で取りうる値の範囲をO(n)で求められるようにする
    // あとは、それをmap使って、高速に探索する
    // unordered_map<int, int> map;
    // rep3(i, 1, n + 1)
    // {
    //     int key = i + a[i - 1];
    //     // 何回 i + a[i - 1]が出てくるか数える
    //     map[key]++;
    // }

    // rep3(j, 2, n + 1)
    // {
    //     int key = j - a[j - 1];
    //     ans = ans + map[key];
    // }

    unordered_map<int, int> map;
    // j > i の範囲のみを調べる
    rep3(j, 1, n + 1)
    {
        int key_j = j - a[j - 1];
        ans = ans + map[key_j];

        int key_i = j + a[j - 1];
        // 何回 i + a[i - 1]が出てくるか数える
        map[key_i]++;
    }

    mPrint(ans);

    return 0;
}
