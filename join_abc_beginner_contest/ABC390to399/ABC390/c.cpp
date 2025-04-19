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
    int h, w;
    cin >> h >> w;

    vector<vector<char>> s(h, vector<char>(w, 'a'));
    rep(i, h)
    {
        rep(j, w)
        {
            char ch;
            cin >> ch;
            s[i][j] = ch;
        }
    }

    pair<int, int> first_hw;
    pair<int, int> end_hw;

    rep(j, w)
    {
        rep(i, h)
        {
            if (s[i][j] == '#')
            {
                first_hw.first = j;
                first_hw.second = i;
                break;
            }
        }
    }

    repR(j, w)
    {
        repR(i, h)
        {
            if (s[i][j] == '#')
            {
                end_hw.first = j;
                end_hw.second = i;
                break;
            }
        }
    }

    for (int i = first_hw.first; i < end_hw.first; i++)
    {
        for (int j = first_hw.second; i < end_hw.second; i++)
        {
            if (s[i][j] == '.')
            {
                mPrint("No");

                return 0;
            }
        }
    }

    mPrint("Yes");
    return 0;
}

// 解答
// #include <bits/stdc++.h>
// using namespace std;

// int main(void)
// {
//     int h, w;
//     string s[1000];
//     int hmin = 1000, hmax = -1, wmin = 1000, wmax = -1;
//     bool flag = true;

//     cin >> h >> w;

//     for (int i = 0; i < h; i++)
//     {
//         cin >> s[i];
//         for (int j = 0; j < w; j++)
//         {
//             if (s[i][j] == '#')
//             {
//                 hmin = min(hmin, i);
//                 hmax = max(hmax, i);
//                 wmin = min(wmin, j);
//                 wmax = max(wmax, j);
//             }
//         }
//     }

//     for (int i = hmin; i <= hmax; i++)
//     {
//         for (int j = wmin; j <= wmax; j++)
//         {
//             if (s[i][j] == '.')
//                 flag = false;
//         }
//     }

//     if (flag)
//         cout << "Yes" << endl;
//     else
//         cout << "No" << endl;
//     return 0;
// }
