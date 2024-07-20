#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define repR(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rep3R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define all(x) std::begin(x), std::end(x)
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> h;
    rep(i, n)
    {
        cin >> h[i];
    }

    vector<int> dp(n, 0);
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);

    rep3(i, 2, n)
    {
        dp[i] = min(dp[i - 1] + abs(dp[i] - dp[i - 1]), dp[i - 2] + abs(dp[i] - dp[i - 2]));
    }

    cout << dp[n - 1] << endl;

    return 0;
}
