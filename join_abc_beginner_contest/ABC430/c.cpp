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

    int n, A_min, B_limit;
    cin >> n >> A_min >> B_limit;
    string s;
    cin >> s;

    vector<int> A(n + 1), B(n + 1);
    rep(i, n)
    {
        A[i + 1] = A[i] + (s[i] == 'a');
        B[i + 1] = B[i] + (s[i] == 'b');
    }

    long long ans = 0;
    for (int l = 1; l <= n; l++)
    {
        // --- a_l: A個以上になる最小のrを探す ---
        int low = l, high = n + 1;
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (A[mid] - A[l - 1] >= A_min)
                high = mid;
            else
                low = mid + 1;
        }
        int a_l = (high <= n ? high : n + 1); // 存在しない場合に備え

        // --- b_l: B個未満になる最大のrを探す ---
        low = l - 1, high = n;
        while (low < high)
        {
            int mid = (low + high + 1) / 2;
            if (B[mid] - B[l - 1] < B_limit)
                low = mid;
            else
                high = mid - 1;
        }
        int b_l = low;

        if (a_l <= b_l)
            ans += (b_l - a_l + 1);
    }

    cout << ans << endl;
}
