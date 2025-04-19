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

ll cube(ll x)
{
    return x * x * x;
}
bool isOK(ll x, ll y, ll N)
{
    return cube(x) - cube(y) == N;
}

int binary_search(ll x, ll N)
{
    ll left = 1;
    ll right = x - 1;

    while (left <= right)
    {
        ll mid = left + (right - left) / 2;

        if (isOK(x, mid, N))
            return mid;
        else if (cube(x) > N + cube(mid))
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main()
{
    ll N;
    cin >> N;
    const ll MAX = 1e6;

    // x^3 = N + y^3となる、xとyの組を二分探索で見つける。
    // y = 0の時、x^3 = Nで、Nは最大でも10^18かつx>0, y>0のため、1 <= x <= 10^6の範囲でxを固定して、
    // yの値を二分探索で求めていけば、時間内に終わりそう。
    for (ll x = 1; x <= MAX; ++x)
    {
        ll y = binary_search(x, N);
        if (y != -1)
        {
            cout << x << " " << y << endl;
            return 0;
        }
    }

    // 解が見つからなかった場合
    cout << -1 << endl;

    return 0;
}
