#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define repR(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rep3R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define all(x) std::begin(x), std::end(x)
#define rAll(x) std::rbegin(x), std::rend(x)
#define mPrint(msg) cout << msg << endl;
#define dPrint(msg) cout << "-----\n" \
                         << msg << "\n-----\n";
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

int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < 1; i++)
    {
        if ((s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') || (s[i] == 'A' && s[i + 1] == 'C' && s[i + 2] == 'B') || (s[i] == 'B' && s[i + 1] == 'C' && s[i + 2] == 'A') || (s[i] == 'B' && s[i + 1] == 'A' && s[i + 2] == 'C') || (s[i] == 'C' && s[i + 1] == 'B' && s[i + 2] == 'A') || (s[i] == 'C' && s[i + 1] == 'A' && s[i + 2] == 'B'))
        {
            mPrint("Yes");
        }
        else
        {
            mPrint("No");
        }
    }

    return 0;
}
