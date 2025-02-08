#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define repR(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rep3R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define all(x) std::begin(x), std::end(x)
#define mPrint(msg) cout << msg << endl;
#define dPrint(msg) cout << "-----\n" \
                         << msg << "\n-----\n";
#define arrPrint(arr)                \
    {                                \
        bool first = true;           \
        for (const auto &elem : arr) \
        {                            \
            if (!first)              \
                cout << " ";         \
            cout << elem;            \
            first = false;           \
        }                            \
        cout << endl;                \
    }

int main()
{
    int n;
    cin >> n;
    vector<pair<int, char>> as(n);
    rep(i, n)
    {
        cin >> as[i].first >> as[i].second;
    }

    vector<int> left, right;
    int left_cnt = 0, right_cnt = 0;
    rep(i, n)
    {
        if (as[i].second == 'L')
        {
            left.push_back(as[i].first);
            left_cnt++;
        }
        else
        {
            right.push_back(as[i].first);
            right_cnt++;
        }
    }

    int left_sum = 0;
    int right_sum = 0;
    rep(i, left_cnt - 1)
    {
        left_sum += abs(left[i] - left[i + 1]);
    }

    rep(i, right_cnt - 1)
    {
        right_sum += abs(right[i] - right[i + 1]);
    }

    int sum = left_sum + right_sum;

    mPrint(sum);

    return 0;
}
