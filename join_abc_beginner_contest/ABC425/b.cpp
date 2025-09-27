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

    int n;
    cin >> n;

    vector<int> p(n);
    unordered_map<int, bool> mp;
    rep(i, n)
    {
        int a;
        cin >> a;
        mp[a] = true;
        p[i] = a;
    }

    // -1であれば、1から順に入れていく
    // そうでなければ、次の要素を見る
    int cnt = 1;
    rep(i, n)
    {
        if (p[i] == -1)
        {
            while (mp[cnt] == true)
            {
                cnt++;
            }
            p[i] = cnt;
            cnt++;
        }
    }

    // すべての要素が-1でないかチェック & 重複チェック
    bool isOK = true;
    unordered_set<int> used; // 使用済み要素をチェック

    rep(i, n)
    {
        // -1でないかチェック
        if (p[i] == -1)
        {
            isOK = false;
            break;
        }

        // 重複チェック
        if (used.count(p[i]))
        {
            isOK = false;
            break;
        }
        used.insert(p[i]);
    }

    if (isOK)
    {
        mPrint("Yes");
        arrPrint(p);
    }
    else
    {
        mPrint("No");
    }
    return 0;
}
