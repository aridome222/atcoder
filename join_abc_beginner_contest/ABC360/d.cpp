#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define repR(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rep3R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define all(x) std::begin(x), std::end(x)
using namespace std;

int main()
{
    int n, t, cnt = 0;
    cin >> n >> t;
    string s;
    cin >> s;

    vector<pair<char, int>> sx(n);
    rep(i, n)
    {
        sx[i].first = s[i];
        cin >> sx[i].second;
    }

    int ans = 0;
    rep(i, n)
    {
        // '1'が見つかった場合、それと'1'以降にある'0'との距離の絶対値 ÷ 2 が t 以内であれば、ansを1増やす
        if (sx[i].first == '1')
        {
            rep3(j, i, n - 1)
            {
                // '0'が見つかった場合
                if (sx[j + 1].first == '0')
                {
                    // '1'と'0'との距離の絶対値 ÷ 2.0 が t 以内の場合
                    if (abs(sx[i].second - sx[j + 1].second) / 2.0 <= t)
                    {
                        ans++;
                        // cout << ans << endl;
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
