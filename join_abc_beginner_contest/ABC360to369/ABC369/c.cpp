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
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }

    int cnt = 0;

    rep3(i, 3, n + 1)
    {
        rep(j, n)
        {
            bool flag = false;
            vector<int> subArr(a.begin() + j, a.begin() + j + i);
            int diff = abs(subArr[0] - subArr[1]);
            rep3(k, 1, subArr.size() - 1)
            {
                if (diff != abs(subArr[k] - subArr[k + 1]))
                {
                    flag = true;
                    break;
                }
            }
            if (flag == false)
            {
                cnt++;
            }
        }
    }

    int sum = n + (n - 1) + cnt;

    mPrint(sum);

    return 0;
}
