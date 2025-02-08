#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define repR(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rep3R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define all(x) std::begin(x), std::end(x)
#define rAll(x) std::rbegin(x), std::rend(x)
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
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

typedef struct edge
{
    int x1;
    int y1;
    int x2;
    int y2;
} edge;

int main()
{
    int n; // 線分の数
    cin >> n;
    double s, t; // sは照射してない時の移動速度、tは照射時の移動速度
    cin >> s >> t;
    edge p[n];
    rep(i, n)
    {
        cin >> p[i].x1;
        cin >> p[i].y1;
        cin >> p[i].x2;
        cin >> p[i].y2;
    }

    double ans = 0.0;
    double min_len = 10000;
    int min_index = 0;

    // (0, 0)から一番近い点までの距離をsで割る
    rep(i, n)
    {
        double tmp_len = min((double)sqrt(
                                 (p[i].x1) * (p[i].x1) + (p[i].y1) * (p[i].y1)),
                             (double)sqrt(
                                 (p[i].x2) * (p[i].x2) + (p[i].y2) * (p[i].y2)));
        dPrint(tmp_len);
        if (chmin(min_len, tmp_len))
        {
            min_index = i;
        }
    }

    double s_time = min_len / s;
    double t_time = (double)sqrt(
                        (p[min_index].x1 - p[min_index].x2) * (p[min_index].x1 - p[min_index].x2) + (p[min_index].y1 - p[min_index].y2) * (p[min_index].y1 - p[min_index].y2)) /
                    t;

    ans = s_time + t_time;

    rep(i, n)
    {
        double tmp_len = min((double)sqrt(
                                 (p[i].x1) * (p[i].x1) + (p[i].y1) * (p[i].y1)),
                             (double)sqrt(
                                 (p[i].x2) * (p[i].x2) + (p[i].y2) * (p[i].y2)));
        dPrint(tmp_len);
        if (chmin(min_len, tmp_len))
        {
            min_index = i;
        }
    }

    mPrint(ans);

    return 0;
}
