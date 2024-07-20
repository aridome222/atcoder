#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define repR(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rep3R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define all(x) std::begin(x), std::end(x)
#define mprint(msg) cout << msg << endl;
#define repE(arr)                    \
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

int main()
{
    int n, t, p;
    cin >> n >> t >> p;
    vector<int> l(n);
    rep(i, n)
    {
        cin >> l[i];
    }

    sort(all(l));

    int cnt = 0;
    int index = 0;
    rep(i, n)
    {
        if (l[i] >= t)
        {
            if (cnt == 0)
            {
                index = i;
            }
            cnt++;
        }
        if (cnt == p)
        {
            mprint("0");
            return 0;
        }
    }

    int left = p - cnt;
    int ans = 0;
    ans = t - l[n - cnt - left];
    mprint(ans);

    return 0;
}
