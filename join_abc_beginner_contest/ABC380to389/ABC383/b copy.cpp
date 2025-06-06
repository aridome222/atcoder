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
// 二分探索
/*
vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};
bool isOK(int index, int key) {
    if (a[index] >= key) return true;
    else return false;
}
int binary_search(int key) {
    long long left = -1;
    long long right = (int)a.size();

    while (right - left > 1) {
        long long mid = left + (right - left) / 2;

        if (isOK(mid, key)) right = mid;
        else left = mid;
    }

    return right;
}
*/

int main()
{
    int h, w, d;
    cin >> h >> w >> d;

    vector<vector<char>> map(h, vector<char>(w));
    rep(i, h)
    {
        rep(j, w)
        {
            char ch;
            cin >> ch;
            map[i][j] = ch;
        }
    }

    int min_cnt = 0;
    rep(i, h)
    {
        rep(j, w)
        {
            if(map[i][j] == ".")
            {
                vector<vector<bool>> x_map(h, vector<bool>(w)) = map;
                int cnt = 0;
                rep3(k, i - d, i + d)
                {
                    rep3(l, j-d, j+d)
                    {
                        // マップ内であるか
                        if(0 <= i-d && j-d <=0 && i+d <= h-1 && j+d <= w-d)
                        {
                            // マンハッタン距離内であるか
                            if(abs(i-k) + abs(j-l) <= d)
                            {
                                cnt++;
                                x_map[k][l] = true;
                            }
                        }
                    }
                }
            }
        }
    }

    rep(i, h)
    {
        rep(j, w)
        {
            if(map[i][j] == ".")
            {
                int cnt = 0;
                rep3(k, i - d, i + d)
                {
                    rep3(l, j-d, j+d)
                    {
                        if(0 <= i-d && j-d <=0 && i+d <= h-1 && j+d <= w-d)
                        {
                            if(abs(i-k) + abs(j-l) <= d)
                            {
                                cnt++;
                            }
                        }
                    }
                }
            }
            
        }
    }



    // rep(i, h)
    // {
    //     rep(j, w)
    //     {
    //         cout << map[i][j];
    //         if (j < w - 1)
    //     }
    //     cout << endl;
    // }
    

    return 0;
}
