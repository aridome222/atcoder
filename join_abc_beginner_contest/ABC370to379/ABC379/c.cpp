#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define repR(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rep3R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define all(x) std::begin(x), std::end(x)
#define rAll(x) std::rbegin(x), std::rend(x)
#define contain(str, ch) (str.find(ch) != string::npos)
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

using li = long int;

int main()
{
    li n, m;
    cin >> n >> m;

    vector<li> x(m);
    vector<li> a(m);
    li sum = 0;
    rep(i, m)
    {
        cin >> x[i];
    }
    rep(i, m)
    {
        cin >> a[i];
    }

    li pos = 0;
    if(x[0] != 1){
        mPrint(-1);
        return 0;
    }
    li ans = 0;
    rep(i, m)
    {
        if(pos + 1 < x[i])
        {
            mPrint(-1);
            return 0;
        }
        if(pos + 1 == x[i]){
            // x_i番目にある値だけ、nマスのうち、a_i個埋める
            li cnt = a[i] * (a[i] - 1) / 2;
            ans += cnt;
            // 移動させた時の境界
            pos = x[i] + a[i] - 1;
            if(n < pos){
                
            }
        }else{
            // x_i番目にある値だけ、nマスのうち、a_i個埋める
            li cnt = ((x[i] - pos) * a[i]) + (a[i] * (a[i] - 1) / 2);
            ans += cnt;
            // 移動させた時の境界
            pos = x[i] + a[i] - 1;
        }
    }



    if(pos + 1 < x[i]){
            mPrint(-1);
            return 0;
        }else if (pos + 1 == x[i])
        {
            if(i != m-1)
            {
                // x_i番目にある値だけ、nマスのうち、a_i個埋める
                li move = a[i] * (a[i] - 1) / 2;
                // 移動させた時の境界
                pos = x[i] + a[i] - 1;
            }
        }else
        {
            // x_i番目にある値だけ、nマスのうち、a_i個埋める
            li move = a[i] * (a[i] - 1) / 2;
            // 移動させた時の境界
            pos = x[i] + a[i] - 1;
        }

    return 0;
}
