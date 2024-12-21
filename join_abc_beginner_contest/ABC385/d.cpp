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

P = pair<int, int>
C = pair<char, int>

int main()
{
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    sx--;
    sy--;

    P xy(n);
    rep(i, n)
    {
        cin >> xy[i].first >> xy[i].second;
    }

    C dc(m);
    rep(i, m)
    {
        cin >> dc[i].first >> dc[i].second;
    }

    int ans = 0;
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    rep(i, m)
    {
        int moved_x = sx;
        int moved_y = sy;

        if (dc[i].first == 'U')
        {
            moved_x = moved_x - dc[i].second;
        }
        else if (dc[i].first == 'D')
        {
            moved_x = moved_x + dc[i].second;
        }
        else if (dc[i].first == 'L')
        {
            moved_y = moved_y - dc[i].second;
        }
        else if (dc[i].first == 'R')
        {
            moved_y = moved_y + dc[i].second;
        }

        auto isValid = [&](int moved_x, int moved_y) -> bool {
            return -1000000000 <= moved_x && moved_x <= 1000000000 && -1000000000 <= moved_y && moved_y <= 1000000000;
        };
        if (isValid(moved_x, moved_y))
        {
            sx = moved_x;
            sy = moved_y;
            
            if (s[x][y] ==  && !visited[x][y])
            {
                ans++;
                visited[x][y] = true;
            }
        }
    }

    cout << x + 1 << " " << y + 1 << " " << ans << endl;

    return 0;
}
