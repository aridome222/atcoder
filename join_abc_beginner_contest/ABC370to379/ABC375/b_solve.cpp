#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using pi = pair<int, int>;

// 座標間の距離を計算
long double dist(pi l, pi r)
{
    return hypotl((long double)(l.first - r.first), (long double)(l.second - r.second));
}

int main()
{
    int n;
    cin >> n;
    vector<pi> xy(n);
    rep(i, n)
    {
        cin >> xy[i].first >> xy[i].second;
    }

    pi cur = make_pair(0, 0);
    long double v = dist(cur, xy[0]);

    rep(i, n - 1)
    {
        v += dist(xy[i], xy[i + 1]);
    }
    v += dist(xy[n - 1], cur);

    cout << fixed << setprecision(12) << v << "\n";

    return 0;
}
