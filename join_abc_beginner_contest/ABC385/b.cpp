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
bool isValid(int h, int w, int moved_x, int moved_y)
{
    return 0 <= moved_x && moved_x < h && 0 <= moved_y && moved_y < w;
}

int main()
{
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    x--;
    y--;

    vector<string> s(h);
    rep(i, h)
    {
        cin >> s[i];
    }

    string t;
    cin >> t;

    int ans = 0;
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    rep(i, t.size())
    {
        int moved_x = x;
        int moved_y = y;

        if (t[i] == 'U')
        {
            moved_x = x - 1;
        }
        else if (t[i] == 'D')
        {
            moved_x = x + 1;
        }
        else if (t[i] == 'L')
        {
            moved_y = y - 1;
        }
        else if (t[i] == 'R')
        {
            moved_y = y + 1;
        }

        // auto isValid = [&](int moved_x, int moved_y) -> bool {
        //     return 0 <= moved_x && moved_x < h && 0 <= moved_y && moved_y < w;
        // };
        if (isValid(h, w, moved_x, moved_y) && s[moved_x][moved_y] != '#')
        {
            x = moved_x;
            y = moved_y;
            
            if (s[x][y] == '@' && !visited[x][y])
            {
                ans++;
                visited[x][y] = true;
            }
        }
    }

    cout << x + 1 << " " << y + 1 << " " << ans << endl;

    return 0;
}