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

struct Floor {
    int x;
    int y;
};

int manhattan_distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
    int H, W, D;
    cin >> H >> W >> D;

    vector<string> grid(H);
    vector<Floor> floors;

    for (int i = 0; i < H; i++) {
        cin >> grid[i];
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '.') {
                floors.push_back({i, j});
            }
        }
    }

    int max_humid = 0;
    int floor_count = floors.size();
    vector<set<pair<int, int>>> humid_ranges(floor_count);
    for (int i = 0; i < floor_count; i++) {
        int x1 = floors[i].x, y1 = floors[i].y;
        for (int x = 0; x < H; x++) {
            for (int y = 0; y < W; y++) {
                if (grid[x][y] == '.' && manhattan_distance(x1, y1, x, y) <= D) {
                    humid_ranges[i].insert({x, y});
                }
            }
        }
    }

    for (int i = 0; i < floor_count; i++) {
        for (int j = i + 1; j < floor_count; j++) {
            set<pair<int, int>> humid_set = humid_ranges[i];
            humid_set.insert(humid_ranges[j].begin(), humid_ranges[j].end());
            max_humid = max(max_humid, (int)humid_set.size());
        }
    }

    cout << max_humid << endl;
    
    return 0;
}
