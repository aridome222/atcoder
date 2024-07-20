#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    int n, m;
    string s;

    cin >> n >> m;

    vector<int> result(n, 0);
    rep(i, n)
    {
        cin >> s;
        for (char c : s)
        {
            result[i] = (result[i] << 1) | (c == 'o' ? 1 : 0);
        }
    }

    int sum = 0, ans = 0;
    int expected = (1 << m) - 1;
    rep(i, n)
    {
        if (sum == expected)
            break;
        sum |= result[i];
        ans++;
    }

    cout << ans << endl;

    return 0;
}
