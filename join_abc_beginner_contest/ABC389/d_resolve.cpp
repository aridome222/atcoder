#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll R;
    cin >> R;

    // (1) 軸上の正方形の個数
    ll res = 4 * (R - 1) + 1;

    // (2) 第1象限の正方形の個数を数える
    ll count = 0;
    ll j = R - 1;
    for (ll i = 1; i < R; i++)
    {
        while (j >= 1 && (2 * i + 1) * (2 * i + 1) + (2 * j + 1) * (2 * j + 1) > 4 * R * R)
        {
            j--;
        }
        count += j;
    }
    res += 4 * count;

    // (3) 結果の出力
    cout << res << endl;
    return 0;
}
