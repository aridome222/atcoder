#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define repR(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rep3R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define all(x) std::begin(x), std::end(x)
using namespace std;

int main()
{
    int k = 0;
    int n = 0;
    int x = 0;
    cin >> n >> k >> x;
    vector<int> a(n + 1);
    rep(i, n + 1)
    {
        if (i == k)
        {
            a[i] = x;
            continue;
        }
        cin >> a[i];
    }

    rep(i, n + 1)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
