#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define repR(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rep3R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define all(x) std::begin(x), std::end(x)
using namespace std;

using ll = long long;

// #define INF 100010
// -----------
// 無限大の値
const long long INF = 1LL << 60;
// -----------

vector<ll> dp(100010, INF);

int main()
{
    int n;
    cin >> n;

    vector<int> h(n);
    rep(i, n)
    {
        cin >> h[i];
    }

    // -----------
    // dp配列をdpの種類に応じて初期化
    // vector<int> dp(INF);
    // ll dp[10010];

    // // DP テーブル全体を初期化 (最小化問題なので INF に初期化)
    // for (int i = 0; i < 100010; ++i)
    // {
    //     dp[i] = INF;
    // }
    // -----------

    // 初期条件を入力
    dp[0] = 0;
    // dp[1] = abs(h[0] - h[1]);

    // ループを回す
    rep3(i, 1, n)
    {
        dp[i] = min(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
        if (i > 1)
        {
            dp[i] = min(dp[i], dp[i - 2] + abs(h[i - 2] - h[i]));
        }
    }
    // rep(i, n)
    // {
    //     dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
    //     dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
    // }

    // 結果を出力
    cout
        << dp[n - 1] << endl;

    return 0;
}
