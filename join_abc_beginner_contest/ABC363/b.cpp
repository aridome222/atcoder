#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, t, ans = 0;
    cin >> n >> a;

    for (int i = 1; i <= n; i++)
    {
        cin >> t;

        if (t - ans > 0)
        {
            ans += a + (t - ans);
        }
        else
        {
            ans += a;
        }

        cout << ans << "\n";
    }

    return 0;
}
