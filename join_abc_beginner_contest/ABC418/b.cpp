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

vector<string> getAllSubstrings(const string &s)
{
    vector<string> substrings;
    int n = s.length();
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 't')
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (s[j] == 't')
                {
                    int len = j - i + 1;
                    if (len >= 3)
                    {
                        substrings.push_back(s.substr(i, len));
                    }
                }
            }
        }
    }
    // arrPrint(substrings);
    return substrings;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(17);

    string s;
    cin >> s;
    // int n = s.size();
    long double ans = 0.0;
    // long double tmp = 0.0;
    // int t_cnt = 0, s_cnt = 0;
    vector<string> substrings = getAllSubstrings(s);
    int n_sub = substrings.size();
    if (n_sub == 0)
    {
        mPrint(ans);
        return 0;
    }
    rep(i, n_sub)
    {
        int cnt = 0;
        int size = substrings[i].size();
        // if (size < 2)
        // {
        //     continue;
        // }
        rep(j, size)
        {
            if (substrings[i][j] == 't')
            {
                cnt++;
                // dump(j);
                // dump(cnt);
                // dump(size);
            }
        }
        long double tmp = (long double)(cnt - 2) / (long double)(size - 2);
        // dump(tmp);
        ans = max(ans, tmp);
    }
    mPrint(ans);
    // rep(i, n)
    // {
    //     s_cnt++;
    //     rep3(j, i + 1, n)
    //     {
    //         if (t_cnt == 1 || s_cnt < 2)
    //         {
    //             continue;
    //         }
    //         tmp = (long double)(t_cnt - 2) / (long double)(s_cnt - 2);
    //         ans = max(ans, tmp);
    //     }
    // }
    // rep(i, n)
    // {
    //     s_cnt++;
    //     if (s[i] == 't')
    //     {
    //         t_cnt++;
    //         if (t_cnt == 1 || s_cnt < 2)
    //         {
    //             continue;
    //         }
    //         tmp = (long double)(t_cnt - 2) / (long double)(s_cnt - 2);
    //         ans = max(ans, tmp);
    //     }
    // }

    // mPrint(ans);
    // if (s[0] != 't' && s[n-1] != 't' && )
    // bool f_flag, s_flag;
    // int t_cnt = 0;
    // rep(i, n)
    // {
    //     if (s[i] == 't' && f_flag == false)
    //     {
    //         f_flag = true;
    //         t_cnt++;
    //     }
    //     if (s[i] == 't' && f_flag == true && s_flag == false)
    //     {
    //         f_flag = true;
    //         t_cnt++;
    //     }
    // }

    // if (n < 3)
    // {
    //     mPrint(ans);
    //     return 0;
    // }
    // int t_cnt = 0;
    // rep(i, n)
    // {
    //     if (s[i] == 't')
    //     {
    //         t_cnt++;
    //     }
    //     if (t_cnt == 3)
    //     {
    //         ans = 1.0;
    //         mPrint(ans);
    //         return 0;
    //     }
    // }

    // int a = 200, b = 200;
    // rep(i, n)
    // {
    //     if (s[i] == 't')
    //     {
    //         a = i;
    //         break;
    //     }
    // }
    // repR(i, n)
    // {
    //     if (s[i] == 't')
    //     {
    //         b = i;
    //         break;
    //     }
    // }

    // if (a == 200 || b == 200)
    // {
    //     mPrint(ans);
    //     return 0;
    // }

    // dump(a);
    // dump(b);

    // int cnt = 0;
    // if (b - a + 1 < 3)
    // {
    //     mPrint(ans);
    //     return 0;
    // }
    // rep3(i, a, b + 1)
    // {
    //     if (s[i] == 't')
    //     {
    //         cnt++;
    //         // dump(i);
    //         // dump(cnt);
    //     }
    // }

    // ans = (long double)(cnt - 2) / (long double)((b - a + 1) - 2);

    // mPrint(ans);
    return 0;
}
