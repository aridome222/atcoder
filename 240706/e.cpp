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
    vector<int> a(n, 0);
    rep(i, n)
    {
        cin >> a[i];
    }

    vector<int> s;

    vector<int> ans;
    int result = 0;
    rep(i, n)
    {
        result += a[i];
        if (!s.empty())
        {
            repR(j, s.size())
            {
                if (s[j] < a[i])
                {
                    result += a[i] - s[i];
                }
            }
        }
        s.push_back(a[i]);
    }
}
