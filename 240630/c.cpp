#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0), w(n, 0);
    vector<pair<int, int>> aw(n, {0, 0});

    rep(i, n)
    {
        cin >> aw[i].first;
    }
    rep(i, n)
    {
        cin >> aw[i].second;
    }

    sort(aw.begin(), aw.end());

    int sum = 0;

    // キー値が重複するものの中で、一番大きい値以外の値を全て足し合わせる
    rep(i, n - 1)
    {
        if (aw[i].first == aw[i + 1].first)
        {
            sum += aw[i].second;
        }
    }

    cout << sum << endl;

    return 0;
}
