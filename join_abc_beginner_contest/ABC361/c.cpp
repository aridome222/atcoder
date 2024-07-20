#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define repR(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rep3R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define all(x) std::begin(x), std::end(x)

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> lr(n);
    rep(i, n)
    {
        cin >> lr.first >> lr.second;
    }

    // sort(all(lr));

    long l_sum = 0;
    rep(i, n)
    {
        l_sum += lr[i].first;
    }
    long r_sum = 0;
    rep(i, n)
    {
        r_sum += lr[i].first;
    }

    if (l_sum == 0 || r_sum == 0)
    {
        cout << "Yes" << endl;
        return 0;
    }
    else if (l_sum > 0 || r_sum < 0)
    {
        cout << "No" << endl;
        return 0;
    }
    else
    {
        // 各最小値の和が0になるようにする
        int sum = lr[0].first;
        rep3(i, 1, n)
        {
            if (sum + lr[i].second < 0)
            {
                sum += lr[i].second;
            }
            else
            {
                rep(j, lr[i].second)
                {
                    sum--;
                    if (sum == 0)
                    {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
}
