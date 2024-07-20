#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = (n) - 1; (n) >= 0; i--)

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
            rep2(j, s.size())
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
