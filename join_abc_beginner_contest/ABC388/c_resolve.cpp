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
// 配列はソートされていることが使用条件
bool isOK(vector<ll> &a, ll index, ll key)
{
    if (a[index] >= key)
        return true;
    else
        return false;
}
int binary_search(ll key, vector<ll> &a)
{
    ll left = -1;
    ll right = a.size();

    while (right - left > 1)
    {
        ll mid = left + (right - left) / 2;

        if (isOK(mid, key, a))
            right = mid;
        else
            left = mid;
    }

    return right;
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> a(N);
    rep(i, N)
    {
        cin >> a[i];
    }

    ll ans = 0;
    rep(i, N)
    {
        ll right = binary_search(a[i] * 2, a);
        ans += N - right;
    }

    mPrint(ans);
    return 0;
}
