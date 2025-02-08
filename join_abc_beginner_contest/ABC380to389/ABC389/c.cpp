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
    size_t left = 0; // 0からスタート
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
    int q;
    cin >> q;

    vector<pair<int, ll>> c;
    pair<int, ll> x(1, 0); // 1番目の座標は0
    map<int, ll> m;
    c.push_back(x);
    int cnt = 2;
    int index = 0;
    ll r = 0;
    rep(i, q)
    {
        int a;
        cin >> a;
        if (a == 2)
        {
            index++;
            r += m[index];
        }
        else
        {
            if (a == 1)
            {
                ll length;
                cin >> length;
                pair<int, ll> b(0, 0);
                b.first = cnt;
                m[cnt - 1] = length;
                cnt++;
                b.second += length + c.back().second;
                c.push_back(b);
            }
            else
            {
                int k;
                cin >> k;
                k--;
                ll ans = c[k + index].second - r;
                mPrint(ans);
            }
        }
    }

    return 0;
}

// 賢いやり方
// ll now = 0;
// vector<ll> x;
// int id = 0;
// rep(i, q)
// {
//     int t;
//     cin >> t;

//     if (t == 1)
//     {
//         ll l;
//         cin >> l;
//         x.push_back(now);
//         now += l;
//     }
//     else if (t == 2)
//     {
//         id++;
//     }
//     else
//     {
//         int k;
//         cin >> k;
//         k--;
//         cout << x[id + k] - x[id] << endl;
//     }
// }
