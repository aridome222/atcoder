#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, a, n) for (int i = (a); i < (n); i++)

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
            rrep(j, i, n - 1)
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
