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

    // nは子供の数、xは小さな飴の重さ、yは大きな飴の重さ
    // 2 <= n <= 2*10^5
    // 1 <= x < y <= 10^9
    ll n, x, y;
    cin >> n >> x >> y;

    vector<ll> v(n);
    // 子供iに配る、2種類の飴を合計した飴の数
    // n人の子供それぞれに配る飴の数の総重量は全て等しい
    ll a;
    rep(i, n)
    {
        cin >> a;
        v.push_back(a);
    }

    // 上記の条件を満たす配り方が存在するか判定
    // 存在する場合はそのような配り方における、
    // 大きな飴を配る個数としてあり得る最大値を求める
    // 存在しない場合は、-1を出力

    // 方針
    // 一番配る飴の個数が少ない子供に、大きな飴だけ配る
    sort(all(v));
    min_items = v[0];
    // そして、大きな飴の重さ×配った数 = 総重量 の時、
    // その総重量になるよう、他全員が大きな飴の個数をできるだけ多くなるよう配る
    // もし配れれば、全員の大きな飴の個数の合計が答え。
    // もしそのような配り方ができなければ、一番配る飴の個数が少ない子供に配る大きな飴の個数を二分探索で決める
    // そして、配ることができるようになるまで二分探索で繰り返す
    // 配れれば全員の大きな飴の個数の合計が答え？
    binary_search();

    return 0;
}
