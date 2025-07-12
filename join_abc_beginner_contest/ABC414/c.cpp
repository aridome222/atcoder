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

bool is_same_reverse(ll n)
{
    string s = to_string(n);
    string t = s;
    reverse(all(t));
    return s == t;
}

ll is_same_reverse_value_list(ll n)
{
    string s = to_string(n);
    string t = s;
    reverse(all(t));
    if (s == t)
    {
        return n;
    }
    else
    {
        return 1;
    }
}

bool is_same_reverse_base_a(ll n, int a)
{
    string str;

    while (n > 0)
    {
        str += to_string(n % a);
        n /= a;
    }
    string reverse_str = str;
    reverse(all(reverse_str));
    return str == reverse_str;
}

vector<ll> make_palindromes(ll n)
{
    vector<ll> res;
    // 奇数桁
    for (ll half = 1;; ++half)
    {
        string s = to_string(half);
        string t = s;
        reverse(t.begin(), t.end());
        string pal = s + t.substr(1); // 例: 123 + 21 = 12321
        ll val = stoll(pal);
        if (val > n)
            break;
        res.push_back(val);
    }
    // 偶数桁
    for (ll half = 1;; ++half)
    {
        string s = to_string(half);
        string t = s;
        reverse(t.begin(), t.end());
        string pal = s + t; // 例: 123 + 321 = 123321
        ll val = stoll(pal);
        if (val > n)
            break;
        res.push_back(val);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a;
    cin >> a;
    ll n;
    cin >> n;

    ll sum = 0;
    set<ll> setList;
    rep3(i, 1, n + 1)
    {
        setList.emplace(is_same_reverse_value_list(i));
    }

    for (auto value : setList)
    {
        // dump(value);
        if (is_same_reverse_base_a(value, a))
        {
            sum += value;
        }
    }

    mPrint(sum);

    return 0;
}
