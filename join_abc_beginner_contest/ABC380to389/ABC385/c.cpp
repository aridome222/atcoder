#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define repR(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rep3R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define all(x) std::begin(x), std::end(x)
#define rAll(x) std::rbegin(x), std::rend(x)
#define contain(str, ch) (str.find(ch) != string::npos)
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
// 二分探索
/*
vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};
bool isOK(int index, int key) {
    if (a[index] >= key) return true;
    else return false;
}
int binary_search(int key) {
    long long left = -1;
    long long right = (int)a.size();

    while (right - left > 1) {
        long long mid = left + (right - left) / 2;

        if (isOK(mid, key)) right = mid;
        else left = mid;
    }

    return right;
}
*/

int main()
{
    int n;
    cin >> n;

    vector<int> h(n);
    rep(i, n)
    {
        cin >> h[i];
    }

    int ans = 1;
    rep(i1, n)
    {
        rep3(j1, i1+1, n)
        {
            if(h[i1] == h[j1])
            {
                int tmp = 1;
                int cnt = j1 - i1;
                for (int i = j1; i < n; i += cnt)
                {
                    if(h[j1] == h[i])
                    {
                        tmp++;
                    }else{
                        break;
                    }
                }
                ans = max(tmp, ans);
            }
        }
    }

    mPrint(ans);

    return 0;
}
