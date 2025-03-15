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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }

    set<int> b, c;
    int ans = 0;
    rep(i, n - 1)
    {
        b = set<int>(a.begin(), a.begin() + i + 1);
        c = set<int>(a.begin() + i + 1, a.end());

        // dump(b.size());
        // dump(c.size());
        int tmp = b.size() + c.size();
        // dump(tmp);
        // dump(ans);
        ans = max(ans, tmp);
    }

    mPrint(ans);

    return 0;
}

// 　解答
//  int main()
//  {
//      int n;
//      cin >> n;
//      vector<int> a(n);
//      for (auto &e : a)
//          cin >> e;
//      vector<int> suml(n), sumr(n);
//      vector<int> vis(n + 1, 0);
//      int now = 0;
//      for (int i = 0; i < n; ++i)
//      {
//          if (!vis[a[i]])
//          {
//              now++;
//          }
//          vis[a[i]] = 1;
//          suml[i] = now;
//      }
//      now = 0;
//      vis = vector<int>(n + 1, 0);
//      for (int i = n - 1; i >= 0; --i)
//      {
//          if (!vis[a[i]])
//          {
//              now++;
//          }
//          vis[a[i]] = 1;
//          sumr[i] = now;
//      }
//      int ans = 0;
//      for (int i = 0; i < n - 1; ++i)
//      {
//          ans = max(ans, suml[i] + sumr[i + 1]);
//      }
//      cout << ans << endl;
//  }
