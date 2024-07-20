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

    rep(i, k)
    {
        if (abs(a[i + 1] - a[n - (i + 1)]) > abs(a[i] - a[n - (i + 1)]))
        {
        }
    }

    int ans;
    ans = a[n - 2] - a[2]

          return 0;
}
