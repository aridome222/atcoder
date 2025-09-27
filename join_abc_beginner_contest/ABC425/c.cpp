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

    // cout << fixed << setprecision(17);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }

    // 累積和を計算（2倍の長さにして循環に対応）
    vector<ll> cumsum(2 * n + 1, 0);
    rep(i, 2 * n)
    {
        cumsum[i + 1] = cumsum[i] + a[i % n];
    }

    int offset = 0; // 仮想的な先頭位置を記録

    while (q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int c;
            cin >> c;
            offset = (offset + c) % n;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int start = offset + l;
            int end = offset + r;
            ll sum = cumsum[end + 1] - cumsum[start];
            mPrint(sum);
        }
        q--;
    }

    return 0;
}
