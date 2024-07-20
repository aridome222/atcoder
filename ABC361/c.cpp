#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define repR(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rep3R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define all(x) std::begin(x), std::end(x)
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n, 0);

    rep(i, n)
    {
        cin >> a[i];
    }

    sort(all(a));

    int ans = 1e9;
    rep(l, k + 1)
    {
        int r = l + (n - k) - 1;
        int now = a[r] - a[l];
        ans = min(ans, now);
    }

    cout << ans << endl;

    return 0;
}
